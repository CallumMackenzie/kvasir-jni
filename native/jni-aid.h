#ifndef JNI_AID_H__
#define JNI_AID_H__ 1

#include <jni.h>
#include "kvasir-include.h"

template <typename T>
T *get_native_ptr(JNIEnv *env, jobject obj)
{
	jclass clss = env->GetObjectClass(obj);
	jfieldID fid = env->GetFieldID(clss, "nativePtr", "J");
	return (T *)env->GetLongField(obj, fid);
}

vec3f jVec3(JNIEnv *env, jobject vec);
jobject jVec3(JNIEnv *env, vec3f vec);

quaternionf jQuat(JNIEnv *env, jobject quat);
jobject jQuat(JNIEnv *env, quaternionf quat);


#endif