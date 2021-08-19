#include "jni-aid.h"
#include <iostream>

vec3f jVec3(JNIEnv *env, jobject vec)
{
	vec3f ret;
	jclass vec_class = env->FindClass("Ljkvasir/math/Vec3;");
	ret.x() = env->GetFloatField(vec, env->GetFieldID(vec_class, "x", "F"));
	ret.y() = env->GetFloatField(vec, env->GetFieldID(vec_class, "y", "F"));
	ret.z() = env->GetFloatField(vec, env->GetFieldID(vec_class, "z", "F"));
	return ret;
}

jobject jVec3(JNIEnv *env, vec3f vec)
{
	jclass vec_class = env->FindClass("Ljkvasir/math/Vec3;");
	jobject ret = env->NewObject(vec_class, env->GetMethodID(vec_class, "<init>", "(FFF)V"), vec.x(), vec.y(), vec.z());
	return ret;
}

quaternionf jQuat(JNIEnv *env, jobject q)
{
	quaternionf ret;
	jclass q_class = env->FindClass("Ljkvasir/math/Quaternion;");
	ret.x() = env->GetFloatField(q, env->GetFieldID(q_class, "x", "F"));
	ret.y() = env->GetFloatField(q, env->GetFieldID(q_class, "y", "F"));
	ret.z() = env->GetFloatField(q, env->GetFieldID(q_class, "z", "F"));
	ret.w() = env->GetFloatField(q, env->GetFieldID(q_class, "w", "F"));
	return ret;
}

jobject jQuat(JNIEnv *env, quaternionf q)
{
	jclass q_class = env->FindClass("Ljkvasir/math/Quaternion;");
	jobject ret = env->NewObject(q_class, env->GetMethodID(q_class, "<init>", "(FFFF)V"), q.x(), q.y(), q.z(), q.w());
	return ret;
}