#include "jkvasir_engine_rendering_RenderBase.h"
#include "jni-aid.h"
#include <iostream>

using namespace kvasir;

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    nativeNew
 * Signature: (Ljkvasir/engine/rendering/RenderBase/Type;)J
 */
JNIEXPORT jlong JNICALL Java_jkvasir_engine_rendering_RenderBase_nativeNew(JNIEnv *env, jobject this_obj, jlong type)
{
	return (jlong)kvasir_engine::get_base((render_base::type)type);
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    shouldClose
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_engine_rendering_RenderBase_shouldClose(JNIEnv *env, jobject ob)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		return (jboolean)base->should_close();
	return (jboolean) false;
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    setClearColour
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_RenderBase_setClearColour(JNIEnv *env, jobject ob, jlong col)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		base->set_clear_colour((long)col);
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    clear
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_RenderBase_clear(JNIEnv *env, jobject ob)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		base->clear();
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    swapBuffers
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_RenderBase_swapBuffers(JNIEnv *env, jobject ob)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (!base)
		return;
	base->swap_buffers();
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    pollEvents
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_RenderBase_pollEvents(JNIEnv *env, jobject ob)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		base->poll_events();
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    setPosition
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_RenderBase_setPosition(JNIEnv *env, jobject ob, jint x, jint y)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		base->set_position((int)x, (int)y);
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    setSize
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_RenderBase_setSize(JNIEnv *env, jobject ob, jint x, jint y)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		base->set_size((size_t)x, (size_t)y);
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    setTitle
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_RenderBase_setTitle(JNIEnv *env, jobject ob, jstring title)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		base->set_title(env->GetStringUTFChars(title, NULL));
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    isFullscreen
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_engine_rendering_RenderBase_isFullscreen(JNIEnv *env, jobject ob)
{

	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		return (jboolean)base->is_fullscreen();
	return (jboolean) false;
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    setFullscreen
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_engine_rendering_RenderBase_setFullscreen(JNIEnv *env, jobject ob)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		return base->set_fullscreen();
	return false;
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    setWindowed
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_engine_rendering_RenderBase_setWindowed(JNIEnv *env, jobject ob)
{

	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		return base->set_windowed();
	return false;
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    setResizable
 * Signature: (Z)Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_engine_rendering_RenderBase_setResizable(JNIEnv *env, jobject ob, jboolean res)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		return base->set_resizable((bool)res);
	return false;
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    isResizable
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_engine_rendering_RenderBase_isResizable(JNIEnv *env, jobject ob)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		return base->is_resizable();
	return false;
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    setVisible
 * Signature: (Z)Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_engine_rendering_RenderBase_setVisible(JNIEnv *env, jobject ob, jboolean vis)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		return base->set_visible((bool)vis);
	return false;
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    isVisible
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_engine_rendering_RenderBase_isVisible(JNIEnv *env, jobject ob)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		return base->is_visible();
	return true;
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    init
 * Signature: (Ljava/lang/String;II)Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_engine_rendering_RenderBase_init(JNIEnv *env, jobject ob, jstring title, jint w, jint h)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		return base->init(env->GetStringUTFChars(title, NULL), (int)w, (int)h);
	return false;
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    destroy
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_RenderBase_destroy(JNIEnv *env, jobject ob)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		base->destroy();
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    renderMesh3D
 * Signature: (Ljkvasir/world/Camera3D;Ljkvasir/world/Mesh3D;Ljkvasir/engine/rendering/Shader;)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_RenderBase_renderMesh3D(JNIEnv *env, jobject ob, jobject jcam, jobject jmesh, jobject jshader)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (!base)
		return;
	mesh3d *mesh = get_native_ptr<mesh3d>(env, jmesh);
	if (!mesh)
		return;
	shader_base *shader = get_native_ptr<shader_base>(env, jshader);
	jclass cam_class = env->GetObjectClass(jcam);
	jclass mesh_class = env->GetObjectClass(jmesh);
	jobject jpos = env->GetObjectField(jcam, env->GetFieldID(cam_class, "pos", "Ljkvasir/math/Vec3;"));
	jobject jrot = env->GetObjectField(jcam, env->GetFieldID(cam_class, "rot", "Ljkvasir/math/Vec3;"));

	camera3d camera;
	camera.aspect = env->GetFloatField(jcam, env->GetFieldID(cam_class, "aspect", "F"));
	camera.near = env->GetFloatField(jcam, env->GetFieldID(cam_class, "near", "F"));
	camera.far = env->GetFloatField(jcam, env->GetFieldID(cam_class, "far", "F"));
	camera.fov = env->GetFloatField(jcam, env->GetFieldID(cam_class, "fov", "F"));
	camera.pos = jVec3(env, jpos);
	camera.rot = jVec3(env, jrot);

	jpos = env->GetObjectField(jmesh, env->GetFieldID(mesh_class, "pos", "Ljkvasir/math/Vec3;"));
	jrot = env->GetObjectField(jmesh, env->GetFieldID(mesh_class, "rot", "Ljkvasir/math/Quaternion;"));
	jobject jscale = env->GetObjectField(jmesh, env->GetFieldID(mesh_class, "scale", "Ljkvasir/math/Vec3;"));
	mesh->pos = jVec3(env, jpos);
	mesh->rot = jQuat(env, jrot);
	mesh->scale = jVec3(env, jscale);
	base->render_mesh3d(camera, *mesh, shader);
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    depthBufferActive
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_RenderBase_depthBufferActive(JNIEnv *env, jobject ob, jboolean active)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		base->depth_buffer_active((bool)active);
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    getType
 * Signature: ()Ljkvasir/engine/rendering/RenderBase/Type;
 */
JNIEXPORT jlong JNICALL Java_jkvasir_engine_rendering_RenderBase_getType(JNIEnv *env, jobject ob)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		return (jlong)base->get_type();
	return (jlong)0;
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    getKeystate
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_jkvasir_engine_rendering_RenderBase_getKeystate(JNIEnv *env, jobject ob, jint ke)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		return (jint)base->get_keystate((key)ke);
	return (jint)NoPress;
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    getPositionX
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_jkvasir_engine_rendering_RenderBase_getPositionX(JNIEnv *env, jobject ob)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		return (jint)base->get_position_x();
	return 0;
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    getPositionY
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_jkvasir_engine_rendering_RenderBase_getPositionY(JNIEnv *env, jobject ob)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		return base->get_position_y();
	return 0;
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    getWidth
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_jkvasir_engine_rendering_RenderBase_getWidth(JNIEnv *env, jobject ob)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		return (jint)base->get_width();
	return (jint)-1;
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    getHeight
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_jkvasir_engine_rendering_RenderBase_getHeight(JNIEnv *env, jobject ob)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		return (jint)base->get_height();
	return (jint)-1;
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    setWidth
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_RenderBase_setWidth(JNIEnv *env, jobject ob, jint w)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		base->set_width((int)w);
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    setHeight
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_jkvasir_engine_rendering_RenderBase_setHeight(JNIEnv *env, jobject ob, jint h)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		base->set_height((int)h);
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    getAspect
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_jkvasir_engine_rendering_RenderBase_getAspect(JNIEnv *env, jobject ob)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		return (jdouble)base->get_aspect();
	return (jdouble)0;
}

/*
 * Class:     jkvasir_engine_rendering_RenderBase
 * Method:    keyPressed
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_jkvasir_engine_rendering_RenderBase_keyPressed(JNIEnv *env, jobject ob, jint k)
{
	render_base *base = get_native_ptr<render_base>(env, ob);
	if (base)
		return (jboolean)base->get_keystate((key)k);
	return (jboolean) false;
}
