#include <jni.h>

jstring getstring(JNIEnv *env, char *buffer) {
	return (*env)->NewStringUTF(env, buffer);
}

const char* getcstring(JNIEnv *env, jstring string) {
	return (*env)->GetStringUTFChars(env, string, NULL);
}

void callback(JNIEnv *env, int handle) {
	jmethodID method;
	jclass cls;

	cls = (*env)->FindClass(env, "nativewindowlib/WindowUtils");

	method = (*env)->GetStaticMethodID(env, cls, "callback", "(I)V");

	(*env)->CallStaticVoidMethod(env, cls, method, handle);
}

/*
 * Create java.awt.Rectangle from coordinates and size
 */
jobject getrect(JNIEnv *env, int x, int y, int width, int height) {
	jclass clazz = (*env)->FindClass(env, "java/awt/Rectangle");
	jmethodID constructor = (*env)->GetMethodID(env, clazz, "<init>", "(IIII)V");

	jobject rectangle = (*env)->NewObject(env, clazz, constructor, x, y, width, height);

	return rectangle;
}
