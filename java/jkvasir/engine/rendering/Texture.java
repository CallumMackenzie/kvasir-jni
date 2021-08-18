package jkvasir.engine.rendering;

public class Texture {
	static {
		System.loadLibrary("kvasir-jni");
	}
	private long nativePtr = 0;

	private native long nativeNew(RenderBase base);

	public Texture(RenderBase base) {
		nativePtr = nativeNew(base);
	}

	public native void bind();

	public native void genTexture();

	public native void setSlot(long slot);

	public native void setTexture(TextureImage tex);

	public native void freeTexture();

	public native void make(TextureImage tex, long slot);

	public native void make(String imagePath, long slot);

	public native void make(long colour, long slot);

	public static native TextureImage loadImage(String imgPath);

	public static native TextureImage colourImage(long colour);
}
