package jkvasir.engine.rendering;

import jkvasir.world.Camera3D;
import jkvasir.world.Mesh3D;

public class RenderBase {
	static {
		System.loadLibrary("kvasir-jni");
	}

	public static enum Type {
		OPENGL, VULKAN, TERMINAL, DIRECTX
	};

	private long nativePtr = 0;

	private native long nativeNew(long t);

	public RenderBase(Type t) {
		long type = 0;
		switch (t) {
			case OPENGL:
				type = 0x01;
				break;
			case VULKAN:
				type = 0x02;
				break;
			case TERMINAL:
				type = 0x04;
				break;
			case DIRECTX:
				type = 0x08;
				break;
			default:
				break;
		}
		nativePtr = nativeNew(type);
	}

	public native boolean shouldClose();

	public native void setClearColour(long col);

	public native void clear();

	public native void swapBuffers();

	public native void pollEvents();

	public native void setPosition(int x, int y);

	public native void setSize(int w, int h);

	public native void setTitle(String title);

	public native boolean isFullscreen();

	public native boolean setFullscreen();

	public native boolean setWindowed();

	public native boolean setResizable(boolean b);

	public native boolean isResizable();

	public native boolean setVisible(boolean visible);

	public native boolean isVisible();

	public native boolean init(String name, int w, int h);

	public native void destroy();

	public native void renderMesh3D(Camera3D c, Mesh3D m, Shader s);

	public native void depthBufferActive(boolean b);

	public native long getType();

	public native int getKeystate(int k);

	public native int getPositionX();

	public native int getPositionY();

	public native int getWidth();

	public native int getHeight();

	public native void setWidth(int w);

	public native void setHeight(int h);

	public native double getAspect();

	public native boolean keyPressed(int k);

}
