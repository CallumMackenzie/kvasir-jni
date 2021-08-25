#include "jkvasir_KvasirEngine.h"
#include "jni-aid.h"

/*
 * Class:     jkvasir_KvasirEngine
 * Method:    kvasirInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_KvasirEngine_kvasirInit(JNIEnv *env, jclass thisclass)
{
	kvasir::kvasir_init();
}

/*
 * Class:     jkvasir_KvasirEngine
 * Method:    kvasirDestroy
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_KvasirEngine_kvasirDestroy(JNIEnv *env, jclass thisclass)
{
	kvasir::kvasir_destroy();
}
