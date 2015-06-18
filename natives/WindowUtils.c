#include <windows.h>
#include <psapi.h>
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

static BOOL CALLBACK EnumWindowsCallback(HWND HWND, LPARAM LPARAM) {
	JNIEnv *env = (JNIEnv *) LPARAM;

	jmethodID method;
	jclass cls;

	cls = (*env)->FindClass(env, "nativewindowlib/WindowUtils");

	method = (*env)->GetStaticMethodID(env, cls, "callback", "(I)V");

	(*env)->CallStaticVoidMethod(env, cls, method, (int) HWND);

	return TRUE;
}

JNIEXPORT void JNICALL Java_nativewindowlib_WindowUtils_enumWindows(JNIEnv * env, jclass z) {
	EnumWindows(EnumWindowsCallback, env);
	EnumWindowsCallback(nativewindowlib_WindowUtils_CALLBACK_COMPLETED, env);
}

JNIEXPORT jstring JNICALL Java_nativewindowlib_WindowUtils_getProcessFromWindow(JNIEnv * env, jclass z, jint hwnd) {
	HWND handle = (HWND) hwnd;

	LPSTR buffer = (LPSTR) malloc(MAX_PATH * sizeof(TCHAR));
	DWORD processId;
	GetWindowThreadProcessId(handle, &processId);
	HANDLE hndl = OpenProcess(1040, FALSE, processId);
	GetModuleFileNameExA(hndl, 0, buffer, MAX_PATH);
	jstring process = (*env)->NewStringUTF(env, buffer);
	free(buffer);

	return process;
}

