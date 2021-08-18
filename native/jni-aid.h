#ifndef JNI_AID_H__
#define JNI_AID_H__ 1

#include <jni.h>

template <typename T>
T *get_native_ptr(JNIEnv *env, jobject obj)
{
	jclass clss = env->GetObjectClass(obj);
	jfieldID fid = env->GetFieldID(clss, "nativePtr", "J");
	return (T *)env->GetLongField(obj, fid);
}

#endif