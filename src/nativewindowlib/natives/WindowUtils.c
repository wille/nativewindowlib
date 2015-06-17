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

JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_IsWindowVisible(JNIEnv * env, jclass z, jint hwnd) {
	return IsWindowVisible(hwnd);
}

JNIEXPORT jstring JNICALL Java_nativewindowlib_WindowUtils_GetWindowText(JNIEnv * env, jclass z, jint hwnd) {
	HWND handle = (HWND) hwnd;
	if (handle == 0) {
		return NULL;
	}

	int length = GetWindowTextLengthA(handle);
	if (length <= 0) {
		return NULL;
	}

	LPSTR buffer = (LPSTR) malloc(length * sizeof(TCHAR));
	GetWindowTextA(handle, buffer, length + 1);
	jstring title = (*env)->NewStringUTF(env, buffer);
	free(buffer);

	return title;
}
