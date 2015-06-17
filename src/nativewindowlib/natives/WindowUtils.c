#include <windows.h>
#include <Psapi.h>
#include <jni.h>

#include "nativewindowlib_WindowUtils.h"

JNIEXPORT void JNICALL Java_nativewindowlib_WindowUtil_ShowWindow(JNIEnv * env, jclass z, jint hwnd, jint mode) {
	HWND handle = (HWND) hwnd;

	ShowWindow(handle, mode);
}

JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_GetTopWindow(JNIEnv * env, jclass z, jint hwnd) {
	return GetTopWindow(hwnd);
}

JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_GetWindow(JNIEnv * env, jclass z, jint hwnd, jint mode) {
	return GetWindow(hwnd, mode);
}
