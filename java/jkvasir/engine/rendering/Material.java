package jkvasir.engine.rendering;

public class Material {
	static {
		System.loadLibrary("kvasir-jni");
	}
	private long nativePtr = 0;

	private native long nativeNew(RenderBase base);

	public Material(RenderBase base) {
		nativePtr = nativeNew(base);
	}

	public native void bind();

	public native long getNumTextures();

	public native long setTexture(long index, Texture texture);

	public native Texture getTexture(long index);

}
