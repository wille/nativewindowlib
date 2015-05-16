package nativewindowlib;

import java.awt.Rectangle;
import java.io.File;

import javax.swing.Icon;
import javax.swing.filechooser.FileSystemView;

import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.ptr.IntByReference;

import nativewindowlib.WindowUtils.Kernel32;
import nativewindowlib.WindowUtils.NativeRectangle;
import nativewindowlib.WindowUtils.PsAPI;
import nativewindowlib.WindowUtils.User32;

public class NativeWindow {
	
	public static final int SW_FORCEMINIMIZE = 11;
	public static final int SW_HIDE = 0;
	public static final int SW_MAXIMIZE = 3;
	public static final int SW_MINIMIZE = 6;
	public static final int SW_RESTORE = 9;
	public static final int SW_SHOW = 5;
	public static final int SW_SHOWDEFAULT = 10;
	public static final int SW_SHOWMAXIMIZED = 3;
	public static final int SW_SHOWMINIMIZED = 2;
	public static final int SW_SHOWMINNOACTIVE = 7;
	public static final int SW_SHOWNA = 8;
	public static final int SW_SHOWNOACTIVATE = 4;
	public static final int SW_SHOWNORMAL = 1;

	private int hwnd;

	public NativeWindow(int hwnd) {
		this.hwnd = hwnd;
	}

	public int getHwnd() {
		return hwnd;
	}

	/**
	 * @return an java.awt.Rectangle for the RECT
	 */
	public Rectangle getRectangle() {
		NativeRectangle rect = new NativeRectangle();
		User32.INSTANCE.GetWindowRect(hwnd, rect);
		
		return new Rectangle(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);
	}

	/**
	 * @return the title of this window
	 */
	public String getTitle() {
		byte[] buffer = new byte[1024];
		User32.INSTANCE.GetWindowTextA(hwnd, buffer, buffer.length);
		String title = Native.toString(buffer);
		
		return title;
	}

	/**
	 * @return if this window is minimized or not
	 */
	public boolean isMinimized() {
		return getRectangle().x <= -32000;
	}
	
	public String getProcess() {
		byte[] buffer = new byte[1024];

		Pointer zero = new Pointer(0);
		IntByReference pid = new IntByReference();
		User32.INSTANCE.GetWindowThreadProcessId(hwnd, pid);

		Pointer ptr = Kernel32.INSTANCE.OpenProcess(1040, false, pid.getValue());
		PsAPI.INSTANCE.GetModuleFileNameExA(ptr, zero, buffer, buffer.length);
		
		String process = Native.toString(buffer);
		
		return process;
	}
	
	/**
	 * Destroys the window
	 * @return true if this succeeded
	 */
	public boolean close() {
		return User32.INSTANCE.DestroyWindow(hwnd);
	}
	
	/**
	 * Minimizes the window
	 * @return true if this succeeded
	 */
	public boolean minimize() {
		return User32.INSTANCE.CloseWindow(hwnd);
	}
	
	/**
	 * Maximizes the window
	 * @return true if this succeeded
	 */
	public boolean maximize() {
		return User32.INSTANCE.ShowWindow(hwnd, SW_MAXIMIZE);
	}
	
	/**
	 * @return the process file icon, not the window icon
	 */
	public Icon getIcon() {
		return FileSystemView.getFileSystemView().getSystemIcon(new File(getProcess()));
	}

	/**
	 * Brings this window to front using SetForegroundWindow
	 */
	public void bringToFront() {
		WindowUtils.User32.INSTANCE.SetForegroundWindow(hwnd);
	}
	
	/**
	 * Should always be checked, if false, you might want to ignore it
	 * @return
	 */
	public boolean isVisible() {
		return User32.INSTANCE.IsWindowVisible(hwnd);
	}
	
	@Override
	public String toString() {
		StringBuilder builder = new StringBuilder();
		builder.append("NativeWindow[Hwnd=").append(getHwnd());
		builder.append(", Title=").append(getTitle());
		builder.append(", Process=").append(getProcess());
		builder.append(", Minimized=").append(isMinimized());
		builder.append(", Visible=").append(isVisible());
		builder.append("]");
		
		return builder.toString();
	}

}