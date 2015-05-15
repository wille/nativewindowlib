# nativewindowlib

Small library for working with native windows in Windows using JNA

## Dependencies

- [jna](https://github.com/twall/jna)

## Examples

Loop through windows
```java
List<NativeWindow> windows = WindowUtils.getWindows();
		    
for (NativeWindow window : windows) {
	if (window.getTitle().length() > 0) {
		addToList(window);
	}	
}		    
```

Minimize first window in list
```java
List<NativeWindow> windows = WindowUtils.getWindows();

windows.get(0).minimize(); // maximize()....
```