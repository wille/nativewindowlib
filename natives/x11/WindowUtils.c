#include "../os.h"

#ifdef X11

#include <jni.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>

#include "../nativewindowlib_WindowUtils.h"
#include "../util.h"


Window *winlist (Display *disp, unsigned long *len) {
	Atom prop = XInternAtom(disp,"_NET_CLIENT_LIST",False), type;
	int form;
	unsigned long remain;
	unsigned char *list;

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

	if (XGetWindowProperty(disp,win,prop,0,1024,False,XA_STRING,
					&type,&form,&len,&remain,&list) != Success) {
		perror("winlist() -- GetWinProp");
		return NULL;
	}

	return (char*)list;
}

Window getWindow(int handle) {
	int i;
	unsigned long len;
	Display *disp = XOpenDisplay(NULL);
	Window *list;
	char *name;

	if (!disp) {
		return NULL;
	}

	list = (Window*)winlist(disp,&len);

	Window root = list[0];

	for (i=1;i<(int)len;i++) {
		Window window = list[i];

		if ((int) window == handle) {
			XFree(list);
			XCloseDisplay(disp);

			return window;
		}
	}

	XFree(list);

	XCloseDisplay(disp);

	return NULL;
}

JNIEXPORT void JNICALL Java_nativewindowlib_WindowUtil_showWindow(JNIEnv * env, jclass z, jint handle, jint mode) {

}

JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_getTopWindow(JNIEnv * env, jclass z, jint handle) {
	return 0;
}

JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_getWindow(JNIEnv * env, jclass z, jint handle, jint mode) {
	return 0;
}

JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_isWindowVisible(JNIEnv * env, jclass z, jint handle) {
	return JNI_TRUE;
}

JNIEXPORT jstring JNICALL Java_nativewindowlib_WindowUtils_getWindowText(JNIEnv * env, jclass z, jint handle) {
	Window window = getWindow(handle);

	return getstring(env, winame(XOpenDisplay(NULL), window));
}

JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_setWindowText(JNIEnv * env, jclass z, jint handle, jstring title) {
	return JNI_FALSE;
}

JNIEXPORT void JNICALL Java_nativewindowlib_WindowUtils_enumWindows(JNIEnv * env, jclass z) {
	int i;
	unsigned long len;
	Display *disp = XOpenDisplay(NULL);
	Window *list;
	char *name;

	if (!disp) {
		puts("no display!");
		callback(env, nativewindowlib_WindowUtils_CALLBACK_COMPLETED);
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
	return getstring(env, "");
}

JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_getFromTitle(JNIEnv * env, jclass z, jstring title) {
	return 0;
}

JNIEXPORT jobject JNICALL Java_nativewindowlib_WindowUtils_getWindowRect(JNIEnv * env, jclass z, jint handle) {
	return NULL;
}

JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_moveWindow(JNIEnv * env, jclass z, jint handle, jint x, jint y, jint width, jint height) {
	return JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_setForegroundWindow(JNIEnv * env, jclass z, jint handle) {
	return JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_closeWindow(JNIEnv * env, jclass z, jint handle) {
	return JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_destroyWindow(JNIEnv * env, jclass z, jint handle) {
	return JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_showWindow(JNIEnv * env, jclass z, jint handle, jint nCmdShow) {
	return JNI_FALSE;
}

JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_getForegroundWindow(JNIEnv * env, jclass z) {
	return 0;
}

#endif
