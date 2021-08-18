package jkvasir.engine.rendering;

public class TextureImage {
	static {
		System.loadLibrary("kvasir-jni");
	}
	private long nativePtr = 0;

	private native long nativeNew();

	public TextureImage() {
		nativePtr = nativeNew();
	}

	public native long getWidth();

	public native long getHeight();

	public native long[] getPixels();

	public native long pixelRGB(long x, long y);
}
