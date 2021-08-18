#include "jkvasir_engine_rendering_Shader.h"
#include "kvasir-include.h"
#include "jni-aid.h"
#include <vector>

using namespace kvasir;

JNIEXPORT jlong JNICALL Java_jkvasir_engine_rendering_Shader_nativeNew(JNIEnv *env, jobject jthis, jobject jRenderBase)
{
	render_base *base = get_native_ptr<render_base>(env, jRenderBase);
	if (!base)
		return (jlong)0;
	return (jlong)base->make_shader();
}
JNIEXPORT jboolean JNICALL Java_jkvasir_engine_rendering_Shader_compile(JNIEnv *env, jobject jthis, jobjectArray jStrSrcs, jlong nSrcs)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return (jboolean) false;
	std::vector<const char *> srcs;
	for (size_t i = 0; i < (size_t)nSrcs; ++i)
		srcs.push_back(env->GetStringUTFChars((jstring)env->GetObjectArrayElement(jStrSrcs, (jsize)i), NULL));
	return (jboolean)shader->compile(&srcs[0], nSrcs);
}