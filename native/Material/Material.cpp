#include "jkvasir_engine_rendering_Material.h"
#include "jni-aid.h"

using namespace kvasir;

/*
 * Class:     jkvasir_engine_rendering_Material
 * Method:    nativeNew
 * Signature: (Ljkvasir/engine/rendering/RenderBase;)J
 */
JNIEXPORT jlong JNICALL Java_jkvasir_engine_rendering_Material_nativeNew(JNIEnv *env, jobject jthis, jobject jRenderBase)
{
	render_base *base = get_native_ptr<render_base>(env, jRenderBase);
	if (!base)
		return (jlong)0;
	return (jlong)base->make_material();
}

/*
 * Class:     jkvasir_engine_rendering_Material
 * Method:    bind
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Material_bind(JNIEnv *env, jobject jthis)
{
	material_base *mat = get_native_ptr<material_base>(env, jthis);
	if (!mat)
		return;
	mat->bind();
}

/*
 * Class:     jkvasir_engine_rendering_Material
 * Method:    getNumTextures
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_jkvasir_engine_rendering_Material_getNumTextures(JNIEnv *env, jobject jthis)
{
	material_base *mat = get_native_ptr<material_base>(env, jthis);
	if (!mat)
		return (jlong)-1;
	jlong nTexs = 0;
	for (size_t i = 0; i < mat->texs.size(); ++i)
		if (mat->texs[i] != nullptr)
			++nTexs;
	return nTexs;
}

/*
 * Class:     jkvasir_engine_rendering_Material
 * Method:    setTexture
 * Signature: (JLjkvasir/engine/rendering/Texture;)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Material_setTexture(JNIEnv *env, jobject jthis, jlong jIndex, jobject jTexture)
{
	material_base *mat = get_native_ptr<material_base>(env, jthis);
	texture_base *tex = get_native_ptr<texture_base>(env, jTexture);
	if (!mat || !tex)
		return;
	while (mat->texs.size() <= (size_t)jIndex)
		mat->texs.push_back(nullptr);
	mat->texs[(size_t)jIndex] = tex;
}

/*
 * Class:     jkvasir_engine_rendering_Material
 * Method:    getTexture
 * Signature: (J)Ljkvasir/engine/rendering/Texture;
 */
JNIEXPORT jobject JNICALL Java_jkvasir_engine_rendering_Material_getTexture(JNIEnv *env, jobject jthis, jlong jIndex)
{
	material_base *mat = get_native_ptr<material_base>(env, jthis);
	if (!mat || (long)jIndex >= mat->texs.size() || jIndex < 0)
		return (jobject)NULL;
	jclass cls = env->FindClass("Ljkvasir/engine/rendering/Texture;");
	jobject tex = env->NewObject(cls, env->GetMethodID(cls, "<init>", "()V"));
	env->SetLongField(tex, env->GetFieldID(cls, "nativePtr", "J"), (jlong)mat->texs[(size_t)jIndex]);
	return tex;
}

/*
 * Class:     jkvasir_engine_rendering_Material
 * Method:    freeTextures
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Material_freeTextures(JNIEnv *env, jobject jthis)
{
	material_base *mat = get_native_ptr<material_base>(env, jthis);
	if (!mat)
		return;
	for (size_t i = 0; i < mat->texs.size(); ++i)
		if (mat->texs[i])
			mat->texs[i]->free_texture();
}
/*
 * Class:     jkvasir_engine_rendering_Material
 * Method:    getNumTexturePointers
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_jkvasir_engine_rendering_Material_getNumTexturePointers(JNIEnv *env, jobject jthis)
{
	material_base *mat = get_native_ptr<material_base>(env, jthis);
	if (!mat)
		return (jlong)0;
	return (jlong)mat->texs.size();
}