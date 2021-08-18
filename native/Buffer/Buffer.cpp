#include "jkvasir_engine_rendering_Buffer.h"
#include "jni-aid.h"

using namespace kvasir;

/*
 * Class:     jkvasir_engine_rendering_Buffer
 * Method:    nativeNew
 * Signature: (Ljkvasir/engine/rendering/RenderBase;)J
 */
JNIEXPORT jlong JNICALL Java_jkvasir_engine_rendering_Buffer_nativeNew(JNIEnv *env, jobject jthis, jobject jRenderBase)
{
	render_base *base = get_native_ptr<render_base>(env, jRenderBase);
	if (!base)
		return (jlong)0;
	return (jlong)base->make_buffer();
}

/*
 * Class:     jkvasir_engine_rendering_Buffer
 * Method:    genBuffer
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Buffer_genBuffer(JNIEnv *env, jobject jthis)
{
	buffer_base *buff = get_native_ptr<buffer_base>(env, jthis);
	if (!buff)
		return;
	buff->gen_buffer();
}

/*
 * Class:     jkvasir_engine_rendering_Buffer
 * Method:    setData
 * Signature: ([BJZ)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Buffer_setData(JNIEnv *env, jobject jthis, jbyteArray data, jlong len, jboolean changeOften)
{
	buffer_base *buff = get_native_ptr<buffer_base>(env, jthis);
	if (!buff)
		return;
	jbyte *dat = env->GetByteArrayElements(data, NULL);
	if (!dat)
		return;
	buff->set_data((void *)dat, (size_t)len, (bool)changeOften);
}

/*
 * Class:     jkvasir_engine_rendering_Buffer
 * Method:    subData
 * Signature: ([BJJ)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Buffer_subData(JNIEnv *env, jobject jthis, jbyteArray data, jlong offset, jlong len)
{
	buffer_base *buff = get_native_ptr<buffer_base>(env, jthis);
	if (!buff)
		return;
	jbyte *dat = env->GetByteArrayElements(data, NULL);
	buff->sub_data((void *)dat, (size_t)offset, (size_t)len);
}

/*
 * Class:     jkvasir_engine_rendering_Buffer
 * Method:    getData
 * Signature: (JJ)[B
 */
JNIEXPORT jbyteArray JNICALL Java_jkvasir_engine_rendering_Buffer_getData(JNIEnv *env, jobject jthis, jlong offset, jlong len)
{
	buffer_base *buff = get_native_ptr<buffer_base>(env, jthis);
	if (!buff)
		return (jbyteArray)NULL;
	jbyte *data = new jbyte[len];
	buff->get_data(data, (size_t)offset, (size_t)len);
	jbyteArray arr = env->NewByteArray((jsize)len);
	env->SetByteArrayRegion(arr, (jsize)0, (jsize)len, data);
	DEL_ARR_PTR(data)
	return arr;
}

/*
 * Class:     jkvasir_engine_rendering_Buffer
 * Method:    attribPtr
 * Signature: (JJJJ)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Buffer_attribPtr(JNIEnv *env, jobject jthis, jlong ptrNum, jlong size, jlong step, jlong offset)
{
	buffer_base *buff = get_native_ptr<buffer_base>(env, jthis);
	if (!buff)
		return;
	buff->attrib_ptr((size_t)ptrNum, (size_t)size, (size_t)step, (size_t)offset);
}

/*
 * Class:     jkvasir_engine_rendering_Buffer
 * Method:    binfBuffer
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Buffer_bindBuffer(JNIEnv *env, jobject jthis)
{
	buffer_base *buff = get_native_ptr<buffer_base>(env, jthis);
	if (!buff)
		return;
	buff->bind_buffer();
}

/*
 * Class:     jkvasir_engine_rendering_Buffer
 * Method:    bindVAO
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Buffer_bindVAO(JNIEnv *env, jobject jthis)
{
	buffer_base *buff = get_native_ptr<buffer_base>(env, jthis);
	if (!buff)
		return;
	buff->bind_vao();
}

/*
 * Class:     jkvasir_engine_rendering_Buffer
 * Method:    freeBuffer
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_Buffer_freeBuffer(JNIEnv *env, jobject jthis)
{
	buffer_base *buff = get_native_ptr<buffer_base>(env, jthis);
	if (!buff)
		return;
	buff->free_buffer();
}
