#include "jkvasir_engine_rendering_TextureImage.h"
#include "jni-aid.h"

using namespace kvasir;

/*
 * Class:     jkvasir_engine_rendering_TextureImage
 * Method:    nativeNew
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_jkvasir_engine_rendering_TextureImage_nativeNew(JNIEnv *env, jobject jthis)
{
	return (jlong) new texture_image();
}

/*
 * Class:     jkvasir_engine_rendering_TextureImage
 * Method:    getWidth
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_jkvasir_engine_rendering_TextureImage_getWidth(JNIEnv *env, jobject jthis)
{
	texture_image *img = get_native_ptr<texture_image>(env, jthis);
	if (!img)
		return (jlong)-1;
	return (jlong)img->w;
}

/*
 * Class:     jkvasir_engine_rendering_TextureImage
 * Method:    getHeight
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_jkvasir_engine_rendering_TextureImage_getHeight(JNIEnv *env, jobject jthis)
{
	texture_image *img = get_native_ptr<texture_image>(env, jthis);
	if (!img)
		return (jlong)-1;
	return (jlong)img->h;
}

/*
 * Class:     jkvasir_engine_rendering_TextureImage
 * Method:    getPixels
 * Signature: ()[J
 */
JNIEXPORT jlongArray JNICALL Java_jkvasir_engine_rendering_TextureImage_getPixels(JNIEnv *env, jobject jthis)
{
	texture_image *img = get_native_ptr<texture_image>(env, jthis);
	if (!img)
		return (jlongArray)NULL;
	size_t len = img->get_pixels().size() / 4;
	jlongArray jpixels = env->NewLongArray((jsize)len);
	std::vector<jlong> pixels;
	for (size_t i = 0; i < len; ++i)
		pixels.push_back(
			(jlong)((((jlong)(img->get_pixels()[i * 4 + 0] & 0xFF)) << 32) | // R
					(((jlong)(img->get_pixels()[i * 4 + 1] & 0xFF)) << 16) | // G
					(((jlong)(img->get_pixels()[i * 4 + 2] & 0xFF)) << 8) |	 // B
					(((jlong)(img->get_pixels()[i * 4 + 3] & 0xFF)) << 0))); // A
	env->SetLongArrayRegion(jpixels, (jsize)0, (jsize)len, &pixels[0]);
	pixels.clear();
	return jpixels;
}

/*
 * Class:     jkvasir_engine_rendering_TextureImage
 * Method:    setPixels
 * Signature: ([S)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_TextureImage_setPixels(JNIEnv *env, jobject jthis, jlongArray arr, jlong wid, jlong hei)
{
	texture_image *img = get_native_ptr<texture_image>(env, jthis);
	if (!img)
		return;
	jlong *dat = env->GetLongArrayElements(arr, NULL);
	size_t nelems = env->GetArrayLength(arr);
	img->get_pixels().clear();
	for (size_t i = 0; i < nelems; ++i)
	{
		img->get_pixels().push_back(dat[i] >> 32 & 0xFF); // R
		img->get_pixels().push_back(dat[i] >> 16 & 0xFF); // G
		img->get_pixels().push_back(dat[i] >> 8 & 0xFF);	// B
		img->get_pixels().push_back(dat[i] & 0xFF);		// A
	}
	img->w = (unsigned)wid;
	img->h = (unsigned)hei;
}

/*
 * Class:     jkvasir_engine_rendering_TextureImage
 * Method:    pixelRGB
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_jkvasir_engine_rendering_TextureImage_pixelRGB(JNIEnv *env, jobject jthis, jlong x, jlong y)
{
	texture_image *img = get_native_ptr<texture_image>(env, jthis);
	if (!img)
		return (jlong)-1;
	return (jlong)img->pixel_rgb((size_t)x, (size_t)y);
}
