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
