package jkvasir.world;

import jkvasir.math.Vec3;
import jkvasir.math.Vec2;
import jkvasir.engine.rendering.RenderBase;

public class Mesh3D extends Position3D {
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

	public native boolean loadFromObj(RenderBase base, String filePath);

	public native boolean setDiffuseTex(RenderBase base, long col);

	public native boolean setDiffuseTex(RenderBase base, String imgPath);

}
