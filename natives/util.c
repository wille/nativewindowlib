static jstring getstring(JNIEnv * env, char* buffer) {
	return (*env)->NewStringUTF(env, buffer);
}
