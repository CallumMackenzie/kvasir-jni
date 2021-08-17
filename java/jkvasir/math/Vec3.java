package jkvasir.math;

public class Vec3 {

	float x, y, z;

	public float getX() {
		return x;
	}

	public void setX(float x) {
		this.x = x;
	}

	public void setX(double x) {
		this.x = (float) x;
	}

	public float getY() {
		return y;
	}

	public void setY(float y) {
		this.y = y;
	}

	public void setY(double y) {
		this.y = (float) y;
	}

	public float getZ() {
		return z;
	}

	public void setZ(float z) {
		this.z = z;
	}

	public void setZ(double z) {
		this.z = (float) z;
	}

	public Vec3(float x, float y, float z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}

	public Vec3(float x, float y) {
		this(x, y, 0.f);
	}

	public Vec3(float x) {
		this(x, 0.f, 0.f);
	}

	public Vec3() {
		this(0, 0, 0.f);
	}

	public Vec3(Vec3 v) {
		this(v.x, v.y, v.z);
	}

	public Vec3(double x, double y, double z) {
		this((float) x, (float) y, (float) z);
	}

	public Vec3(double x, double y) {
		this((float) x, (float) y);
	}

	public Vec3(double x) {
		this((float) x);
	}

	/**
	 * 
	 * @return the length of the Vec3
	 */
	public float len() {
		return (float) Math.sqrt(x * x + y * y + z * z);
	}

	/**
	 * 
	 * @param v the vector to compare
	 * @return whether the x and y components are equal
	 */
	public boolean equalsXY(Vec3 v) {
		return (v.x == this.x && v.y == this.y);
	}

	/**
	 * 
	 * @param v the vector to compare
	 * @return whether the x, y, and w components are equal
	 */
	public boolean equalsXYZ(Vec3 v) {
		return (v.x == this.x && v.y == this.y && v.z == this.z);
	}

	/**
	 * 
	 * @param vs any number of vectors to add
	 * @return a new Vec3 with the sum
	 */
	public Vec3 add(Vec3... vs) {
		Vec3 vec = new Vec3(this);
		for (Vec3 v : vs) {
			vec.x += v.x;
			vec.y += v.y;
			vec.z += v.z;
		}
		return vec;
	}

	/**
	 * 
	 * @param vs any number of vectors to subtract
	 * @return a new Vec3 with the difference
	 */
	public Vec3 sub(Vec3... vs) {
		Vec3 vec = new Vec3(this);
		for (Vec3 v : vs) {
			vec.x -= v.x;
			vec.y -= v.y;
			vec.z -= v.z;
		}
		return vec;
	}

	/**
	 * 
	 * @param vs any number of vectors to multiply
	 * @return a new Vec3 with the product
	 */
	public Vec3 mul(Vec3... vs) {
		Vec3 vec = new Vec3(this);
		for (Vec3 v : vs) {
			vec.x *= v.x;
			vec.y *= v.y;
			vec.z *= v.z;
		}
		return vec;
	}

	/**
	 * 
	 * @param vs any number of vectors to divide
	 * @return a new Vec3 with the quotient
	 */
	public Vec3 div(Vec3... vs) {
		Vec3 vec = new Vec3(this);
		for (Vec3 v : vs) {
			vec.x /= v.x;
			vec.y /= v.y;
			vec.z /= v.z;
		}
		return vec;
	}

	/**
	 * 
	 * @param ns floats to multiply
	 * @return a new Vec3 with the product
	 */
	public Vec3 mulFloat(float... ns) {
		Vec3 vec = new Vec3(this);
		for (float n : ns) {
			vec.x *= n;
			vec.y *= n;
			vec.z *= n;
		}
		return vec;
	}

	public Vec3 mul(float... ns) {
		return this.mulFloat(ns);
	}

	/**
	 * 
	 * @param ns floats to add
	 * @return a new Vec3 with the sum
	 */
	public Vec3 addFloat(float... ns) {
		Vec3 vec = new Vec3(this);
		for (float n : ns) {
			vec.x += n;
			vec.y += n;
			vec.z += n;
		}
		return vec;
	}

	public Vec3 add(float... ns) {
		return this.addFloat(ns);
	}

	/**
	 * 
	 * @param ns floats to multiply
	 * @return a new Vec3 with the difference
	 */
	public Vec3 subFloat(float... ns) {
		Vec3 vec = new Vec3(this);
		for (float n : ns) {
			vec.x -= n;
			vec.y -= n;
			vec.z -= n;
		}
		return vec;
	}

	public Vec3 sub(float... ns) {
		return this.subFloat(ns);
	}

	/**
	 * 
	 * @param ns floats to multiply
	 * @return a new Vec3 with the product
	 */
	public Vec3 divFloat(float... ns) {
		Vec3 vec = new Vec3(this);
		for (float n : ns) {
			vec.x /= n;
			vec.y /= n;
			vec.z /= n;
		}
		return vec;
	}

	public Vec3 div(float... ns) {
		return this.divFloat(ns);
	}

	public Vec3 addEquals(Vec3... vectors) {
		Vec3 result = this.add(vectors);
		return this.set(result);
	}

	public Vec3 addEquals(float... ns) {
		Vec3 result = this.add(ns);
		return this.set(result);
	}

	public Vec3 subEquals(Vec3... vectors) {
		Vec3 result = this.sub(vectors);
		return this.set(result);
	}

	public Vec3 subEquals(float... ns) {
		Vec3 result = this.sub(ns);
		return this.set(result);
	}

	public Vec3 mulEquals(Vec3... vectors) {
		Vec3 result = this.mul(vectors);
		return this.set(result);
	}

	public Vec3 mulEquals(float... ns) {
		Vec3 result = this.mul(ns);
		return this.set(result);
	}

	public Vec3 divEquals(Vec3... vectors) {
		Vec3 result = this.div(vectors);
		return this.set(result);
	}

	public Vec3 divEquals(float... ns) {
		Vec3 result = this.div(ns);
		return this.set(result);
	}

	public Vec3 set(Vec3 newVector) {
		this.x = newVector.x;
		this.y = newVector.y;
		this.z = newVector.z;
		return this;
	}

	/**
	 * 
	 * @return a copy of the Vec3 normalized
	 */
	public Vec3 normalized() {
		Vec3 vec = new Vec3(this);
		float l = vec.len();
		if (l != 0.f) {
			vec.x /= l;
			vec.y /= l;
			vec.z /= l;
		}
		return vec;
	}

	/**
	 * 
	 * Normalizes the Vec3
	 */
	public void normalize() {
		float l = len();
		if (l != 0.f) {
			this.x /= l;
			this.y /= l;
			this.z /= l;
		}
	}

	public int hashCode() {
		return ("Vec3(" + x + "," + y + "," + z + ")").hashCode();
	}

	@Override
	public String toString() {
		return "Vec3(" + x + "," + y + ")";
	}

	public static float dot(Vec3 v1, Vec3 v2) {
		return v1.x * v2.x + v1.y * v2.y;
	}

	float x() {
		return x;
	}

	float y() {
		return y;
	}

	float z() {
		return z;
	}
}
