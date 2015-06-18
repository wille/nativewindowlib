package nativewindowlib;

import java.awt.Rectangle;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public final class WindowUtils {
	
	private static final List<Integer> WINDOW_HANDLES = new ArrayList<Integer>();

	public static final int CALLBACK_COMPLETED = -1;
	public static final int GW_HWNDNEXT = 2;

	public static synchronized List<NativeWindow> getWindows() {
		final List<NativeWindow> inflList = new ArrayList<NativeWindow>();
		final List<Integer> order = new ArrayList<Integer>();

		int top = getTopWindow(0);

		while (top != 0) {
			order.add(top);
			top = getWindow(top, GW_HWNDNEXT);
			inflList.add(new NativeWindow(top));
		}

		try {
			enumWindows();

			Thread.sleep(Long.MAX_VALUE);
		} catch (InterruptedException e) {

		}
		
		
		for (int i : WINDOW_HANDLES) {
			inflList.add(new NativeWindow(i));
		}
		
		
		WINDOW_HANDLES.clear();

		Collections.sort(inflList, new Comparator<NativeWindow>() {
			public int compare(NativeWindow o1, NativeWindow o2) {
				return order.indexOf(o1.getHandle()) - order.indexOf(o2.getHandle());
			}
		});

		return inflList;
	}
	
	/**
	 * Callback method, see <a href="https://msdn.microsoft.com/en-us/library/windows/desktop/ms633497(v=vs.85).aspx">EnumWindows</a>
	 * When all windows are looped through, gets called with {@link #CALLBACK_COMPLETED} to interrupt the sleeping of {@link #getWindows()}
	 * @param handle the window handle
	 */
	private static void callback(int handle) {
		if (handle == CALLBACK_COMPLETED) {
			Thread.currentThread().interrupt();
		} else {
			WINDOW_HANDLES.add(handle);
		}
	}
	
	/**
	 * Returns the current selected window
	 * 
	 * @return
	 */
	public static NativeWindow getActiveWindow() {
		return new NativeWindow(getForegroundWindow());
	}

	/**
	 * Finds all windows and checks which are visible
	 * 
	 * @return all visible windows.
	 */
	public static List<NativeWindow> getVisibleWindows() {
		List<NativeWindow> visible = new ArrayList<NativeWindow>();
		List<NativeWindow> windows = WindowUtils.getWindows();
		
		for (NativeWindow w : windows) {
			String title = w.getTitle();

			if (w.isVisible() && title != null &&  title.length() > 0) {
				visible.add(w);
			}
		}
		
		return visible;
	}

	/**
	 * Finds all windows and searches for a matching title
	 * 
	 * @param title
	 *            the title to search for
	 * @return the window with the title that has been searched for, or null if
	 *         not found.
	 */
	public static NativeWindow getByTitle(String title) {
		return new NativeWindow(getFromTitle(title));
	}
	
	private static native void enumWindows();

	public static native int getFromTitle(String title);

	/**
	 * Is window visible (only show windows that is)
	 * 
	 * @param handle
	 * @return
	 */
	public static native boolean isWindowVisible(int handle);

	/**
	 * Gets window position
	 * 
	 * @param handle
	 * @param r
	 * @return
	 */
	public static native Rectangle getWindowRect(int handle);

	/**
	 * Moves window position
	 * 
	 * @param handle
	 * @param X
	 * @param Y
	 * @param nWidth
	 * @param nHeight
	 * @return
	 */
	public static native boolean moveWindow(int handle, int X, int Y, int nWidth, int nHeight);

	/**
	 * Gets window title
	 * 
	 * @param handle
	 */
	public static native String getWindowText(int handle);

	/**
	 * Sets window title
	 * 
	 * @param handle
	 * @param text
	 * @return
	 */
	public static native boolean setWindowText(int handle, String text);

	/**
	 * Gets window on top
	 * 
	 * @param handle
	 * @return
	 */
	public static native int getTopWindow(int handle);

	public static native int getWindow(int handle, int flag);

	/**
	 * Set focus on window
	 * 
	 * @param handle
	 * @return
	 */
	public static native boolean setForegroundWindow(int handle);

	/**
	 * Minimizes the window
	 * 
	 * @param handle
	 * @return
	 */
	public static native boolean closeWindow(int handle);

	/**
	 * Closes the window
	 * 
	 * @param handle
	 * @return
	 */
	public static native boolean destroyWindow(int handle);

	/**
	 * Changes state of the window
	 * 
	 * @param handle
	 * @param flag see {@link NativeWindow#Win32} for Windows flags
	 * @return
	 */
	public static native boolean showWindow(int handle, int flag);

	/**
	 * Returns the current Window handle
	 * 
	 * @return
	 */
	public static native int getForegroundWindow();

	public static native String getProcessFromWindow(int handle);

}