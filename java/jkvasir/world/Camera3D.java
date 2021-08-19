package jkvasir.world;

import jkvasir.math.Vec3;
import jkvasir.math.Vec4;
import jkvasir.math.Mat4;
import jkvasir.engine.rendering.RenderBase;

public class Camera3D {
	public float fov = 75.f;
	public float near = 0.1f;
	public float far = 200.f;
	public float aspect = 1.f;

	private Vec3 pos = new Vec3();
	private Vec3 rot = new Vec3();

	public Vec3 getPos() {
		return pos;
	}

	public Vec3 getRot() {
		return rot;
	}

	public Mat4 view() {
		return Mat4.pointedAt(pos, new Vec4(0, 0, 1).mulMat4(Mat4.rotation(rot)).xyz().add(pos));
	}

	public Mat4 perspective() {
		return Mat4.perspective(fov, aspect, near, far);
	}

	public Vec3 lookVector() {
		return new Vec4(0, 0, 1).mulMat4(Mat4.rotation(rot)).xyz();
	}

	public void setProperAspect(RenderBase base) {
		if (base.type() == RenderBase.Type.TERMINAL)
			aspect = (float) base.getAspect() * 2.f;
		else
			aspect = (float) base.getAspect();
	}

	public void debugControls(RenderBase base, float delta, float camSpeed, float moveSpeed) {
		Vec3 cLV = lookVector();
		float cameraMoveSpeed = camSpeed;
		float speed = moveSpeed;

		Vec3 forward = new Vec3();
		Vec3 up = new Vec3(0.f, 1.f, 0.f);
		Vec3 rotate = new Vec3();
		if (base.keyPressed(22)) // w
			forward = forward.add(cLV);
		if (base.keyPressed(18)) // s
			forward = forward.add(cLV.mulFloat(-1.f));
		if (base.keyPressed(3)) // d
			forward = forward.sub(Vec3.cross(cLV, up));
		if (base.keyPressed(0)) // a
			forward = forward.add(Vec3.cross(cLV, up));
		if (base.keyPressed(16) || base.keyPressed(57)) // Q or space
			forward.setY(forward.getY() + 1.f);
		if (base.keyPressed(4)) // E
			forward.setY(forward.getY() - 1.f);

		if (base.keyPressed(71)) // Arrow left
			rotate.setY(cameraMoveSpeed);
		if (base.keyPressed(72)) // Arrow right
			rotate.setY(-cameraMoveSpeed);
		if (base.keyPressed(73)) // Arrow up
			rotate.setX(-cameraMoveSpeed);
		if (base.keyPressed(74)) // Arrow down
			rotate.setX(cameraMoveSpeed);
		if (base.keyPressed(38)) // Shift
			speed *= 3.f;
		if (base.keyPressed(37)) // Ctrl
			speed *= 7.f;

		this.rot = this.rot.add(rotate.mul(delta));
		this.pos = this.pos.add(forward.normalized().mul(speed * delta));

		float PI_OVER_2 = (3.1415926f / 2.f) - 0.1f;
		if (this.rot.getX() >= PI_OVER_2)
			this.rot.setX(PI_OVER_2);
		if (this.rot.getX() <= -PI_OVER_2)
			this.rot.setX(-PI_OVER_2);
		if (Math.abs(this.rot.getY()) >= 2.f * 3.14159f)
			this.rot.setY(0.f);
		if (Math.abs(this.rot.getY()) >= 2.f * 3.14159f)
			this.rot.setZ(0.f);
	}

}
