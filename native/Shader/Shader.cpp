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
/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uBool1
 * Signature: (Ljava/lang/String;Z)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uBool1(JNIEnv *env, jobject jthis, jstring jname, jboolean jv1)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return;
	shader->u_bool1(env->GetStringUTFChars(jname, NULL), (bool)jv1);
}

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uBool2
 * Signature: (Ljava/lang/String;ZZ)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uBool2(JNIEnv *env, jobject jthis, jstring jname, jboolean jv1, jboolean jv2)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return;
	shader->u_bool2(env->GetStringUTFChars(jname, NULL), (bool)jv1, (bool)jv2);
}

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uBool3
 * Signature: (Ljava/lang/String;ZZZ)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uBool3(JNIEnv *env, jobject jthis, jstring jname, jboolean jv1, jboolean jv2, jboolean jv3)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return;
	shader->u_bool3(env->GetStringUTFChars(jname, NULL), (bool)jv1, (bool)jv2, (bool)jv3);
}

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uBool4
 * Signature: (Ljava/lang/String;ZZZZ)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uBool4(JNIEnv *env, jobject jthis, jstring jname, jboolean jv1, jboolean jv2, jboolean jv3, jboolean jv4)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return;
	shader->u_bool4(env->GetStringUTFChars(jname, NULL), (bool)jv1, (bool)jv2, (bool)jv3, (bool)jv4);
}

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uInt1
 * Signature: (Ljava/lang/String;I)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uInt1(JNIEnv *env, jobject jthis, jstring jname, jint jv1)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return;
	shader->u_int1(env->GetStringUTFChars(jname, NULL), (int)jv1);
}

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uInt2
 * Signature: (Ljava/lang/String;II)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uInt2(JNIEnv *env, jobject jthis, jstring jname, jint jv1, jint jv2)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return;
	shader->u_int2(env->GetStringUTFChars(jname, NULL), (int)jv1, (int)jv2);
}

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uInt3
 * Signature: (Ljava/lang/String;III)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uInt3(JNIEnv *env, jobject jthis, jstring jname, jint jv1, jint jv2, jint jv3)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return;
	shader->u_int3(env->GetStringUTFChars(jname, NULL), (int)jv1, (int)jv2, (int)jv3);
}

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uInt4
 * Signature: (Ljava/lang/String;IIII)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uInt4(JNIEnv *env, jobject jthis, jstring jname, jint jv1, jint jv2, jint jv3, jint jv4)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return;
	shader->u_int4(env->GetStringUTFChars(jname, NULL), (int)jv1, (int)jv2, (int)jv3, (int)jv4);
}

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uFloat1
 * Signature: (Ljava/lang/String;F)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uFloat1(JNIEnv *env, jobject jthis, jstring jname, jfloat jv1)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return;
	shader->u_float1(env->GetStringUTFChars(jname, NULL), (float)jv1);
}

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uFloat2
 * Signature: (Ljava/lang/String;FF)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uFloat2(JNIEnv *env, jobject jthis, jstring jname, jfloat jv1, jfloat jv2)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return;
	shader->u_float2(env->GetStringUTFChars(jname, NULL), (float)jv1, (float)jv2);
}

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uFloat3
 * Signature: (Ljava/lang/String;FFF)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uFloat3(JNIEnv *env, jobject jthis, jstring jname, jfloat jv1, jfloat jv2, jfloat jv3)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return;
	shader->u_float3(env->GetStringUTFChars(jname, NULL), (float)jv1, (float)jv2, (float)jv3);
}

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uFloat4
 * Signature: (Ljava/lang/String;FFFF)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uFloat4(JNIEnv *env, jobject jthis, jstring jname, jfloat jv1, jfloat jv2, jfloat jv3, jfloat jv4)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return;
	shader->u_float4(env->GetStringUTFChars(jname, NULL), (float)jv1, (float)jv2, (float)jv3, (float)jv4);
}

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uMat2f
 * Signature: (Ljava/lang/String;[[F)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uMat2f(JNIEnv *env, jobject jthis, jstring jname, jobjectArray jm2x2)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return;
	if (env->GetArrayLength(jm2x2) < 2)
		return;
	float m[2][2]{0};

	for (short i = 0; i < 2; ++i)
	{
		jfloatArray jfarr = (jfloatArray)env->GetObjectArrayElement(jm2x2, (jsize)i);
		float *elems = env->GetFloatArrayElements(jfarr, NULL);
		if (env->GetArrayLength(jfarr) < 2)
			return;
		m[i][0] = (float)elems[0];
		m[i][1] = (float)elems[1];
	}
	shader->u_mat2f(env->GetStringUTFChars(jname, NULL), m);
}

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uMat3f
 * Signature: (Ljava/lang/String;[[F)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uMat3f(JNIEnv *env, jobject jthis, jstring jname, jobjectArray jm3x3)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return;
	if (env->GetArrayLength(jm3x3) < 3)
		return;
	float m[3][3]{0};

	for (short i = 0; i < 3; ++i)
	{
		jfloatArray jfarr = (jfloatArray)env->GetObjectArrayElement(jm3x3, (jsize)i);
		float *elems = env->GetFloatArrayElements(jfarr, NULL);
		if (env->GetArrayLength(jfarr) < 3)
			return;
		for (short j = 0; j < 3; ++j)
			m[i][j] = (float)elems[j];
	}
	shader->u_mat3f(env->GetStringUTFChars(jname, NULL), m);
}

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    uMat4f
 * Signature: (Ljava/lang/String;[[F)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_uMat4f(JNIEnv *env, jobject jthis, jstring jname, jobjectArray jm4x4)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return;
	if (env->GetArrayLength(jm4x4) < 4)
		return;
	float m[4][4]{0};

	for (short i = 0; i < 4; ++i)
	{
		jfloatArray jfarr = (jfloatArray)env->GetObjectArrayElement(jm4x4, (jsize)i);
		float *elems = env->GetFloatArrayElements(jfarr, NULL);
		if (env->GetArrayLength(jfarr) < 4)
			return;
		for (short j = 0; j < 4; ++j)
			m[i][j] = (float)elems[j];
	}
	shader->u_mat4f(env->GetStringUTFChars(jname, NULL), m);
}

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    render
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_render(JNIEnv *env, jobject jthis, jint nVerts)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return;
	shader->render(nVerts);
}

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    freeShader
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_freeShader(JNIEnv *env, jobject jthis)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return;
	shader->free_shader();
}

/*
 * Class:     jkvasir_engine_rendering_Shader
 * Method:    use
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Shader_use(JNIEnv *env, jobject jthis)
{
	shader_base *shader = get_native_ptr<shader_base>(env, jthis);
	if (!shader)
		return;
	shader->use();
}