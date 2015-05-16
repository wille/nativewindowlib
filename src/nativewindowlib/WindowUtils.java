package nativewindowlib;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.ptr.IntByReference;
import com.sun.jna.win32.StdCallLibrary;

public final class WindowUtils {

	/**
	 * https://stackoverflow.com/questions/3188484/windows-how-to-get-a-list-of-all-visible-windows
	 * 
	 * https://stackoverflow.com/questions/7521693/converting-c-sharp-to-java-jna-getmodulefilename-from-hwnd
	 */
	public static List<NativeWindow> getWindows() {
		final List<NativeWindow> inflList = new ArrayList<NativeWindow>();
		final List<Integer> order = new ArrayList<Integer>();

		int top = User32.INSTANCE.GetTopWindow(0);

		while (top != 0) {
			order.add(top);
			top = User32.INSTANCE.GetWindow(top, User32.GW_HWNDNEXT);
		}

		User32.INSTANCE.EnumWindows(new WndEnumProc() {
			public boolean callback(int hWnd, int lParam) {						
				inflList.add(new NativeWindow(hWnd));
				return true;
			}
		}, 0);

		Collections.sort(inflList, new Comparator<NativeWindow>() {
			public int compare(NativeWindow o1, NativeWindow o2) {
				return order.indexOf(o1.getHwnd()) - order.indexOf(o2.getHwnd());
			}
		});

		return inflList;
	}
	
	/**
	 * Finds all windows and checks which are visible
	 * @return all visible windows.
	 */
	public static List<NativeWindow> getVisibleWindows() {
		List<NativeWindow> visible = new ArrayList<NativeWindow>();
		List<NativeWindow> windows = WindowUtils.getWindows();

		for (NativeWindow w : windows) {
			if (w.isVisible()) {
				visible.add(w);
			}
		}
		
		return visible;
	}

	/**
	 * Finds all windows and searches for a matching title
	 * @param title the title to search for
	 * @return the window with the title that has been searched for, or null if not found.
	 */
	public static NativeWindow getByTitle(String title) {
		return new NativeWindow(User32.INSTANCE.FindWindowA(null, title));
	}
	
	/**
	 * Prevent instantiation
	 */
	private WindowUtils() {
	}

	public static interface WndEnumProc extends StdCallLibrary.StdCallCallback {

		public abstract boolean callback(int hWnd, int lParam);
	}

	public static interface User32 extends StdCallLibrary {

		public static final User32 INSTANCE = (User32) Native.loadLibrary("user32", User32.class);

		public static final int GW_HWNDNEXT = 2;

		/**
		 * Enumerate all native windows
		 * @param wndenumproc
		 * @param lParam
		 * @return
		 */
		public abstract boolean EnumWindows(WndEnumProc wndenumproc, int lParam);
		
		public abstract int FindWindowA(String lpClassName, String lpWindowName);

		/**
		 * Is window visible (only show windows that is)
		 * @param hWnd
		 * @return
		 */
		public abstract boolean IsWindowVisible(int hWnd);

		/**
		 * Gets window position
		 * @param hWnd
		 * @param r
		 * @return
		 */
		public abstract int GetWindowRect(int hWnd, NativeRectangle r);

		/**
		 * Moves window position
		 * @param hWnd
		 * @param X
		 * @param Y
		 * @param nWidth
		 * @param nHeight
		 * @param bRepaint
		 * @return
		 */
		public abstract boolean MoveWindow(int hWnd, int X, int Y, int nWidth, int nHeight, boolean bRepaint);

		/**
		 * Gets window title
		 * @param hWnd
		 * @param buffer
		 * @param buflen
		 */
		public abstract void GetWindowTextA(int hWnd, byte[] buffer, int buflen);
		
		/**
		 * Sets window title
		 * @param hWnd
		 * @param text
		 * @return
		 */
		public abstract boolean SetWindowTextA(int hWnd, String text);

		public abstract int GetWindowThreadProcessId(int hWnd);

		/**
		 * Gets window on top
		 * @param hWnd
		 * @return
		 */
		public abstract int GetTopWindow(int hWnd);

		public abstract int GetWindow(int hWnd, int flag);

		/**
		 * Set focus on window
		 * @param hWnd
		 * @return
		 */
		public abstract boolean SetForegroundWindow(int hWnd);

		public abstract int GetWindowThreadProcessId(int hWnd, IntByReference pid);
		
		/**
		 * Minimizes the window
		 * @param hWnd
		 * @return
		 */
		public abstract boolean CloseWindow(int hWnd);
		
		/**
		 * Closes the window
		 * @param hWnd
		 * @return
		 */
		public abstract boolean DestroyWindow(int hWnd);

		/**
		 * Changes state of the window
		 * @param hWnd
		 * @param nCmdShow
		 * @return
		 */
		public abstract boolean ShowWindow(int hWnd, int nCmdShow);
	}

	public static final int PROCESS_QUERY_INFORMATION = 0x0400;

	public interface Kernel32 extends StdCallLibrary {
		Kernel32 INSTANCE = (Kernel32) Native.loadLibrary("kernel32", Kernel32.class);

		public Pointer OpenProcess(int dwDesiredAccess, boolean bInheritHandle, int dwProcessId);

		public int GetTickCount();
	};

	public interface PsAPI extends StdCallLibrary {
		PsAPI INSTANCE = (PsAPI) Native.loadLibrary("psapi", PsAPI.class);

		int GetModuleFileNameExA(Pointer process, Pointer hModule, byte[] lpString, int nMaxCount);

	};

	public static class NativeRectangle extends Structure {

		public int left;
		public int right;
		public int top;
		public int bottom;

		@Override
		protected List<String> getFieldOrder() {
			List<String> list = new ArrayList<String>();
			list.add("left");
			list.add("top");

			list.add("right");
			list.add("bottom");

			return list;
		}
	}
}