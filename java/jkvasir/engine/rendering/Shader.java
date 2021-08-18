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

}
