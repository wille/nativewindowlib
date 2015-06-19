#include <jni.h>

#define NULL 0

jstring getstring(JNIEnv * env, char* buffer) {
	return (*env)->NewStringUTF(env, buffer);
}

char* getcstring(JNIEnv * env, jstring string) {
	return (*env)->GetStringUTFChars(env, string, NULL);
}

void callback(JNIEnv * env, int handle) {
	jmethodID method;
	jclass cls;

	cls = (*env)->FindClass(env, "nativewindowlib/WindowUtils");

	method = (*env)->GetStaticMethodID(env, cls, "callback", "(I)V");

	(*env)->CallStaticVoidMethod(env, cls, method, handle);
}

jobject getrect(JNIEnv * env, int x, int y, int width, int height) {
	jclass clazz = (*env)->FindClass(env, "java/awt/Rectangle");
	jmethodID constructor = (*env)->GetMethodID(env, clazz, "<init>", "(IIII)V");

	jobject rectangle = (*env)->NewObject(env, clazz, constructor, x, y, width, height);
	return rectangle;
}
