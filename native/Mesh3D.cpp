#include "jkvasir_world_Mesh3D.h"
#include "kvasir-include.h"
#include "jni-aid.h"

using namespace kvasir;
/*
 * Class:     jkvasir_world_Mesh3D
 * Method:    nativeNew
 * Signature: (Ljkvasir/engine/rendering/RenderBase;)J
 */
JNIEXPORT jlong JNICALL Java_jkvasir_world_Mesh3D_nativeNew(JNIEnv *env, jobject jthis)
{
	return (jlong) new mesh3d();
}

/*
 * Class:     jkvasir_world_Mesh3D
 * Method:    loadFromObj
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_world_Mesh3D_loadFromObj(JNIEnv *env, jobject jthis, jobject jRenderBase, jstring jFilePath)
{
	render_base *base = get_native_ptr<render_base>(env, jRenderBase);
	mesh3d *m = get_native_ptr<mesh3d>(env, jthis);
	if (!base || !m)
		return (jboolean) false;
	return (jboolean)m->load_from_obj(env->GetStringUTFChars(jFilePath, NULL), base->make_buffer());
}

JNIEXPORT jboolean JNICALL Java_jkvasir_world_Mesh3D_setDiffuseTex__Ljkvasir_engine_rendering_RenderBase_2J(JNIEnv *env, jobject jthis, jobject jRenderBase, jlong col)
{
	render_base *base = get_native_ptr<render_base>(env, jRenderBase);
	mesh3d *m = get_native_ptr<mesh3d>(env, jthis);
	if (!base || !m)
		return (jboolean) false;
	DEL_PTR(m->material)
	m->material = make_material(base, (long)col);
	return (jboolean)((bool)m->material);
}

/*
 * Class:     jkvasir_world_Mesh3D
 * Method:    setDiffuseTex
 * Signature: (Ljkvasir/engine/rendering/RenderBase;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_world_Mesh3D_setDiffuseTex__Ljkvasir_engine_rendering_RenderBase_2Ljava_lang_String_2(JNIEnv *env, jobject jthis, jobject jRenderBase, jstring path)
{
	render_base *base = get_native_ptr<render_base>(env, jRenderBase);
	mesh3d *m = get_native_ptr<mesh3d>(env, jthis);
	if (!base || !m)
		return (jboolean) false;
	DEL_PTR(m->material)
	m->material = make_material(base, env->GetStringUTFChars(path, NULL));
	return (jboolean)((bool)m->material);
}
