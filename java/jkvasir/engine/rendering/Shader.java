package jkvasir.engine.rendering;

public class Shader {
	static {
		System.loadLibrary("kvasir-jni");
	}
	private long nativePtr = 0;

	private native long nativeNew(RenderBase base);

	public Shader(RenderBase base) {
		nativePtr = nativeNew(base);
	}

	public native boolean compile(String[] srcs, long nSrcs);

	public static Shader default2D(RenderBase base) throws RenderException {
		if (base.getType() != 0x01)
			throw new RenderException("Render base is not using OPENGL.");
		Shader sh = new Shader(base);
		String[] srcs = new String[] {
				"#version 330 core\nlayout(location=0) in vec2 vpos;layout(location=1) in vec2 vuv;uniform float aspect;uniform vec2 pos;uniform mat2 transform;out vec2 uv; void main() {uv = vuv;vec4 tx=vec4(((vpos * transform) + pos), 0.0, 1.0);tx.x *= aspect;gl_Position=tx;}\n",
				"#version 330 core\nlayout(location=0) out vec4 col; in vec2 uv; uniform sampler2D diff;void main() {col=texture(diff, uv).rgba;}\n" };
		if (!sh.compile(srcs, 2))
			throw new RenderException("Default 2D shader failed compiling.");
		return sh;
	}

	public static Shader default3D(RenderBase base) throws RenderException {
		if (base.getType() != 0x01)
			throw new RenderException("Render base is not using OPENGL.");
		Shader sh = new Shader(base);
		String[] srcs = new String[] {
				"#version 330 core\nlayout(location=0) in vec3 v_pos;layout (location = 1) in vec2 v_uv;layout (location = 2) in vec3 v_normal;out vec3 normal;out vec2 uv;uniform mat4 transform;uniform mat4 rot;uniform mat4 view;uniform mat4 projection;void main(){gl_Position=projection*view*transform*vec4(v_pos, 1.0);normal=(rot*vec4(v_normal, 1.0)).xyz;uv=v_uv;}\n",
				"#version 330 core\nlayout(location=0) out vec4 col;in vec3 normal;in vec2 uv;uniform sampler2D diff;void main(){float d=(dot(normal, normalize(vec3(1.0, 1.5, 0.2))) + 1.0) / 2.0;col=vec4(texture(diff, uv).rgb * d, 1.0);}\n" };
		if (!sh.compile(srcs, 2))
			throw new RenderException("Default 3D shader failed compiling.");
		return sh;
	}

}
