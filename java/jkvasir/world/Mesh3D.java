package jkvasir.world;

import jkvasir.math.Vec3;
import jkvasir.math.Vec2;
import jkvasir.math.Mat4;
import jkvasir.engine.rendering.RenderBase;
import jkvasir.engine.rendering.Buffer;
import jkvasir.engine.rendering.Material;

public class Mesh3D extends Position3D {
	static {
		System.loadLibrary("kvasir-jni");
	}

	public static class Triangle {
		public static class Vert {
			Vec3 p;
			Vec2 t;
			Vec3 n;
		}

		Vert[] v = new Vert[] { new Vert(), new Vert(), new Vert() };
	}

	private long nativePtr = 0;

	private native long nativeNew();

	public Mesh3D() {
		nativePtr = nativeNew();
	}

	public Mat4 modelMatrix() {
		Mat4 s = Mat4.scale(scale);
		Mat4 r = Mat4.rotation(rot);
		Mat4 t = Mat4.translation(pos);
		return s.mul(r, t);
	}

	public native boolean loadFromObj(RenderBase base, String filePath);

	public native boolean makeMaterial(RenderBase base);

	public native boolean setDiffuseTex(RenderBase base, long col);

	public native boolean setDiffuseTex(RenderBase base, String imgPath);

	public native boolean setTexNum(RenderBase base, long texNum, String filePath);

	public native boolean setTexNum(RenderBase base, long texNum, long colour);

	public native Buffer getBuffer();

	public native Material getMaterial();

	public native int getNumTris();

}
