package jkvasir.engine.rendering;

import jkvasir.world.Camera3D;
import jkvasir.world.Mesh3D;

public class RenderBase {
	static {
		System.loadLibrary("kvasir-jni");
	}

	public static enum Type {
		OPENGL, VULKAN, TERMINAL, DIRECTX, NONE
	};

	private long nativePtr = 0;

	private native long nativeNew(long t);

	public RenderBase(Type t) {
		nativePtr = nativeNew(baseTypeConvert(t));
	}

	public static long baseTypeConvert(Type t) {
		switch (t) {
			case OPENGL:
				return 0x01;
			case VULKAN:
				return 0x02;
			case TERMINAL:
				return 0x04;
			case DIRECTX:
				return 0x08;
			default:
				break;
		}
		return 0x0;
	}

	public static Type baseTypeConvert(long t) {
		switch ((int) t) {
			case 0x01:
				return Type.OPENGL;
			case 0x02:
				return Type.VULKAN;
			case 0x04:
				return Type.TERMINAL;
			case 0x08:
				return Type.DIRECTX;
			default:
				break;
		}
		return Type.NONE;
	}

	public static String typeToString(Type t) {
		switch (t) {
			case OPENGL:
				return "OpenGL";
			case VULKAN:
				return "Vulkan";
			case TERMINAL:
				return "Terminal";
			case DIRECTX:
				return "DirectX";
			default:
				break;
		}
		return "Unknown";
	}

	public Type type() {
		return baseTypeConvert(getType());
	}

	public native boolean shouldClose();

	public native void setClearColour(long col);

	public native void clear();

	/**
	 * Swaps the render and display buffers, showing most recently drawn content.
	 * May seem slow on some systems due to v-sync.
	 */
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
