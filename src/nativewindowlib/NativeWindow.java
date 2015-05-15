package nativewindowlib;

import java.awt.Rectangle;
import java.io.File;

import javax.swing.Icon;
import javax.swing.filechooser.FileSystemView;

import nativewindowlib.WindowsUtils.NativeRectangle;

public class NativeWindow {

	private int hwnd;
	private NativeRectangle rect;
	private String title;
	private String process;

	public NativeWindow(int hwnd, NativeRectangle rect, String title, String process) {
		this.hwnd = hwnd;
		this.rect = rect;
		this.title = title;
		this.process = process;
	}

	public int getHwnd() {
		return hwnd;
	}

	/**
	 * @return an java.awt.Rectangle for the RECT
	 */
	public Rectangle getRectangle() {
		return new Rectangle(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);
	}

	/**
	 * @return the title of this window
	 */
	public String getTitle() {
		return title;
	}

	/**
	 * @return if this window is minimized or not
	 */
	public boolean isMinimized() {
		return rect.left <= -32000;
	}

	/**
	 * @return the process file icon, not the window icon
	 */
	public Icon getIcon() {
		return FileSystemView.getFileSystemView().getSystemIcon(new File(process));
	}

	/**
	 * Brings this window to front using SetForegroundWindow
	 */
	public void bringToFront() {
		WindowsUtils.User32.INSTANCE.SetForegroundWindow(hwnd);
	}

}