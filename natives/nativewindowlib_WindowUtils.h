/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class nativewindowlib_WindowUtils */

#ifndef _Included_nativewindowlib_WindowUtils
#define _Included_nativewindowlib_WindowUtils
#ifdef __cplusplus
extern "C" {
#endif
#undef nativewindowlib_WindowUtils_CALLBACK_COMPLETED
#define nativewindowlib_WindowUtils_CALLBACK_COMPLETED -1L
#undef nativewindowlib_WindowUtils_GW_handleNEXT
#define nativewindowlib_WindowUtils_GW_handleNEXT 2L
/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    enumWindows
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_nativewindowlib_WindowUtils_enumWindows
  (JNIEnv *, jclass);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    callback
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_callback
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    EnumWindows
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_EnumWindows
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    FindWindowA
 * Signature: (Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_FindWindowA
  (JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    IsWindowVisible
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_IsWindowVisible
  (JNIEnv *, jclass, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    GetWindowRect
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_GetWindowRect
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    MoveWindow
 * Signature: (IIIIIZ)Z
 */
JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_MoveWindow
  (JNIEnv *, jclass, jint, jint, jint, jint, jint, jboolean);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    GetWindowText
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_nativewindowlib_WindowUtils_GetWindowText
  (JNIEnv *, jclass, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    SetWindowTextA
 * Signature: (ILjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_SetWindowTextA
  (JNIEnv *, jclass, jint, jstring);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    GetWindowThreadProcessId
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_GetWindowThreadProcessId__I
  (JNIEnv *, jclass, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    GetTopWindow
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_GetTopWindow
  (JNIEnv *, jclass, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    GetWindow
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_GetWindow
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    SetForegroundWindow
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_SetForegroundWindow
  (JNIEnv *, jclass, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    GetWindowThreadProcessId
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_GetWindowThreadProcessId__II
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    CloseWindow
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_CloseWindow
  (JNIEnv *, jclass, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    DestroyWindow
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_DestroyWindow
  (JNIEnv *, jclass, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    ShowWindow
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_nativewindowlib_WindowUtils_ShowWindow
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    GetForegroundWindow
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_nativewindowlib_WindowUtils_GetForegroundWindow
  (JNIEnv *, jclass);

/*
 * Class:     nativewindowlib_WindowUtils
 * Method:    getProcessFromWindow
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_nativewindowlib_WindowUtils_getProcessFromWindow
  (JNIEnv *, jclass, jint);

#ifdef __cplusplus
}
#endif
#endif
