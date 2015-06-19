#include "../os.h"

#ifdef X11

#include <jni.h>
#include <X11/Xlib.h>

#include "../nativewindowlib_WindowUtils.h"
#include "../util.h"

JNIEXPORT void JNICALL Java_nativewindowlib_WindowUtil_showWindow(JNIEnv * env, jclass z, jint handle, jint mode) {

}

JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_getTopWindow(JNIEnv * env, jclass z, jint handle) {

}

JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_getWindow(JNIEnv * env, jclass z, jint handle, jint mode) {

}

JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_isWindowVisible(JNIEnv * env, jclass z, jint handle) {

}

JNIEXPORT jstring JNICALL Java_nativewindowlib_WindowUtils_getWindowText(JNIEnv * env, jclass z, jint handle) {

}

JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_setWindowText(JNIEnv * env, jclass z, jint handle, jstring title) {

}


Window *winlist (Display *disp, unsigned long *len) {
	Atom prop = XInternAtom(disp,"_NET_CLIENT_LIST",False), type;
	int form;
	unsigned long remain;
	unsigned char *list;

	errno = 0;
	if (XGetWindowProperty(disp,XDefaultRootWindow(disp),prop,0,1024,False,XA_WINDOW,
					&type,&form,len,&remain,&list) != Success) {
		perror("winlist() -- GetWinProp");
		return 0;
	}

	return (Window*)list;
}

char *winame (Display *disp, Window win) {
	Atom prop = XInternAtom(disp,"WM_NAME",False), type;
	int form;
	unsigned long remain, len;
	unsigned char *list;

	errno = 0;
	if (XGetWindowProperty(disp,win,prop,0,1024,False,XA_STRING,
					&type,&form,&len,&remain,&list) != Success) {
		perror("winlist() -- GetWinProp");
		return NULL;
	}

	return (char*)list;
}

JNIEXPORT void JNICALL Java_nativewindowlib_WindowUtils_enumWindows(JNIEnv * env, jclass z) {
	int i;
	unsigned long len;
	Display *disp = XOpenDisplay(NULL);
	Window *list;
	char *name;

	if (!disp) {
		puts("no display!");
		return -1;
	}

	list = (Window*)winlist(disp,&len);

	Window root = list[0];

	for (i=1;i<(int)len;i++) {
		Window window = list[i];
		callback(env, (int) window);
	}

	XFree(list);

	XCloseDisplay(disp);

	callback(env, nativewindowlib_WindowUtils_CALLBACK_COMPLETED);
}

JNIEXPORT jstring JNICALL Java_nativewindowlib_WindowUtils_getProcessFromWindow(JNIEnv * env, jclass z, jint handle) {

}

JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_getFromTitle(JNIEnv * env, jclass z, jstring title) {

}

JNIEXPORT jobject JNICALL Java_nativewindowlib_WindowUtils_getWindowRect(JNIEnv * env, jclass z, jint handle) {

}

JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_moveWindow(JNIEnv * env, jclass z, jint handle, jint x, jint y, jint width, jint height) {

}

JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_setForegroundWindow(JNIEnv * env, jclass z, jint handle) {

}

JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_closeWindow(JNIEnv * env, jclass z, jint handle) {

}

JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_destroyWindow(JNIEnv * env, jclass z, jint handle) {

}

JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_showWindow(JNIEnv * env, jclass z, jint handle, jint nCmdShow) {

}

JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_getForegroundWindow(JNIEnv * env, jclass z) {

}

#endif
