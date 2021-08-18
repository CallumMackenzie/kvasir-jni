/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class jkvasir_engine_rendering_Texture */

#ifndef _Included_jkvasir_engine_rendering_Texture
#define _Included_jkvasir_engine_rendering_Texture
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    nativeNew
 * Signature: (Ljkvasir/engine/rendering/RenderBase;)J
 */
JNIEXPORT jlong JNICALL Java_jkvasir_engine_rendering_Texture_nativeNew
  (JNIEnv *, jobject, jobject);

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    bind
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Texture_bind
  (JNIEnv *, jobject);

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    genTexture
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Texture_genTexture
  (JNIEnv *, jobject);

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    setSlot
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Texture_setSlot
  (JNIEnv *, jobject, jlong);

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    setTexture
 * Signature: (Ljkvasir/engine/rendering/TextureImage;)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Texture_setTexture
  (JNIEnv *, jobject, jobject);

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    freeTexture
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Texture_freeTexture
  (JNIEnv *, jobject);

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    make
 * Signature: (Ljkvasir/engine/rendering/TextureImage;J)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Texture_make__Ljkvasir_engine_rendering_TextureImage_2J
  (JNIEnv *, jobject, jobject, jlong);

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    make
 * Signature: (Ljava/lang/String;J)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Texture_make__Ljava_lang_String_2J
  (JNIEnv *, jobject, jstring, jlong);

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    make
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Texture_make__JJ
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    loadImage
 * Signature: (Ljava/lang/String;)Ljkvasir/engine/rendering/TextureImage;
 */
JNIEXPORT jobject JNICALL Java_jkvasir_engine_rendering_Texture_loadImage
  (JNIEnv *, jclass, jstring);

/*
 * Class:     jkvasir_engine_rendering_Texture
 * Method:    colourImage
 * Signature: (J)Ljkvasir/engine/rendering/TextureImage;
 */
JNIEXPORT jobject JNICALL Java_jkvasir_engine_rendering_Texture_colourImage
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif