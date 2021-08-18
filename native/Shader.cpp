#include "jkvasir_engine_rendering_Shader.h"
#include "kvasir-include.h"
#include "jni-aid.h"

using namespace kvasir;

JNIEXPORT jlong JNICALL Java_jkvasir_engine_rendering_Shader_nativeNew(JNIEnv *env, jobject jthis, jobject jRenderBase)
{
	render_base *base = get_native_ptr<render_base>(env, jRenderBase);
	if (!base)
		return (jlong)0;
	return (jlong)base->make_shader();
}