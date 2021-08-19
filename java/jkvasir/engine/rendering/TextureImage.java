package jkvasir.engine.rendering;

import jkvasir.math.Vec4;
import jkvasir.engine.KvasirException;

public class TextureImage {
	static {
		System.loadLibrary("kvasir-jni");
	}
	private long nativePtr = 0;

	private native long nativeNew();

	public TextureImage() throws KvasirException {
		nativePtr = nativeNew();
		if (nativePtr == 0)
			throw new KvasirException("Native texture_image pointer is NULL.");
	}

	public native long getWidth();

	public native long getHeight();

	public native long[] getPixels();

	public native void setPixels(long[] pixels, long width, long height);

	public native long pixelRGB(long x, long y);

	public static long getPixelR(long pixel) {
		return ((pixel >> 32) & 0xFF);
	}

	public static long getPixelG(long pixel) {
		return ((pixel >> 16) & 0xFF);
	}

	public static long getPixelB(long pixel) {
		return ((pixel >> 8) & 0xFF);
	}

	public static long getPixelA(long pixel) {
		return (pixel & 0xFF);
	}

	public static long RGBAToPixel(long r, long g, long b, long a) {
		return ((r & 0xFF << 32) | (g & 0xFF << 16) | (b & 0xFF << 8) | (a & 0xFF));
	}

	public static Vec4 pixelToRGBA(long pixel) {
		return new Vec4(getPixelR(pixel), getPixelG(pixel), getPixelB(pixel), getPixelA(pixel));
	}

}
