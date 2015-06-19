# nativewindowlib

Small library for working with native windows in Windows and the X Window System using JNI

Fork of this project can be found [here](https://github.com/U2ForMeJava/nativewindowlib) which has contributed alot to the developement

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
