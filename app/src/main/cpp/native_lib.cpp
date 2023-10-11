#include <jni.h>
#include <string>

extern "C" int Factorial(int num);

JNIEXPORT jstring JNICALL StringFromJNI(JNIEnv *env, jclass clazz)
{
    std::string hello = "Hello from C++ " + std::to_string(Factorial(6));
    return env->NewStringUTF(hello.c_str());
}

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    JNIEnv * env;
    vm->GetEnv((void**)&env,JNI_VERSION_1_6);

    JNINativeMethod methods[] ={
            { "StringFromJNI", "()Ljava/lang/String;",(void*)StringFromJNI },
    };

    env->RegisterNatives(env->FindClass("com/noemie/androidasm/MainActivity"),methods,1);
    return JNI_VERSION_1_6;
}