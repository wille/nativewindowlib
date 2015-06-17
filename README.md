# nativewindowlib

Small library for working with native windows in Windows using JNA

## Examples

Loop through windows
```java
List<NativeWindow> windows = WindowUtils.getVisibleWindows();
		    
for (NativeWindow window : windows) {
	addToList(window);
}		    
```

Minimize first window in list
```java
List<NativeWindow> windows = WindowUtils.getVisibleWindows();

windows.get(0).minimize(); // maximize()....
```
