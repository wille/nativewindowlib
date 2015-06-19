jstring getstring(JNIEnv * env, char* buffer);

char* getcstring(JNIEnv * env, jstring string);

void callback(JNIEnv * env, int handle);

jobject getrect(JNIEnv * env, int x, int y, int width, int height);
