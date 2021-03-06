/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class jkvasir_engine_rendering_Shader */

#ifndef _Included_jkvasir_engine_rendering_Shader
#define _Included_jkvasir_engine_rendering_Shader
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    nativeNew
 * Signature: (Ljkvasir/engine/rendering/RenderBase;)J
 */
JNIEXPORT jlong JNICALL Java_jkvasir_engine_rendering_Shader_nativeNew
  (JNIEnv *, jobject, jobject);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    compile
 * Signature: ([Ljava/lang/String;J)Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_engine_rendering_Shader_compile
  (JNIEnv *, jobject, jobjectArray, jlong);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uBool1
 * Signature: (Ljava/lang/String;Z)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uBool1
  (JNIEnv *, jobject, jstring, jboolean);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uBool2
 * Signature: (Ljava/lang/String;ZZ)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uBool2
  (JNIEnv *, jobject, jstring, jboolean, jboolean);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uBool3
 * Signature: (Ljava/lang/String;ZZZ)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uBool3
  (JNIEnv *, jobject, jstring, jboolean, jboolean, jboolean);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uBool4
 * Signature: (Ljava/lang/String;ZZZZ)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uBool4
  (JNIEnv *, jobject, jstring, jboolean, jboolean, jboolean, jboolean);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uInt1
 * Signature: (Ljava/lang/String;I)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uInt1
  (JNIEnv *, jobject, jstring, jint);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uInt2
 * Signature: (Ljava/lang/String;II)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uInt2
  (JNIEnv *, jobject, jstring, jint, jint);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uInt3
 * Signature: (Ljava/lang/String;III)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uInt3
  (JNIEnv *, jobject, jstring, jint, jint, jint);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uInt4
 * Signature: (Ljava/lang/String;IIII)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uInt4
  (JNIEnv *, jobject, jstring, jint, jint, jint, jint);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uFloat1
 * Signature: (Ljava/lang/String;F)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uFloat1
  (JNIEnv *, jobject, jstring, jfloat);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uFloat2
 * Signature: (Ljava/lang/String;FF)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uFloat2
  (JNIEnv *, jobject, jstring, jfloat, jfloat);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uFloat3
 * Signature: (Ljava/lang/String;FFF)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uFloat3
  (JNIEnv *, jobject, jstring, jfloat, jfloat, jfloat);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uFloat4
 * Signature: (Ljava/lang/String;FFFF)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uFloat4
  (JNIEnv *, jobject, jstring, jfloat, jfloat, jfloat, jfloat);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uMat2f
 * Signature: (Ljava/lang/String;[[F)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uMat2f
  (JNIEnv *, jobject, jstring, jobjectArray);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uMat3f
 * Signature: (Ljava/lang/String;[[F)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uMat3f
  (JNIEnv *, jobject, jstring, jobjectArray);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uMat4f
 * Signature: (Ljava/lang/String;[[F)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uMat4f
  (JNIEnv *, jobject, jstring, jobjectArray);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    render
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_render
  (JNIEnv *, jobject, jint);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    freeShader
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_freeShader
  (JNIEnv *, jobject);

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    use
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_use
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
