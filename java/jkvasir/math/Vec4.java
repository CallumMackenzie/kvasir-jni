package jkvasir.math;

public class Vec4 {
	protected float x, y, z, w;

	public Vec4(float x, float y, float z, float w) {
		this.x = x;
		this.y = y;
		this.z = z;
		this.w = w;
	}

	public Vec4(float x, float y, float z) {
		this(x, y, z, 1.f);
	}

	public Vec4(float x, float y) {
		this(x, y, 0.f, 1.f);
	}

	public Vec4(float x) {
		this(x, 0.f, 0.f, 1.f);
	}

	public Vec4() {
		this(0.f, 0.f, 0.f, 1.f);
	}

	public Vec4(Vec4 v) {
		this(v.x, v.y, v.z, v.w);
	}

	public Vec4(double x, double y, double z, double w) {
		this((float) x, (float) y, (float) z, (float) w);
	}

	public Vec4(double x, double y, double z) {
		this((float) x, (float) y, (float) z);
	}

	public Vec4(double x, double y) {
		this((float) x, (float) y);
	}

	public Vec4(double x) {
		this((float) x);
	}

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

	public float getW() {
		return w;
	}

	public void setW(float w) {
		this.w = w;
	}

	public void setW(double w) {
		this.w = (float) w;
	}

	/**
	 * 
	 * @param m the Mat4 to multiply the vector by
	 * @return a new vector with the multiplication result
	 */
	public Vec4 mulMat4(Mat4 m) {
		Vec4 v = new Vec4();
		v.x = x * m.getM()[0][0] + y * m.getM()[1][0] + z * m.getM()[2][0] + w * m.getM()[3][0];
		v.y = x * m.getM()[0][1] + y * m.getM()[1][1] + z * m.getM()[2][1] + w * m.getM()[3][1];
		v.z = x * m.getM()[0][2] + y * m.getM()[1][2] + z * m.getM()[2][2] + w * m.getM()[3][2];
		v.w = x * m.getM()[0][3] + y * m.getM()[1][3] + z * m.getM()[2][3] + w * m.getM()[3][3];
		return v;
	}

	/**
	 * 
	 * @param vs any number of vectors to add
	 * @return a new Vec4 with the sum
	 */
	public Vec4 add(Vec4... vs) {
		Vec4 vec = new Vec4(this);
		for (Vec4 v : vs) {
			vec.x += v.x;
			vec.y += v.y;
			vec.z += v.z;
		}
		return vec;
	}

	/**
	 * 
	 * @param vs any number of vectors to subtract
	 * @return a new Vec4 with the difference
	 */
	public Vec4 sub(Vec4... vs) {
		Vec4 vec = new Vec4(this);
		for (Vec4 v : vs) {
			vec.x -= v.x;
			vec.y -= v.y;
			vec.z -= v.z;
		}
		return vec;
	}

	/**
	 * 
	 * @param vs any number of vectors to multiply
	 * @return a new Vec4 with the product
	 */
	public Vec4 mul(Vec4... vs) {
		Vec4 vec = new Vec4(this);
		for (Vec4 v : vs) {
			vec.x *= v.x;
			vec.y *= v.y;
			vec.z *= v.z;
		}
		return vec;
	}

	/**
	 * 
	 * @param vs any number of vectors to divide
	 * @return a new Vec4 with the quotient
	 */
	public Vec4 div(Vec4... vs) {
		Vec4 vec = new Vec4(this);
		for (Vec4 v : vs) {
			vec.x /= v.x;
			vec.y /= v.y;
			vec.z /= v.z;
		}
		return vec;
	}

	/**
	 * 
	 * @param ns floats to multiply
	 * @return a new Vec4 with the product
	 */
	public Vec4 mulFloat(float... ns) {
		Vec4 vec = new Vec4(this);
		for (float n : ns) {
			vec.x *= n;
			vec.y *= n;
			vec.z *= n;
		}
		return vec;
	}

	public Vec4 mul(float... ns) {
		return this.mulFloat(ns);
	}

	/**
	 * 
	 * @param ns floats to add
	 * @return a new Vec4 with the sum
	 */
	public Vec4 addFloat(float... ns) {
		Vec4 vec = new Vec4(this);
		for (float n : ns) {
			vec.x += n;
			vec.y += n;
			vec.z += n;
		}
		return vec;
	}

	public Vec4 add(float... ns) {
		return this.addFloat(ns);
	}

