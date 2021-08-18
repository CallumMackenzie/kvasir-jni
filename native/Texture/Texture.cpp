#include "jkvasir_engine_rendering_Texture.h"
#include "jni-aid.h"

using namespace kvasir;

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    nativeNew
 * Signature: (Ljkvasir/engine/rendering/RenderBase;)J
 */
JNIEXPORT jlong JNICALL Java_jkvasir_engine_rendering_Texture_nativeNew(JNIEnv *env, jobject jthis, jobject jRenderBase)
{
	render_base *base = get_native_ptr<render_base>(env, jRenderBase);
	if (!base)
		return (jlong)0;
	return (jlong)base->make_texture();
}

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    bind
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Texture_bind(JNIEnv *env, jobject jthis)
{
	texture_base *tex = get_native_ptr<texture_base>(env, jthis);
	if (!tex)
		return;
	tex->bind();
}

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    genTexture
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Texture_genTexture(JNIEnv *env, jobject jthis)
{
	texture_base *tex = get_native_ptr<texture_base>(env, jthis);
	if (!tex)
		return;
	tex->gen_texture();
}

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    setSlot
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Texture_setSlot(JNIEnv *env, jobject jthis, jlong slot)
{
	texture_base *tex = get_native_ptr<texture_base>(env, jthis);
	if (!tex)
		return;
	tex->set_slot((size_t)slot);
}

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    setTexture
 * Signature: (Ljkvasir/engine/rendering/TextureImage;)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Texture_setTexture(JNIEnv *env, jobject jthis, jobject jTextureImage)
{
	texture_base *tex = get_native_ptr<texture_base>(env, jthis);
	texture_image *t_image = get_native_ptr<texture_image>(env, jTextureImage);
	if (!tex || !t_image)
		return;
	tex->set_texture(*t_image);
}

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    freeTexture
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Texture_freeTexture(JNIEnv *env, jobject jthis)
{
	texture_base *tex = get_native_ptr<texture_base>(env, jthis);
	if (!tex)
		return;
	tex->free_texture();
}

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    make
 * Signature: (Ljkvasir/engine/rendering/TextureImage;J)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Texture_make__Ljkvasir_engine_rendering_TextureImage_2J(JNIEnv *env, jobject jthis, jobject jTextureImage, jlong slot)
{
	texture_base *tex = get_native_ptr<texture_base>(env, jthis);
	texture_image *t_image = get_native_ptr<texture_image>(env, jTextureImage);
	if (!tex || !t_image)
		return;
	tex->make(*t_image, (size_t)slot);
}

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    make
 * Signature: (Ljava/lang/String;J)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Texture_make__Ljava_lang_String_2J(JNIEnv *env, jobject jthis, jstring jfilePath, jlong slot)
{
	texture_base *tex = get_native_ptr<texture_base>(env, jthis);
	if (!tex)
		return;
	tex->make_png(env->GetStringUTFChars(jfilePath, NULL), (size_t)slot);
}

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    make
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Texture_make__JJ(JNIEnv *env, jobject jthis, jlong col, jlong slot)
{
	texture_base *tex = get_native_ptr<texture_base>(env, jthis);
	if (!tex)
		return;
	tex->make_colour((long)col, (size_t)slot);
}

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    loadImage
 * Signature: (Ljava/lang/String;)Ljkvasir/engine/rendering/TextureImage;
 */
JNIEXPORT jobject JNICALL Java_jkvasir_engine_rendering_Texture_loadImage(JNIEnv *env, jclass jthisclass, jstring jimgPath)
{
	jclass cls = env->FindClass("Ljkvasir/engine/rendering/TextureImage;");
	jobject tex = env->NewObject(cls, env->GetMethodID(cls, "<init>", "()V"));
	texture_image *timg = get_native_ptr<texture_image>(env, tex);
	if (!timg)
		return (jobject)NULL;
	*timg = texture_base::load_image(env->GetStringUTFChars(jimgPath, NULL));
	return tex;
}

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    colourImage
 * Signature: (J)Ljkvasir/engine/rendering/TextureImage;
 */
JNIEXPORT jobject JNICALL Java_jkvasir_engine_rendering_Texture_colourImage(JNIEnv *env, jclass jthisclass, jlong col)
{
	jclass cls = env->FindClass("Ljkvasir/engine/rendering/TextureImage;");
	jobject tex = env->NewObject(cls, env->GetMethodID(cls, "<init>", "()V"));
	texture_image *timg = get_native_ptr<texture_image>(env, tex);
	if (!timg)
		return (jobject)NULL;
	*timg = texture_base::colour_image((long)col);
	return tex;
}
