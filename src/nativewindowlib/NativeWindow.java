package nativewindowlib;

import java.awt.Rectangle;
import java.io.File;

import javax.swing.Icon;
import javax.swing.filechooser.FileSystemView;

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

	private int handle;

	public NativeWindow(int hwnd) {
		this.handle = hwnd;
	}
	
	/**
	 * Destroys the window
	 * @return true if this succeeded
	 */
	public boolean close() {
		return WindowUtils.destroyWindow(handle);
	}
	
	/**
	 * Minimizes the window
	 * @return true if this succeeded
	 */
	public boolean minimize() {
		return WindowUtils.closeWindow(handle);
	}
	
	/**
	 * @return if this window is minimized or not
	 */
	public boolean isMinimized() {
		return getRectangle().x <= -32000;
	}
	
	/**
	 * Maximizes the window
	 * @return true if this succeeded
	 */
	public boolean maximize() {
		return WindowUtils.showWindow(handle, SW_MAXIMIZE);
	}
	
	/**
	 * Brings this window to front using SetForegroundWindow
	 */
	public void bringToFront() {
		WindowUtils.setForegroundWindow(handle);
	}
	
	/**
	 * Sets this window either visible or invisible
	 * @param visible state of the window
	 * @return true if this succeeded
	 */
	public boolean setVisible(boolean visible) {
		return WindowUtils.showWindow(handle, visible ? SW_SHOW : SW_HIDE);
	}
	
	/**
	 * Should always be checked, if false, you might want to ignore it
	 * @return true if this window is visible
	 */
	public boolean isVisible() {
		return WindowUtils.isWindowVisible(handle);
	}
	
	/**
	 * @return the window handle (hwnd on Windows, Window object casted to int in x11)
	 */
	public int getHandle() {
		return handle;
	}
	
	public boolean setRectangle(Rectangle rect) {
		return WindowUtils.MoveWindow(handle, rect.x, rect.y, rect.width, rect.height, true);
	}

	/**
	 * @return an java.awt.Rectangle for the RECT
	 */
	public Rectangle getRectangle() {
		//NativeRectangle rect = new NativeRectangle();
		//WindowUtils.GetWindowRect(hwnd, null);
		return null;
		//return new Rectangle(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);
	}
	
	/**
	 * Sets the title of this window
	 * @param title
	 * @return true if this operation succeeded
	 */
	public boolean setTitle(String title) {
		return WindowUtils.SetWindowTextA(handle, title);
	}

	/**
	 * @return the title of this window
	 */
	public String getTitle() {	
		return WindowUtils.getWindowText(handle);
	}
	
	public String getProcess() {
		return WindowUtils.getProcessFromWindow(handle);
	}
	
	/**
	 * @return the process file icon, not the window icon
	 */
	public Icon getIcon() {
		return FileSystemView.getFileSystemView().getSystemIcon(new File(getProcess()));
	}
	
	@Override
	public String toString() {
		StringBuilder builder = new StringBuilder();
		builder.append("NativeWindow[Hwnd=").append(getHandle());
		builder.append(", Title=").append(getTitle());
		builder.append(", Process=").append(getProcess());
		builder.append(", Minimized=").append(isMinimized());
		builder.append(", Visible=").append(isVisible());
		builder.append("]");
		
		return builder.toString();
	}

}