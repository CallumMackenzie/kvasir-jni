#include "jkvasir_world_Mesh3D.h"
#include "kvasir-include.h"
#include "jni-aid.h"

#include <iostream>

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

/*
 * Class:     jkvasir_world_Mesh3D
 * Method:    setTexNum
 * Signature: (Ljkvasir/engine/rendering/RenderBase;JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_world_Mesh3D_setTexNum__Ljkvasir_engine_rendering_RenderBase_2JLjava_lang_String_2(JNIEnv *env, jobject jthis, jobject jRenderBase, jlong texNum, jstring filePath)
{
	render_base *base = get_native_ptr<render_base>(env, jRenderBase);
	mesh3d *m = get_native_ptr<mesh3d>(env, jthis);
	if (!base || !m)
		return (jboolean) false;
	material_base *mat = m->material;
	if (!mat)
		return (jboolean) false;
	while (mat->texs.size() <= (size_t)texNum)
		mat->texs.push_back(nullptr);
	texture_base *tex = base->make_texture();
	if (!tex)
		return (jboolean) false;
	tex->make_png(env->GetStringUTFChars(filePath, NULL), (size_t)texNum);
	mat->texs[(size_t)texNum] = tex;
	return (jboolean) true;
}

/*
 * Class:     jkvasir_world_Mesh3D
 * Method:    setTexNum
 * Signature: (Ljkvasir/engine/rendering/RenderBase;JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_world_Mesh3D_setTexNum__Ljkvasir_engine_rendering_RenderBase_2JJ(JNIEnv *env, jobject jthis, jobject jRenderBase, jlong texNum, jlong colour)
{
	render_base *base = get_native_ptr<render_base>(env, jRenderBase);
	mesh3d *m = get_native_ptr<mesh3d>(env, jthis);
	if (!base || !m)
		return (jboolean) false;
	material_base *mat = m->material;
	if (!mat)
		return (jboolean) false;
	while (mat->texs.size() <= (size_t)texNum)
		mat->texs.push_back(nullptr);
	texture_base *tex = base->make_texture();
	if (!tex)
		return (jboolean) false;
	tex->make_colour((long)colour, (size_t)texNum);
	mat->texs[(size_t)texNum] = tex;
	return (jboolean) true;
}

/*
 * Class:     jkvasir_world_Mesh3D
 * Method:    getBuffer
 * Signature: ()Ljkvasir/engine/rendering/Buffer;
 */
JNIEXPORT jobject JNICALL Java_jkvasir_world_Mesh3D_getBuffer(JNIEnv *env, jobject jthis)
{
	mesh3d *m = get_native_ptr<mesh3d>(env, jthis);
	if (!m)
		return (jobject)NULL;
	if (!m->buffer)
		return (jobject)NULL;
	jclass buffer_class = env->FindClass("Ljkvasir/engine/rendering/Buffer;");
	jobject jbuff = env->NewObject(buffer_class, env->GetMethodID(buffer_class, "<init>", "()V"));
	env->SetLongField(jbuff, env->GetFieldID(buffer_class, "nativePtr", "J"), (jlong)m->buffer);
	return jbuff;
}

/*
 * Class:     jkvasir_world_Mesh3D
 * Method:    getMaterial
 * Signature: ()Ljkvasir/engine/rendering/Material;
 */
JNIEXPORT jobject JNICALL Java_jkvasir_world_Mesh3D_getMaterial(JNIEnv *env, jobject jthis)
{
	mesh3d *m = get_native_ptr<mesh3d>(env, jthis);
	if (!m)
		return (jobject)NULL;
	if (!m->material)
		return (jobject)NULL;
	jclass cls = env->FindClass("Ljkvasir/engine/rendering/Material;");
	jobject jbuff = env->NewObject(cls, env->GetMethodID(cls, "<init>", "()V"));
	env->SetLongField(jbuff, env->GetFieldID(cls, "nativePtr", "J"), (jlong)m->material);
	return jbuff;
}

/*
 * Class:     jkvasir_world_Mesh3D
 * Method:    makeMaterial
 * Signature: (Ljkvasir/engine/rendering/RenderBase;)Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_world_Mesh3D_makeMaterial(JNIEnv *env, jobject jthis, jobject jRenderBase)
{
	mesh3d *m = get_native_ptr<mesh3d>(env, jthis);
	render_base *base = get_native_ptr<render_base>(env, jRenderBase);
	if (!m || !base)
		return (jboolean) false;
	m->material = base->make_material();
	return (jboolean) true;
}

/*
 * Class:     jkvasir_world_Mesh3D
 * Method:    getNumTris
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_jkvasir_world_Mesh3D_getNumTris(JNIEnv *env, jobject jthis)
{
	mesh3d *m = get_native_ptr<mesh3d>(env, jthis);
	if (!m)
		return (jint)0;
	return (jint)m->n_tris;
}