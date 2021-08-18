/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class jkvasir_world_Mesh3D */

#ifndef _Included_jkvasir_world_Mesh3D
#define _Included_jkvasir_world_Mesh3D
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     jkvasir_world_Mesh3D
 * Method:    nativeNew
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_jkvasir_world_Mesh3D_nativeNew
  (JNIEnv *, jobject);

/*
 * Class:     jkvasir_world_Mesh3D
 * Method:    loadFromObj
 * Signature: (Ljkvasir/engine/rendering/RenderBase;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_world_Mesh3D_loadFromObj
  (JNIEnv *, jobject, jobject, jstring);

/*
 * Class:     jkvasir_world_Mesh3D
 * Method:    setDiffuseTex
 * Signature: (Ljkvasir/engine/rendering/RenderBase;J)Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_world_Mesh3D_setDiffuseTex__Ljkvasir_engine_rendering_RenderBase_2J
  (JNIEnv *, jobject, jobject, jlong);

/*
 * Class:     jkvasir_world_Mesh3D
 * Method:    setDiffuseTex
 * Signature: (Ljkvasir/engine/rendering/RenderBase;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_world_Mesh3D_setDiffuseTex__Ljkvasir_engine_rendering_RenderBase_2Ljava_lang_String_2
  (JNIEnv *, jobject, jobject, jstring);

/*
 * Class:     jkvasir_world_Mesh3D
 * Method:    setTexNum
 * Signature: (Ljkvasir/engine/rendering/RenderBase;JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_world_Mesh3D_setTexNum__Ljkvasir_engine_rendering_RenderBase_2JLjava_lang_String_2
  (JNIEnv *, jobject, jobject, jlong, jstring);

/*
 * Class:     jkvasir_world_Mesh3D
 * Method:    setTexNum
 * Signature: (Ljkvasir/engine/rendering/RenderBase;JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_world_Mesh3D_setTexNum__Ljkvasir_engine_rendering_RenderBase_2JJ
  (JNIEnv *, jobject, jobject, jlong, jlong);

/*
 * Class:     jkvasir_world_Mesh3D
 * Method:    getBuffer
 * Signature: ()Ljkvasir/engine/rendering/Buffer;
 */
JNIEXPORT jobject JNICALL Java_jkvasir_world_Mesh3D_getBuffer
  (JNIEnv *, jobject);

/*
 * Class:     jkvasir_world_Mesh3D
 * Method:    getMaterial
 * Signature: ()Ljkvasir/engine/rendering/Material;
 */
JNIEXPORT jobject JNICALL Java_jkvasir_world_Mesh3D_getMaterial
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif