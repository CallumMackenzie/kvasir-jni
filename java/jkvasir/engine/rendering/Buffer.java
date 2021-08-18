package jkvasir.engine.rendering;

public class Buffer {
	static {
		System.loadLibrary("jni-kvasir");
	}
	private long nativePtr = 0;

	public Buffer(RenderBase base) {
		nativePtr = nativeNew(base);
	}

	private native long nativeNew(RenderBase base);

	public native void genBuffer();

	private native void setData(byte[] data, long len, boolean changeOften);

	private native void subData(byte[] data, long offset, long len);

	public native byte[] getData(long offset, long len);

	public native void attribPtr(long ptrNum, long size, long step, long offset);

	public native void binfBuffer();

	public native void bindVAO();

	public native void freeBuffer();

	public void setData(byte[] data, boolean changeOften) {
		setData(data, data.length, changeOften);
	}

	public void setData(byte[] data) {
		setData(data, false);
	}

	public void subData(byte[] data, long offset) {
		subData(data, offset, data.length);
	}

	public void subData(byte[] data) {
		subData(data, 0);
	}

	public void attribPtr(long ptrNum, long size, long step) {
		attribPtr(ptrNum, size, step, 0);
	}

	public void attribPtr(long ptrNum, long size) {
		attribPtr(ptrNum, size);
	}
}
