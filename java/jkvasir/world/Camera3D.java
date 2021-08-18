package jkvasir.world;

import jkvasir.math.Vec3;
import jkvasir.math.Vec4;
import jkvasir.math.Mat4;

public class Camera3D {
	public float fov = 75.f;
	public float near = 0.1f;
	public float far = 200.f;
	public float aspect = 1.f;

	Vec3 pos;
	Vec3 rot;

	Mat4 view() {
		return Mat4.pointedAt(pos.xyz1(), (new Vec4(0, 0, 1).mulMat4(Mat4.rotation(rot.xyz1())).xyz().add(pos)).xyz1());
	}

	Mat4 perspective() {
		return Mat4.perspective(fov, aspect, near, far);
	}

	Vec3 lookVector() {
		return new Vec4(0, 0, 1).mulMat4(Mat4.rotation(rot.xyz1())).xyz();
	}

}
