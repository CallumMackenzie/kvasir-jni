package jkvasir.world;

import jkvasir.math.Vec3;
import jkvasir.math.Quaternion;

public class Position3D {
	public Vec3 pos = new Vec3();
	public Quaternion rot = Quaternion.fromEuler(new Vec3());
	public Vec3 scale = new Vec3(1, 1, 1);
	public Vec3 rotPoint = new Vec3();
}
