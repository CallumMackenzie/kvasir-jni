package jkvasir.engine.rendering;

import jkvasir.engine.KvasirException;

public class Material {
	static {
		System.loadLibrary("kvasir-jni");
	}
	private long nativePtr = 0;

	private native long nativeNew(RenderBase base);

	public Material(RenderBase base) throws KvasirException {
		nativePtr = nativeNew(base);
		if (nativePtr == 0)
			throw new KvasirException("Native material_base pointer is NULL.");
	}

	private Material() {
	}

	public native void bind();

	public native long getNumTextures();

	public native void setTexture(long index, Texture texture);

	public native Texture getTexture(long index);

}
