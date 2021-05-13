#include "JniCallSo.h"
#include "example.h"

JNIEXPORT void JNICALL Java_JniCallSo_jni_1call_1so(JNIEnv* env, jclass cls, jstring jstr)
{
    const char* str = (*env)->GetStringUTFChars(env, jstr, 0);
    example(str);
}