	/**
	 * 
	 * @param ns floats to multiply
	 * @return a new Vec4 with the difference
	 */
	public Vec4 subFloat(float... ns) {
		Vec4 vec = new Vec4(this);
		for (float n : ns) {
			vec.x -= n;
			vec.y -= n;
			vec.z -= n;
		}
		return vec;
	}

	public Vec4 sub(float... ns) {
		return this.subFloat(ns);
	}

	/**
	 * 
	 * @param ns floats to multiply
	 * @return a new Vec4 with the product
	 */
	public Vec4 divFloat(float... ns) {
		Vec4 vec = new Vec4(this);
		for (float n : ns) {
			vec.x /= n;
			vec.y /= n;
			vec.z /= n;
		}
		return vec;
	}

	public Vec4 div(float... ns) {
		return this.divFloat(ns);
	}

	public Vec4 addEquals(Vec4... vectors) {
		Vec4 result = this.add(vectors);
		return this.set(result);
	}

	public Vec4 addEquals(float... ns) {
		Vec4 result = this.add(ns);
		return this.set(result);
	}

	public Vec4 subEquals(Vec4... vectors) {
		Vec4 result = this.sub(vectors);
		return this.set(result);
	}

	public Vec4 subEquals(float... ns) {
		Vec4 result = this.sub(ns);
		return this.set(result);
	}

	public Vec4 mulEquals(Vec4... vectors) {
		Vec4 result = this.mul(vectors);
		return this.set(result);
	}

	public Vec4 mulEquals(float... ns) {
		Vec4 result = this.mul(ns);
		return this.set(result);
	}

	public Vec4 divEquals(Vec4... vectors) {
		Vec4 result = this.div(vectors);
		return this.set(result);
	}

	public Vec4 divEquals(float... ns) {
		Vec4 result = this.div(ns);
		return this.set(result);
	}

	public Vec4 set(Vec4 newVector) {
		this.x = newVector.x;
		this.y = newVector.y;
		this.z = newVector.z;
		this.w = newVector.w;
		return this;
	}

	/**
	 * 
	 * @return a copy of the Vec4 normalized
	 */
	public Vec4 normalized() {
		Vec4 vec = new Vec4(this);
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
	 * Normalizes the Vec4
	 */
	public void normalize() {
		float l = len();
		if (l != 0.f) {
			this.x /= l;
			this.y /= l;
			this.z /= l;
		}
	}

	/**
	 * 
	 * @param v the vector to compare
	 * @return whether the x, y, and z components are equal
	 */
	public boolean equalsXYZ(Vec4 v) {
		return (v.x == this.x && v.y == this.y && v.z == this.z);
	}

	/**
	 * 
	 * @param v the vector to compare
	 * @return whether the x, y, z, and w components are equal
	 */
	public boolean equalsXYZW(Vec4 v) {
		return (v.x == this.x && v.y == this.y && v.z == this.z && v.w == this.w);
	}

	/**
	 * @return the length of the Vec4
	 */
	public float len() {
		return (float) Math.sqrt(Vec4.dot(this, this));
	}

	public int hashCode() {
		return ("Vec4(" + x + "," + y + "," + z + "," + w + ")").hashCode();
	}

	@Override
	public String toString() {
		return "Vec4(" + x + "," + y + "," + z + "," + w + ")";
	}

	/**
	 * 
	 * @param v1 the first Vec4
	 * @param v2 the second Vec4
	 * @return the dot product
	 */
	public static float dot(Vec4 v1, Vec4 v2) {
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	/**
	 * 
	 * @param v1 the first Vec4
	 * @param v2 the second Vec4
	 * @return the cross product
	 */
	public static Vec4 cross(Vec4 v1, Vec4 v2) {
		Vec4 v = new Vec4();
		v.x = v1.y * v2.z - v1.z * v2.y;
		v.y = v1.z * v2.x - v1.x * v2.z;
		v.z = v1.x * v2.y - v1.y * v2.x;
		return v;
	}

	public static Vec4 filledWith(float v) {
		return new Vec4(v, v, v);
	}

	public static Vec4 filledWith(double v) {
		return filledWith((float) v);
	}

	public float x() {
		return x;
	}

	public float y() {
		return y;
	}

	public float z() {
		return z;
	}

	public float w() {
		return w;
	}

	public Vec3 xyz() {
		return new Vec3(x, y, z);
	}

	public float r() {
		return x;
	}

	public float g() {
		return y;
	}

	public float b() {
		return z;
	}

	public float a() {
		return w;
	}
}
