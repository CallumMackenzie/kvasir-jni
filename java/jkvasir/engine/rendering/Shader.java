package jkvasir.engine.rendering;

import jkvasir.engine.KvasirException;
import jkvasir.math.Mat2;
import jkvasir.math.Mat4;
import jkvasir.math.Vec2;
import jkvasir.math.Vec3;
import jkvasir.math.Vec4;

public class Shader {
	static {
		System.loadLibrary("kvasir-jni");
	}
	private long nativePtr = 0;

	private native long nativeNew(RenderBase base);

	public Shader(RenderBase base) {
		nativePtr = nativeNew(base);
	}

	public static Shader default2D(RenderBase base) throws KvasirException {
		if (base.getType() == 0x01) {
			Shader sh = new Shader(base);
			String[] srcs = new String[] {
					"#version 330 core\nlayout(location=0) in vec2 vpos;layout(location=1) in vec2 vuv;uniform float aspect;uniform vec2 pos;uniform mat2 transform;out vec2 uv; void main() {uv = vuv;vec4 tx=vec4(((vpos * transform) + pos), 0.0, 1.0);tx.x *= aspect;gl_Position=tx;}\n",
					"#version 330 core\nlayout(location=0) out vec4 col; in vec2 uv; uniform sampler2D diff;void main() {col=texture(diff, uv).rgba;}\n" };
			if (!sh.compile(srcs, 2))
				throw new KvasirException("Default 2D shader failed compiling.");
			return sh;
		} else if (base.getType() == 0x04) {
			return null;
		} else
			throw new KvasirException("Render base is not recognized.");
	}

	public static Shader default3D(RenderBase base) throws KvasirException {
		return diffuse3D(base);
	}

	public static Shader diffuse3D(RenderBase base) throws KvasirException {
		if (base.getType() == 0x01) {
			Shader sh = new Shader(base);
			String[] srcs = new String[] {
					"#version 330 core\nlayout(location=0) in vec3 v_pos;layout (location = 1) in vec2 v_uv;layout (location = 2) in vec3 v_normal;out vec3 normal;out vec2 uv;uniform mat4 transform;uniform mat4 rot;uniform mat4 view;uniform mat4 projection;void main(){gl_Position=projection*view*transform*vec4(v_pos, 1.0);normal=(rot*vec4(v_normal, 1.0)).xyz;uv=v_uv;}\n",
					"#version 330 core\nlayout(location=0) out vec4 col;in vec3 normal;in vec2 uv;uniform sampler2D diff;void main(){float d=(dot(normal, normalize(vec3(1.0, 1.5, 0.2))) + 1.0) / 2.0;col=vec4(texture(diff, uv).rgb * d, 1.0);}\n" };
			if (!sh.compile(srcs, 2))
				throw new KvasirException("Default 3D shader failed compiling.");
			return sh;
		} else if (base.getType() == 0x04) {
			return null;
		} else
			throw new KvasirException("Render base is not recognized.");
	}

	public native boolean compile(String[] srcs, long nSrcs);

	public native void uBool1(String name, boolean a);

	public native void uBool2(String name, boolean a, boolean b);

	public native void uBool3(String name, boolean a, boolean b, boolean c);

	public native void uBool4(String name, boolean a, boolean b, boolean c, boolean d);

	public native void uInt1(String name, int a);

	public native void uInt2(String name, int a, int b);

	public native void uInt3(String name, int a, int b, int c);

	public native void uInt4(String name, int a, int b, int c, int d);

	public native void uFloat1(String name, float a);

	public native void uFloat2(String name, float a, float b);

	public native void uFloat3(String name, float a, float b, float c);

	public native void uFloat4(String name, float a, float b, float c, float d);

	public native void uMat2f(String name, float[][] m);

	public native void uMat3f(String name, float[][] m);

	public native void uMat4f(String name, float[][] m);

	public native void render(int nTris);

	public native void free_shader();

	public native void use();

	public void uMat2(String n, Mat2 mat) {
		uMat2f(n, mat.getM());
	}

	public void uMat4(String n, Mat4 mat) {
		uMat4f(n, mat.getM());
	}

	public void uVec2(String n, Vec2 v) {
		uFloat2(n, v.x(), v.y());
	}

	public void uVec3(String n, Vec3 v) {
		uFloat3(n, v.x(), v.y(), v.z());
	}

	public void uVec4(String n, Vec4 v) {
		uFloat4(n, v.x(), v.y(), v.z(), v.w());
	}
}
