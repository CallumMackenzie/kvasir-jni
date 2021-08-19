package jkvasir.math;

public class Vec2 {

	float x, y;

	float getX() {
		return x;
	}

	void setX(float x) {
		this.x = x;
	}

	void setX(double x) {
		this.x = (float) x;
	}

	float getY() {
		return y;
	}

	void setY(float y) {
		this.y = y;
	}

	void setY(double y) {
		this.y = (float) y;
	}

	public Vec2(float x, float y) {
		this.x = x;
		this.y = y;
	}

	public Vec2(float x) {
		this(x, 0.f);
	}

	public Vec2() {
		this(0);
	}

	public Vec2(Vec2 v) {
		this(v.x, v.y);
	}

	public Vec2(double x, double y) {
		this((float) x, (float) y);
	}

	/**
	 * Creates a new Vec2 casting input doubles to floats
	 * 
	 * @param x the x component
	 * @param y the y component
	 */
	public Vec2(double x) {
		this((float) x);
	}

	public float len() {
		return (float) Math.sqrt(x * x + y * y);
	}

	public Vec2 sub(Vec2... vs) {
		Vec2 vec = new Vec2(this);
		for (Vec2 v : vs) {
			vec.x -= v.x;
			vec.y -= v.y;
		}
		return vec;
	}

	/**
	 * 
	 * @param vs any number of vectors to subtract
	 * @return a copy of the Vec2 with the passed values added to it
	 */
	public Vec2 add(Vec2... vs) {
		Vec2 vec = new Vec2(this);
		for (Vec2 v : vs) {
			vec.x += v.x;
			vec.y += v.y;
		}
		return vec;
	}

	/**
	 * 
	 * @param vs any number of vectors to subtract
	 * @return a copy of the Vec2 multiplied by the passed values
	 */
	public Vec2 mul(Vec2... vs) {
		Vec2 vec = new Vec2(this);
		for (Vec2 v : vs) {
			vec.x *= v.x;
			vec.y *= v.y;
		}
		return vec;
	}

	/**
	 * 
	 * @param vs any number of vectors to subtract
	 * @return a copy of the Vec2 divided by the passed values
	 */
	public Vec2 div(Vec2... vs) {
		Vec2 vec = new Vec2(this);
		for (Vec2 v : vs) {
			if (v.x != 0)
				vec.x /= v.x;
			if (v.y != 0)
				vec.y /= v.y;
		}
		return vec;
	}

	/**
	 * 
	 * Normalizes the Vec2
	 */
	public void normalize() {
		float l = len();
		if (l == 0)
			return;
		this.x /= l;
		this.y /= l;
	}

	/**
	 * 
	 * @return a copy of the Vec2 normalized
	 */
	public Vec2 normalized() {
		float l = len();
		if (l == 0)
			l = 1.f;
		return new Vec2(this.x / l, this.y / l);
	}

	public Vec2 mulFloat(float... ns) {
		Vec2 vec = new Vec2(this);
		for (float n : ns) {
			vec.x *= n;
			vec.y *= n;
		}
		return vec;
	}

	public Vec2 mul(float... f) {
		return this.mulFloat(f);
	}

	public Vec2 divFloat(float... ns) {
		Vec2 vec = new Vec2(this);
		for (float n : ns) {
			vec.x /= n;
			vec.y /= n;

		}
		return vec;
	}

	public Vec2 div(float... f) {
		return this.divFloat(f);
	}

	public Vec2 addFloat(float... ns) {
		Vec2 vec = new Vec2(this);
		for (float n : ns) {
			vec.x += n;
			vec.y += n;
		}
		return vec;
	}

	public Vec2 add(float... f) {
		return this.addFloat(f);
	}

	public Vec2 subFloat(float... ns) {
		Vec2 vec = new Vec2(this);
		for (float n : ns) {
			vec.x -= n;
			vec.y -= n;
		}
		return vec;
	}

	public Vec2 sub(float... f) {
		return this.subFloat(f);
	}

	/**
	 * 
	 * @param mat the matrix to multiply by
	 * @return the product
	 */
	public Vec2 mulMat2(Mat2 mat) {
		return mulMat2(this, mat);
	}

	/**
	 * 
	 * @param v the vector to compare
	 * @return whether the x and y components are equal
	 */
	public boolean equalsXY(Vec2 v) {
		return (v.x == this.x && v.y == this.y);
	}

	public Vec2 addEquals(Vec2... vectors) {
		Vec2 result = this.add(vectors);
		return this.set(result);
	}

	public Vec2 addEquals(float... ns) {
		Vec2 result = this.add(ns);
		return this.set(result);
	}

	public Vec2 subEquals(Vec2... vectors) {
		Vec2 result = this.sub(vectors);
		return this.set(result);
	}

	public Vec2 subEquals(float... ns) {
		Vec2 result = this.sub(ns);
		return this.set(result);
	}

	public Vec2 mulEquals(Vec2... vectors) {
		Vec2 result = this.mul(vectors);
		return this.set(result);
	}

	public Vec2 mulEquals(float... ns) {
		Vec2 result = this.mul(ns);
		return this.set(result);
	}

	public Vec2 divEquals(Vec2... vectors) {
		Vec2 result = this.div(vectors);
		return this.set(result);
	}

	public Vec2 divEquals(float... ns) {
		Vec2 result = this.div(ns);
		return this.set(result);
	}

	public Vec2 set(Vec2 newVector) {
		this.x = newVector.x;
		this.y = newVector.y;
		return this;
	}

	public int hashCode() {
		return ("Vec2(" + x + "," + y + "," + ")").hashCode();
	}

	@Override
	public String toString() {
		return "Vec2(" + x + "," + y + ")";
	}

	/**
	 * 
	 * @param vec the base vector
	 * @param mat the matrix to multiply by
	 * @return the product
	 */
	public static Vec2 mulMat2(Vec2 vec, Mat2 mat) {
		Vec2 v = new Vec2(vec);
		v.x = (v.x * mat.getM()[0][0]) + (v.x * mat.getM()[0][1]);
		v.y = (v.y * mat.getM()[1][0]) + (v.y * mat.getM()[1][1]);
		return v;
	}

	public float x() {
		return x;
	}

	public float y() {
		return y;
	}

	public float u() {
		return x;
	}

	public float v() {
		return y;
	}

	public void setU(float u) {
		x = u;
	}

	public void setV(float v) {
		y = v;
	}

	public static float dot(Vec2 v1, Vec2 v2) {
		return v1.x * v2.x + v1.y * v2.y;
	}
}
