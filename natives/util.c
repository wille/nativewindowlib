#include <jni.h>

jstring getstring(JNIEnv * env, char* buffer) {
	return (*env)->NewStringUTF(env, buffer);
}

char* getcstring(JNIEnv * env, jstring string) {
	return (*env)->GetStringUTFChars(env, string, NULL);
}
