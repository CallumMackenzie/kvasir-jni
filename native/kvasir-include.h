#ifndef KVASIR_INCLUDE_H__
#define KVASIR_INCLUDE_H__ 1

#include <stddef.h>
#include <string.h>
#include <time.h>
#include <initializer_list>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <memory>

#define FORCE_INLINE inline

#ifdef _WIN32
typedef unsigned int uint;
#endif

#define ALGEBRAIC_VEC(CLASS, NELEMS)                           \
	friend CLASS operator*(const CLASS &lhs, const CLASS &rhs) \
	{                                                          \
		CLASS ret;                                             \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			ret[i] = lhs[i] * rhs[i];                          \
		return ret;                                            \
	}                                                          \
	friend CLASS operator/(const CLASS &lhs, const CLASS &rhs) \
	{                                                          \
		CLASS ret;                                             \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			ret[i] = lhs[i] / rhs[i];                          \
		return ret;                                            \
	}                                                          \
	friend CLASS operator+(const CLASS &lhs, const CLASS &rhs) \
	{                                                          \
		CLASS ret;                                             \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			ret[i] = lhs[i] + rhs[i];                          \
		return ret;                                            \
	}                                                          \
	friend CLASS operator-(const CLASS &lhs, const CLASS &rhs) \
	{                                                          \
		CLASS ret;                                             \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			ret[i] = lhs[i] - rhs[i];                          \
		return ret;                                            \
	}                                                          \
	friend CLASS operator*(const CLASS &lhs, const T &rhs)     \
	{                                                          \
		CLASS ret;                                             \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			ret[i] = lhs[i] * rhs;                             \
		return ret;                                            \
	}                                                          \
	friend CLASS operator/(const CLASS &lhs, const T &rhs)     \
	{                                                          \
		CLASS ret;                                             \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			ret[i] = lhs[i] / rhs;                             \
		return ret;                                            \
	}                                                          \
	friend CLASS operator+(const CLASS &lhs, const T &rhs)     \
	{                                                          \
		CLASS ret;                                             \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			ret[i] = lhs[i] + rhs;                             \
		return ret;                                            \
	}                                                          \
	friend CLASS operator-(const CLASS &lhs, const T &rhs)     \
	{                                                          \
		CLASS ret;                                             \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			ret[i] = lhs[i] - rhs;                             \
		return ret;                                            \
	}                                                          \
	friend CLASS operator*(const T &lhs, const CLASS &rhs)     \
	{                                                          \
		CLASS ret;                                             \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			ret[i] = lhs * rhs[i];                             \
		return ret;                                            \
	}                                                          \
	friend CLASS operator/(const T &lhs, const CLASS &rhs)     \
	{                                                          \
		CLASS ret;                                             \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			ret[i] = lhs / rhs[i];                             \
		return ret;                                            \
	}                                                          \
	friend CLASS operator+(const T &lhs, const CLASS &rhs)     \
	{                                                          \
		CLASS ret;                                             \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			ret[i] = lhs + rhs[i];                             \
		return ret;                                            \
	}                                                          \
	friend CLASS operator-(const T &lhs, const CLASS &rhs)     \
	{                                                          \
		CLASS ret;                                             \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			ret[i] = lhs - rhs[i];                             \
		return ret;                                            \
	}                                                          \
	friend bool operator==(const CLASS &lhs, const CLASS &rhs) \
	{                                                          \
		bool res = true;                                       \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			res &= (lhs.v[i] == rhs.v[i]);                     \
		return res;                                            \
	}                                                          \
	friend bool operator!=(const CLASS &lhs, const CLASS &rhs) \
	{                                                          \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			if (lhs[i] != rhs[i])                              \
				return true;                                   \
		return false;                                          \
	}                                                          \
	CLASS &operator+=(const CLASS &rhs)                        \
	{                                                          \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			v[i] += rhs[i];                                    \
		return *this;                                          \
	}                                                          \
	CLASS &operator-=(const CLASS &rhs)                        \
	{                                                          \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			v[i] -= rhs[i];                                    \
		return *this;                                          \
	}                                                          \
	CLASS &operator/=(const CLASS &rhs)                        \
	{                                                          \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			v[i] /= rhs[i];                                    \
		return *this;                                          \
	}                                                          \
	CLASS &operator*=(const CLASS &rhs)                        \
	{                                                          \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			v[i] *= rhs[i];                                    \
		return *this;                                          \
	}                                                          \
	CLASS &operator+=(const T &rhs)                            \
	{                                                          \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			v[i] += rhs;                                       \
		return *this;                                          \
	}                                                          \
	CLASS &operator-=(const T &rhs)                            \
	{                                                          \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			v[i] -= rhs;                                       \
		return *this;                                          \
	}                                                          \
	CLASS &operator/=(const T &rhs)                            \
	{                                                          \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			v[i] /= rhs;                                       \
		return *this;                                          \
	}                                                          \
	CLASS &operator*=(const T &rhs)                            \
	{                                                          \
		for (size_s i = 0; i < NELEMS; ++i)                    \
			v[i] *= rhs;                                       \
		return *this;                                          \
	}

#define VEC_STD_OPS(CLASS, NELEMS)              \
	T dot(const CLASS &v2) const                \
	{                                           \
		T sum = 0;                              \
		for (size_s i = 0; i < NELEMS; ++i)     \
			sum += (v[i] * v2[i]);              \
		return sum;                             \
	}                                           \
	T len() const                               \
	{                                           \
		return (T)sqrtf((float)dot(*this));     \
	}                                           \
	CLASS &normalize()                          \
	{                                           \
		T l = len();                            \
		if (l != 0)                             \
			for (size_s i = 0; i < NELEMS; ++i) \
				v[i] /= l;                      \
		return *this;                           \
	}                                           \
	CLASS normalized() const                    \
	{                                           \
		T l = len();                            \
		CLASS ret;                              \
		if (l != 0)                             \
			for (size_s i = 0; i < NELEMS; ++i) \
				ret.v[i] = v[i] / l;            \
		return ret;                             \
	}

#define MAT_NUM_OP(CLASS, SZ, OP)                            \
	friend CLASS operator OP(const CLASS &lhs, const T &rhs) \
	{                                                        \
		CLASS ret = lhs;                                     \
		for (size_s i = 0; i < SZ; ++i)                      \
			for (size_s j = 0; j < SZ; ++j)                  \
				ret[i][j] OP## = rhs;                        \
		return ret;                                          \
	}

#define ALGEBRAIC_MAT_SQUARE(CLASS, SZ)                                  \
	MAT_NUM_OP(CLASS, SZ, +)                                             \
	MAT_NUM_OP(CLASS, SZ, -)                                             \
	MAT_NUM_OP(CLASS, SZ, /)                                             \
	MAT_NUM_OP(CLASS, SZ, *)                                             \
	friend CLASS operator*(const CLASS &lhs, const CLASS &rhs)           \
	{                                                                    \
		CLASS ret;                                                       \
		for (size_s r = 0; r < SZ; ++r)                                  \
			for (size_s c = 0; c < SZ; ++c)                              \
				for (size_s i = 0; i < SZ; ++i)                          \
					ret[r][c] += lhs[r][i] * rhs[i][c];                  \
		return ret;                                                      \
	}                                                                    \
	friend bool operator==(const CLASS &lhs, const CLASS &rhs)           \
	{                                                                    \
		for (size_s r = 0; r < SZ; ++r)                                  \
			for (size_s c = 0; c < SZ; ++c)                              \
				if (lhs[r][c] != rhs[r][c])                              \
					return false;                                        \
		return true;                                                     \
	}                                                                    \
	friend bool operator!=(const CLASS &lhs, const CLASS &rhs)           \
	{                                                                    \
		return !(lhs == rhs);                                            \
	}                                                                    \
	friend vec##SZ<T> operator*(const CLASS &lhs, const vec##SZ<T> &rhs) \
	{                                                                    \
		vec##SZ<T> ret;                                                  \
		for (size_s r = 0; r < SZ; ++r)                                  \
			for (size_s c = 0; c < SZ; ++c)                              \
				ret.v[c] += rhs[r] * lhs[r][c];                          \
		return ret;                                                      \
	}                                                                    \
	CLASS get_cofactor(int p, int q, int n) const                        \
	{                                                                    \
		CLASS temp;                                                      \
		int i = 0, j = 0;                                                \
		for (int row = 0; row < n; ++row)                                \
			for (int col = 0; col < n; ++col)                            \
				if (row != p && col != q)                                \
				{                                                        \
					temp[i][j] = m[row][col];                            \
					if ((++j) == n - 1)                                  \
					{                                                    \
						j = 0;                                           \
						++i;                                             \
					}                                                    \
				}                                                        \
		return temp;                                                     \
	}                                                                    \
	T determinant(int n = SZ) const                                      \
	{                                                                    \
		if (n == 1)                                                      \
			return m[0][0];                                              \
		T D = 0;                                                         \
		CLASS temp;                                                      \
		int sign = 1;                                                    \
		for (int f = 0; f < n; ++f)                                      \
		{                                                                \
			temp = get_cofactor(0, f, n);                                \
			D += ((T)sign) * m[0][f] * temp.determinant(n - 1);          \
			sign = -sign;                                                \
		}                                                                \
		return D;                                                        \
	}                                                                    \
	CLASS adjoint() const                                                \
	{                                                                    \
		int sign = 1;                                                    \
		CLASS temp;                                                      \
		CLASS adj;                                                       \
		for (size_s i = 0; i < 4; ++i)                                   \
			for (size_s j = 0; j < 4; ++j)                               \
			{                                                            \
				temp = get_cofactor(i, j, 4);                            \
				sign = ((i + j) % 2 == 0) ? 1 : -1;                      \
				adj.m[j][i] = (T)sign * temp.determinant(3);             \
			}                                                            \
		return adj;                                                      \
	}                                                                    \
	CLASS inverse() const                                                \
	{                                                                    \
		return adjoint() / determinant();                                \
	}

namespace galg
{
	typedef float fp_num;
	typedef unsigned short size_s;

	template <typename T>
	struct vec4;
	template <typename T>
	struct vec3;
	template <typename T>
	struct vec2;
	template <typename T>
	struct quaternion;
	template <typename T>
	struct mat4;
	template <typename T>
	struct mat3;
	template <typename T>
	struct mat2;

	typedef vec4<fp_num> vec4fp;
	typedef vec4<float> vec4f;
	typedef vec4<double> vec4d;
	typedef vec4<int> vec4i;
	typedef vec4<uint> vec4ui;
	typedef vec4<size_t> vec4st;
	typedef vec4<unsigned short> vec4us;
	typedef vec4<short> vec4s;

	typedef vec3<fp_num> vec3fp;
	typedef vec3<float> vec3f;
	typedef vec3<double> vec3d;
	typedef vec3<int> vec3i;
	typedef vec3<uint> vec3ui;
	typedef vec3<size_t> vec3st;
	typedef vec3<unsigned short> vec3us;
	typedef vec3<short> vec3s;

	typedef vec2<fp_num> vec2fp;
	typedef vec2<float> vec2f;
	typedef vec2<double> vec2d;
	typedef vec2<int> vec2i;
	typedef vec2<uint> vec2ui;
	typedef vec2<size_t> vec2st;
	typedef vec2<unsigned short> vec2us;
	typedef vec2<short> vec2s;

	typedef quaternion<fp_num> quaternionfp;
	typedef quaternion<float> quaternionf;
	typedef quaternion<double> quaterniond;
	typedef quaternion<int> quaternioni;
	typedef quaternion<uint> quaternionui;
	typedef quaternion<size_t> quaternionst;
	typedef quaternion<unsigned short> quaternionus;
	typedef quaternion<short> quaternions;

	typedef mat4<fp_num> mat4fp;
	typedef mat4<float> mat4f;
	typedef mat4<double> mat4d;
	typedef mat4<int> mat4i;
	typedef mat4<uint> mat4ui;
	typedef mat4<size_t> mat4st;
	typedef mat4<unsigned short> mat4us;
	typedef mat4<short> mat4s;

	typedef mat3<fp_num> mat3fp;
	typedef mat3<float> mat3f;
	typedef mat3<double> mat3d;
	typedef mat3<int> mat3i;
	typedef mat3<uint> mat3ui;
	typedef mat3<size_t> mat3st;
	typedef mat3<unsigned short> mat3us;
	typedef mat3<short> mat3s;

	typedef mat2<fp_num> mat2fp;
	typedef mat2<float> mat2f;
	typedef mat2<double> mat2d;
	typedef mat2<int> mat2i;
	typedef mat2<uint> mat2ui;
	typedef mat2<size_t> mat2st;
	typedef mat2<unsigned short> mat2us;
	typedef mat2<short> mat2s;

	template <typename T = fp_num>
	struct vec4
	{
		T v[4];

		vec4(std::initializer_list<T> lst)
		{
			v[3] = 1;
			short ctr = -1;
			for (auto i : lst)
				if (ctr <= 2)
					v[++ctr] = i;
				else
					break;
		}

		vec4(T x = 0, T y = 0, T z = 0, T w = (T)1)
		{
			v[0] = x;
			v[1] = y;
			v[2] = z;
			v[3] = w;
		}

		vec4(vec3<T> v, T w = 1) : vec4(v.x(), v.y(), v.z(), w) {}

		FORCE_INLINE T &x() { return v[0]; }
		FORCE_INLINE T &y() { return v[1]; }
		FORCE_INLINE T &z() { return v[2]; }
		FORCE_INLINE T &w() { return v[3]; }
		FORCE_INLINE const T &x() const { return v[0]; }
		FORCE_INLINE const T &y() const { return v[1]; }
		FORCE_INLINE const T &z() const { return v[2]; }
		FORCE_INLINE const T &w() const { return v[3]; }

		FORCE_INLINE vec3<T> xyz() const { return vec3<T>(x(), y(), z()); }
		FORCE_INLINE vec2<T> xy() const { return vec2<T>(x(), y()); }

		FORCE_INLINE T &operator[](size_t index)
		{
			return v[index];
		}
		FORCE_INLINE const T &operator[](size_t index) const
		{
			return v[index];
		}

		FORCE_INLINE vec4 cross(vec4 &v2) const
		{
			return vec4(
				(y() * v2.z()) - (z() * v2.y()),
				(z() * v2.x()) - (x() * v2.z()),
				(x() * v2.y()) - (y() * v2.x()));
		}

		void set(T x, T y = y(), T z = z(), T w = w())
		{
			x() = x;
			y() = y;
			z() = z;
			w() = w;
		}

		ALGEBRAIC_VEC(vec4, 4)
		VEC_STD_OPS(vec4, 4)
	};

	template <typename T = fp_num>
	struct vec3
	{
		T v[3];

		vec3(std::initializer_list<T> lst)
		{
			short ctr = -1;
			for (auto i : lst)
				v[++ctr] = i;
		}
		vec3(T x = 0, T y = 0, T z = 0)
		{
			v[0] = x;
			v[1] = y;
			v[2] = z;
		}

		FORCE_INLINE T &x() { return v[0]; }
		FORCE_INLINE T &y() { return v[1]; }
		FORCE_INLINE T &z() { return v[2]; }
		FORCE_INLINE const T &x() const { return v[0]; }
		FORCE_INLINE const T &y() const { return v[1]; }
		FORCE_INLINE const T &z() const { return v[2]; }

		FORCE_INLINE T &operator[](size_t index)
		{
			return v[index];
		}
		FORCE_INLINE const T &operator[](size_t index) const
		{
			return v[index];
		}

		vec3 cross(vec3 &v2) const
		{
			return vec3(
				(y() * v2.z()) - (z() * v2.y()),
				(z() * v2.x()) - (x() * v2.z()),
				(x() * v2.y()) - (y() * v2.x()));
		}

		FORCE_INLINE vec4<T> xyz1() { return vec4<T>(x(), y(), z(), (T)1); }
		FORCE_INLINE vec2<T> xy() const { return vec2<T>(x(), y()); }

		ALGEBRAIC_VEC(vec3, 3)
		VEC_STD_OPS(vec3, 3)
	};

	template <typename T = fp_num>
	struct vec2
	{
		T v[2];

		vec2(std::initializer_list<T> lst)
		{
			short ctr = -1;
			for (auto i : lst)
				v[++ctr] = i;
		}
		vec2(T x = 0, T y = 0)
		{
			v[0] = x;
			v[1] = y;
		}

		FORCE_INLINE T &x() { return v[0]; }
		FORCE_INLINE T &y() { return v[1]; }
		FORCE_INLINE const T &x() const { return v[0]; }
		FORCE_INLINE const T &y() const { return v[1]; }

		FORCE_INLINE T &operator[](size_t index)
		{
			return v[index];
		}
		FORCE_INLINE const T &operator[](size_t index) const
		{
			return v[index];
		}

		ALGEBRAIC_VEC(vec2, 2)
		VEC_STD_OPS(vec2, 2)
	};

	template <typename T>
	struct quaternion : vec4<T>
	{
		quaternion() : vec4<T>(0, 0, 0, 1) {}

		quaternion(const vec4<T> &v)
		{
			this->v[0] = v.x();
			this->v[1] = v.y();
			this->v[2] = v.z();
			this->v[3] = v.w();
		}

		// NOT axis angle
		quaternion(const vec3<T> &v, T r)
		{
			this->v[0] = v.x();
			this->v[1] = v.y();
			this->v[2] = v.z();
			this->v[3] = r;
		}

		quaternion(T x, T y, T z, T w)
		{
			this->v[0] = x;
			this->v[1] = y;
			this->v[2] = z;
			this->v[3] = w;
		}

		vec3<T> complex() const { return this->xyz(); }
		void complex(const vec3<T> &c)
		{
			this->v[0] = c[0];
			this->v[1] = c[1];
			this->v[2] = c[2];
		}

		T real() const { return this->v[3]; }
		void real(T r) { this->v[3] = r; }

		quaternion conjugate(void) const
		{
			return quaternion(-complex(), real());
		}
		quaternion inverse(void) const
		{
			return conjugate() / this->len();
		}
		quaternion product(const quaternion &rhs) const
		{
			return quaternion(this->y() * rhs.z() - this->z() * rhs.y() + this->x() * rhs.w() + this->w() * rhs.x(),
							  this->z() * rhs.x() - this->x() * rhs.z() + this->y() * rhs.w() + this->w() * rhs.y(),
							  this->x() * rhs.y() - this->y() * rhs.x() + this->z() * rhs.w() + this->w() * rhs.z(),
							  this->w() * rhs.w() - this->x() * rhs.x() - this->y() * rhs.y() - this->z() * rhs.z());
		}
		quaternion operator*(const quaternion &rhs) const
		{
			return product(rhs);
		}
		quaternion operator*(T s) const
		{
			return quaternion(complex() * s, real() * s);
		}
		quaternion operator+(const quaternion &rhs) const
		{
			return quaternion(this->x() + rhs.x(), this->y() + rhs.y(), this->z() + rhs.z(), this->w() + rhs.w());
		}
		quaternion operator-(const quaternion &rhs) const
		{
			return quaternion(this->x() - rhs.x(), this->y() - rhs.y(), this->z() - rhs.z(), this->w() - rhs.w());
		}
		quaternion operator-() const
		{
			return quaternion(-this->x(), -this->y(), -this->z(), -this->w());
		}
		quaternion operator/(T s) const
		{
			if (s == 0)
				return quaternion();
			return quaternion(complex() / s, real() / s);
		}

		void scaled_axis(const vec3<T> &w)
		{
			T theta = w.len();
			if (theta > 0.0001)
			{
				T s = (T)sinf((float)theta / 2.0);
				vec3<T> W(w / theta * s);
				this->v[0] = W[0];
				this->v[1] = W[1];
				this->v[2] = W[2];
				this->v[3] = cos(theta / 2.0);
			}
			else
			{
				this->v[0] = this->v[1] = this->v[2] = 0;
				this->v[3] = 1.0;
			}
		}

		vec3<T> rotated_vec(const vec3<T> &v) const
		{
			return (((*this) * quaternion(v, 0)) * conjugate()).complex();
		}

		void euler(const vec3<T> &euler)
		{
			T c1 = (T)cosf((float)euler.z() * .5f);
			T c2 = (T)cosf((float)euler.y() * .5f);
			T c3 = (T)cosf((float)euler.x() * .5f);
			T s1 = (T)sinf((float)euler.z() * .5f);
			T s2 = (T)sinf((float)euler.y() * .5f);
			T s3 = (T)sinf((float)euler.x() * .5f);

			this->v[0] = c1 * c2 * s3 - s1 * s2 * c3; // x : A
			this->v[1] = c1 * s2 * c3 + s1 * c2 * s3; // y : B
			this->v[2] = s1 * c2 * c3 - c1 * s2 * s3; // z : C
			this->v[3] = c1 * c2 * c3 + s1 * s2 * s3; // w : D
		}

		vec3<T> euler() const
		{
			vec3<T> euler;
			const static double PI_OVER_2 = M_PI * 0.5;
			const static double EPSILON = 1e-10;
			T sqw, sqx, sqy, sqz;

			sqw = this->v[3] * this->v[3];
			sqx = this->v[0] * this->v[0];
			sqy = this->v[1] * this->v[1];
			sqz = this->v[2] * this->v[2];

			euler[1] = (T)asinf(2.f * (float)(this->v[3] * this->v[1] - this->v[0] * this->v[2]));
			if (PI_OVER_2 - fabs(euler[1]) > EPSILON)
			{
				euler[2] = (T)atan2f(2.f * (this->v[0] * this->v[1] + this->v[3] * this->v[2]),
									 sqx - sqy - sqz + sqw);
				euler[0] = (T)atan2f(2.f * (this->v[3] * this->v[0] + this->v[1] * this->v[2]),
									 sqw - sqx - sqy + sqz);
			}
			else
			{
				euler[2] = (T)atan2f(2 * this->v[1] * this->v[2] - 2 * this->v[0] * this->v[3],
									 2 * this->v[0] * this->v[2] + 2 * this->v[1] * this->v[3]);
				euler[0] = 0;
				if (euler[1] < 0)
					euler[2] = M_PI - euler[2];
			}
			return euler;
		}

		static quaternion axis_angle(const vec3<T> &axis, const T angle)
		{
			return quaternion(axis * (T)sinf((float)angle * .5f), (T)cosf((float)angle * .5f));
		}
		static quaternion from_euler(const vec3<T> &eu)
		{
			quaternion ret;
			ret.euler(eu);
			return ret;
		}
		static quaternion from_euler(T x, T y, T z)
		{
			return from_euler(vec3<T>(x, y, z));
		}
	};

	template <typename T = fp_num>
	struct mat4
	{
		T m[4][4] = {0};

		mat4() {}
		mat4(std::initializer_list<std::initializer_list<T>> list)
		{
			size_t r = 0;
			size_t c = 0;
			for (auto row : list)
			{
				for (auto val : row)
				{
					m[r][c] = val;
					if (++c >= 4)
						break;
				}
				c = 0;
				if (++r >= 4)
					break;
			}
		}
		T **to_array()
		{
			T **ret = new T *[4];
			for (size_s i = 0; i < 4; ++i)
			{
				ret[i] = new T[4];
				for (size_s j = 0; j < 4; ++j)
					ret[i][j] = (T)m[i][j];
			}
			return ret;
		}
		static void delete_array(T **arr)
		{
			for (size_s i = 0; i < 4; ++i)
				delete[] arr[i];
			delete[] arr;
		}

		T *operator[](const size_t index)
		{
			return m[index];
		}

		const T *operator[](const size_t index) const
		{
			return m[index];
		}

		mat4 transposed()
		{
			mat4 tmp = *this;
			for (size_t y = 0; y < 4; ++y)
				for (size_t x = 0; x < 4; ++x)
					tmp[y][x] = m[x][y];
			return tmp;
		}

		mat4 &transpose()
		{
			m = transposed().m;
			return *this;
		}

		static mat4 identity()
		{
			return mat4{
				{(T)1, 0, 0, 0},
				{0, (T)1, 0, 0},
				{0, 0, (T)1, 0},
				{0, 0, 0, (T)1}};
		}

		ALGEBRAIC_MAT_SQUARE(mat4, 4)

		static mat4 perspective(T fovDeg, T aspectRatio, T near, T far)
		{
			auto deg_to_rad = [](T deg)
			{
				return deg * (3.14159265 / 180.000);
			};
			T fovRad = (T)1.0 / (T)tanf((float)deg_to_rad(fovDeg * (T)0.5));
			return mat4{{fovRad * aspectRatio, 0, 0, 0},
						{0, fovRad, 0, 0},
						{0, 0, far / (far - near), 1},
						{0, 0, (-far * near) / (far - near), 0}};
		}
		static mat4 orthographic(T left, T right, T bottom, T top, T near = (T)-1, T far = (T)1)
		{
			return mat4{
				{(T)2.0 / (right - left), 0, 0, 0},
				{0, (T)2.0 / (top - bottom), 0, 0},
				{0, 0, -(T)2.0 / (far - near), 0},
				{-(right + left) / (right - left), -(top + bottom) / (top - bottom), -(far + near) / (far - near), (T)1}};
		}
		template <typename E>
		static mat4 look_at_vec_x(const E &pos, const E &target, const E &up)
		{
			E new_forward = (target - pos).normalize();
			E new_up = (up - (new_forward * up.dot(new_forward))).normalize();
			E new_right = new_up.cross(new_forward);
			return mat4{
				{new_right.x(), new_right.y(), new_right.z(), 0},
				{new_up.x(), new_up.y(), new_up.z(), 0},
				{new_forward.x(), new_forward.y(), new_forward.z(), 0},
				{pos.x(), pos.y(), pos.z(), (T)1}};
		}
		FORCE_INLINE static mat4 look_at(const vec3<T> &pos, const vec3<T> &target, const vec3<T> &up)
		{
			return look_at_vec_x<vec3<T>>(pos, target, up);
		}
		FORCE_INLINE static mat4 look_at(const vec4<T> &pos, const vec4<T> &target, const vec4<T> &up)
		{
			return look_at_vec_x<vec3<T>>(pos.xyz(), target.xyz(), up.xyz());
		}
		FORCE_INLINE static mat4 scale(T x, T y, T z)
		{
			return mat4{
				{x, 0, 0, 0},
				{0, y, 0, 0},
				{0, 0, z, 0},
				{0, 0, 0, (T)1}};
		}
		FORCE_INLINE static mat4 scale(vec3<T> s)
		{
			return scale(s.x(), s.y(), s.z());
		}
		FORCE_INLINE static mat4 scale(vec4<T> s)
		{
			return scale(s.x(), s.y(), s.z());
		}
		FORCE_INLINE static mat4 translation(T x, T y, T z)
		{
			return mat4{
				{(T)1, 0, 0, 0},
				{0, (T)1, 0, 0},
				{0, 0, (T)1, 0},
				{x, y, z, (T)1}};
		}
		FORCE_INLINE static mat4 translation(vec4<T> t)
		{
			return translation(t.x(), t.y(), t.z());
		}
		FORCE_INLINE static mat4 translation(vec3<T> t)
		{
			return translation(t.x(), t.y(), t.z());
		}
		FORCE_INLINE static mat4 x_rotation(T x)
		{
			return mat4{
				{(T)1, 0, 0, 0},
				{0, (T)cosf(x), (T)sinf(x), 0},
				{0, (T)-sinf(x), (T)cosf(x), 0},
				{0, 0, 0, (T)1}};
		}
		FORCE_INLINE static mat4 y_rotation(T y)
		{
			return mat4{
				{(T)cosf(y), 0, (T)sinf(y), 0},
				{0, 1, 0, 0},
				{(T)-sinf(y), 0, (T)cosf(y), 0},
				{0, 0, 0, 1}};
		}
		FORCE_INLINE static mat4 z_rotation(T z)
		{
			return mat4{
				{(T)cosf(z), (T)sinf(z), 0, 0},
				{(T)-sinf(z), (T)cosf(z), 0, 0},
				{0, 0, (T)1, 0},
				{0, 0, 0, (T)1}};
		}
		FORCE_INLINE static mat4 rotation(T x, T y, T z)
		{
			return x_rotation(x) * y_rotation(y) * z_rotation(z);
		}
		FORCE_INLINE static mat4 rotation(vec3<T> r)
		{
			return rotation(r.x(), r.y(), r.z());
		}
		FORCE_INLINE static mat4 rotation(quaternion<T> q)
		{
			q.normalize();
			return mat4{
				{1 - 2 * q.y() * q.y() - 2 * q.z() * q.z(), 2 * q.x() * q.y() - 2 * q.z() * q.w(), 2 * q.x() * q.z() + 2 * q.y() * q.w(), 0},
				{2 * q.x() * q.y() + 2 * q.z() * q.w(), 1 - 2 * q.x() * q.x() - 2 * q.z() * q.z(), 2 * q.y() * q.z() - 2 * q.x() * q.w(), 0},
				{2 * q.x() * q.z() - 2 * q.y() * q.w(), 2 * q.y() * q.z() + 2 * q.x() * q.w(), 1 - 2 * q.x() * q.x() - 2 * q.y() * q.y(), 0},
				{0, 0, 0, 1}};
		}
	};

	template <typename T = fp_num>
	struct mat3
	{
		T m[3][3] = {0};

		mat3() {}
		mat3(std::initializer_list<std::initializer_list<T>> list)
		{
			size_t r = 0;
			size_t c = 0;
			for (auto row : list)
			{
				for (auto val : row)
				{
					m[r][c] = val;
					if (++c >= 3)
						break;
				}
				c = 0;
				if (++r >= 3)
					break;
			}
		}

		T *operator[](const size_t index)
		{
			return m[index];
		}

		const T *operator[](const size_t index) const
		{
			return m[index];
		}

		static mat3 identity()
		{
			return mat3{
				{(T)1, 0, 0},
				{0, (T)1, 0},
				{0, 0, (T)1}};
		}

		ALGEBRAIC_MAT_SQUARE(mat3, 3)
	};

	template <typename T = fp_num>
	struct mat2
	{
		T m[2][2] = {0};

		mat2() {}
		mat2(std::initializer_list<std::initializer_list<T>> list)
		{
			size_t r = 0;
			size_t c = 0;
			for (auto row : list)
			{
				for (auto val : row)
				{
					m[r][c] = val;
					if (++c >= 2)
						break;
				}
				c = 0;
				if (++r >= 2)
					break;
			}
		}

		T *operator[](const size_t index)
		{
			return m[index];
		}

		const T *operator[](const size_t index) const
		{
			return m[index];
		}

		static mat2 identity()
		{
			return mat2{
				{(T)1, 0}, {0, (T)1}};
		}

		ALGEBRAIC_MAT_SQUARE(mat2, 2)

		FORCE_INLINE static mat2 rotation(T v)
		{
			return mat2{
				{(T)cosf(v), (T)sinf(v)},
				{(T)-sinf(v), (T)cosf(v)}};
		}

		FORCE_INLINE static mat2 scale(T x, T y)
		{
			return mat2{{x, 0}, {0, y}};
		}
		FORCE_INLINE static mat2 scale(vec2<T> s)
		{
			return scale(s.x(), s.y());
		}
	};
}
namespace galg
{
	enum class str_fmt
	{
		algebraic,
		array,
		list,
		inline_array,
		bare
	};
	struct str_fmt_group
	{
		const char open[2];
		const char close[2];
		const char seper[2];
		const char newline[2];
		str_fmt_group(const char op, const char cl, const char br, const char nl) : open{op, '\0'}, close{cl, '\0'}, seper{br, '\0'}, newline{nl, '\0'} {}
	};
	str_fmt_group enclosing_chars(str_fmt fmt)
	{
		switch (fmt)
		{
		case str_fmt::algebraic:
			return str_fmt_group('|', '|', ' ', '\n');
		case str_fmt::array:
			return str_fmt_group('{', '}', ',', '\n');
		case str_fmt::list:
			return str_fmt_group('(', ')', ',', '\n');
		case str_fmt::inline_array:
			return str_fmt_group('{', '}', ',', ' ');
		case str_fmt::bare:
			return str_fmt_group(' ', ' ', ' ', '\n');
		}
		return str_fmt_group('?', '?', '?', '?');
	}
	template <typename T>
	std::string to_string(const vec4<T> &vec, str_fmt fmt = str_fmt::array)
	{
		auto ech = enclosing_chars(fmt);
		std::string ret(ech.open);
		for (size_s i = 0; i < 4; ++i)
			ret.append(std::to_string(vec[i])).append(i == 3 ? ech.close : ech.seper);
		return ret;
	}
	template <typename T>
	std::string to_string(const vec3<T> &vec, str_fmt fmt = str_fmt::array)
	{
		auto ech = enclosing_chars(fmt);
		std::string ret(ech.open);
		for (size_s i = 0; i < 3; ++i)
			ret.append(std::to_string(vec[i])).append(i == 2 ? ech.close : ech.seper);
		return ret;
	}
	template <typename T>
	std::string to_string(const vec2<T> &vec, str_fmt fmt = str_fmt::array)
	{
		auto ech = enclosing_chars(fmt);
		return std::string(ech.open).append(std::to_string(vec.x())).append(ech.seper).append(std::to_string(vec.y())).append(ech.close);
	}
	template <typename mat_x, size_s nelems>
	std::string to_string_mat_x(const mat_x &m, str_fmt fmt = str_fmt::array)
	{
		auto ech = enclosing_chars(fmt);
		std::string ret;
		for (size_s i = 0; i < nelems; ++i)
		{
			ret.append(ech.open);
			for (size_s j = 0; j < nelems; ++j)
			{
				ret.append(std::to_string(m[i][j]));
				if (j == nelems - 1)
				{
					if (i == nelems - 1)
						ret.append(ech.close);
					else
						ret.append(ech.close).append(ech.seper).append(ech.newline);
				}
				else
					ret.append(ech.seper);
			}
		}
		return ret;
	}
	template <typename T>
	std::string to_string(const mat2<T> &m, str_fmt fmt = str_fmt::array)
	{
		return to_string_mat_x<mat2<T>, 2>(m, fmt);
	}
	template <typename T>
	std::string to_string(const mat3<T> &m, str_fmt fmt = str_fmt::array)
	{
		return to_string_mat_x<mat3<T>, 3>(m, fmt);
	}
	template <typename T>
	std::string to_string(const mat4<T> &m, str_fmt fmt = str_fmt::array)
	{
		return to_string_mat_x<mat4<T>, 4>(m, fmt);
	}
	std::string to_string(bool b)
	{
		return std::string(b ? "true" : "false");
	}
}

#define COUNT_ALLOCS                \
	size_t allocs = 0;              \
	void *operator new(size_t size) \
	{                               \
		++allocs;                   \
		return malloc(size);        \
	}

// Counts frees into a variable called 'deletes'.
#define COUNT_DELETES               \
	size_t deletes = 0;             \
	void operator delete(void *ptr) \
	{                               \
		++deletes;                  \
		free(ptr);                  \
	}

// Counts allocs and frees into variables called 'allocs' and 'deletes' respectively.
#define COUNT_MEMORY \
	COUNT_ALLOCS     \
	COUNT_DELETES

// Prints the number of allocations.
#define PRINT_ALLOCS \
	std::cout        \
		<< "Allocations: " << allocs << std::endl;

// Prints the number of frees.
#define PRINT_DELETES \
	std::cout         \
		<< "Deletes: " << deletes << std::endl;

// Prints the number of allocations and frees.
#define PRINT_MEMORY_SUMMARY                 \
	std::cout                                \
		<< "Allocs: " << allocs << std::endl \
		<< "Deletes: " << deletes << std::endl;

#define DEL_PTR(ptr)   \
	if (ptr)           \
	{                  \
		delete ptr;    \
		ptr = nullptr; \
	}

#define DEL_ARR_PTR(ptr) \
	if (ptr)             \
	{                    \
		delete[] ptr;    \
		ptr = nullptr;   \
	}

#ifdef _WIN32
std::string R_PATH(const char *str)
{
	return std::string("../").append(std::string(str));
}
#else
std::string R_PATH(const char *str)
{
	return std::string(str);
}
#endif

#define RESOURCE(X) \
	R_PATH(X).c_str()

using namespace galg;
namespace kvasir
{
	struct position3d
	{
		vec3f pos;
		quaternionf rot = quaternionf::axis_angle(vec3f(0, 1, 0), 0);
		vec3f scale = vec3f(1, 1, 1);
		vec3f rot_pt;
	};

	struct position2d
	{
		vec2f pos;
		float rot;
		vec2f scale = galg::vec2f(1, 1);
		vec2f rot_pt;
	};
}

namespace kvasir
{
	struct frame_manager
	{
		bool next_frame_ready();
		void set_fps(double fps);
		float delta() const;
		double delta_d() const;
		static inline double clock_to_sec(const clock_t clock);

	private:
		clock_t last_frame = clock();
		double delta_time;
		double desired_delta = 1.0 / 60;
	};
}

namespace kvasir
{

	struct buffer_base
	{
		virtual ~buffer_base() = 0;
		virtual void gen_buffer() = 0;
		virtual void set_data(void *data, size_t len, bool change_often = false) = 0;
		virtual void sub_data(void *data, size_t offset, size_t len) = 0;
		virtual void get_data(void *recv, size_t offset, size_t len) = 0;
		virtual void attrib_ptr(size_t ptr_num, size_t size, size_t step = 0, size_t offset = 0) = 0;
		virtual void bind_buffer() = 0;
		virtual void bind_vao() = 0;
		virtual void free_buffer() = 0;
	};

}

namespace kvasir
{
	struct render_buffer
	{
		virtual ~render_buffer() = 0;
		virtual bool set_size(size_t width, size_t height) = 0;
		virtual void bind() = 0;
		virtual int get_width() = 0;
		virtual int get_height() = 0;
	};
}

namespace kvasir
{

	struct texture_image
	{
		std::vector<unsigned char> pixels; // RGBA
		unsigned w;						   // width
		unsigned h;						   // height

		long pixel_rgb(size_t x, size_t y);
		long pixel_rgb(const galg::vec2f &uv);
	};

	struct texture_base
	{
		virtual ~texture_base() = 0;
		virtual void bind() = 0;
		virtual void gen_texture() = 0;
		virtual void set_slot(size_t slot) = 0;
		virtual void set_texture(const texture_image &img) = 0;
		virtual void free_texture() = 0;
		void make(const texture_image &tex, size_t slot = 0);
		void make_png(const char *path, size_t slot = 0);
		void make_colour(long colour, size_t slot = 0);
		static texture_image load_image(const char *file_path);
		static texture_image colour_image(long colour);

		static inline std::unordered_map<std::string, texture_image> image_cache;
		static inline bool use_image_cache = true;
	};

}
namespace kvasir
{
	struct material_base
	{
		~material_base();
		std::vector<texture_base *> texs{nullptr, nullptr, nullptr, nullptr};
		texture_base *&diffuse();
		texture_base *&specular();
		texture_base *&normal();
		texture_base *&parallax();
		texture_base *&operator[](size_t index);
		void bind();
	};
}

namespace kvasir
{

	struct mesh3d : position3d
	{
		struct triangle
		{
			struct vert
			{
				vec3f p; // Vertex pos
				vec2f t; // Vertex UV
				vec3f n; // Vertex normal
			};

			vert v[3]; // Verteces in the triangle

			triangle();
			triangle(vec3f &p1, vec3f &p2, vec3f &p3);
		};

		material_base *material = nullptr;
		buffer_base *buffer = nullptr;
		size_t n_tris = 0;
		const size_t tag;

		mesh3d();
		~mesh3d();
		bool load_from_obj(const char *file_name, buffer_base *buf);
		void vertex_pos(const vec3f &pos);
		void vertex_rot(const quaternionf &rot);
		void vertex_scale(const vec3f &scale);

		inline static bool use_geo_val_cache = true;
		inline static std::unordered_map<std::string, std::vector<triangle>> geo_val_cache;
		static std::vector<triangle> obj_to_tri_array(const char *file);
		static std::vector<triangle> check_val_cache(const std::string &file);

	private:
		inline static size_t current_tag = 0;
	};

	struct group_mesh3d : mesh3d
	{
		std::vector<size_t> t_n_tris;
		bool load_from_objs(std::vector<const char *> files, buffer_base *buf);
		void add_mesh_pos(size_t index, const vec3f &pos);
		void add_mesh_scale(size_t index, const vec3f &scale);
		void add_mesh_rot(size_t index, const quaternionf &rot);
	};

	struct mesh2d : position2d
	{
		struct triangle
		{
			struct vert
			{
				vec2f p; // Vertex pos
				vec2f t; // Vertex UV
			};

			vert v[3]; // Vertecies in the triangle
		};

		buffer_base *buffer = nullptr;
		material_base *material = nullptr;
		size_t n_tris = 0;

		mesh2d();
		~mesh2d();
		bool make_quad(const vec2f &size, buffer_base *buf);
	};
};

namespace kvasir
{

	struct physics3d
	{
		struct phys_props
		{
			float mass = 0;
			float friction = 1.f;
			float restitution = 0;
			phys_props(float mass = 0, float friction = 1.f, float rest = 0);
		};
		static phys_props static_props(float friction = 1.f, float restitution = 0);
		static phys_props dynamic_props(float mass, float friction = 1.f, float restitution = 0);

		virtual ~physics3d() = 0;
		virtual void add_mesh(mesh3d &mesh, bool convex, const phys_props &props) = 0;
		virtual void add_mesh_sphere_hitbox(mesh3d &mesh, float diameter, const phys_props &props) = 0;
		virtual void add_mesh_box_hitbox(mesh3d &mesh, vec3f size, const phys_props &props) = 0;
		virtual void add_central_force(const mesh3d &mesh, vec3f force) = 0;
		virtual void add_mesh_prefab_hitbox(mesh3d &mesh, std::string key, const phys_props &props) = 0;
		virtual void set_gravity(const vec3f &g) = 0;
		virtual void step(float delta_seconds) = 0;
		virtual vec3f get_position(const mesh3d &mesh) = 0;
		virtual quaternionf get_rotation(const mesh3d &mesh) = 0;
		virtual void set_position(const mesh3d &mesh, const vec3f &v) = 0;
		virtual void set_rotation(const mesh3d &mesh, const quaternionf &v) = 0;
		virtual position3d get_transform(const mesh3d &mesh) = 0;
		virtual void set_transform(const mesh3d &mesh, const position3d &trns) = 0;
		virtual void create_mesh_hitbox_prefab(mesh3d &mesh, std::string key, bool convex) = 0;
		virtual void activate(const mesh3d &mesh) = 0;
		virtual mesh3d *raycast_first_hit(vec3f from, vec3f to) = 0;
		virtual void set_rotation_axes(const mesh3d &mesh, vec3f axes) = 0;
		virtual void set_position_axes(const mesh3d &mesh, vec3f axes) = 0;
		virtual vec3f get_velocity(const mesh3d &mesh) = 0;
		virtual vec3f get_angular_velocity(const mesh3d &mesh) = 0;
		virtual void set_velocity(const mesh3d &mesh, const vec3f &lv) = 0;
		virtual void set_angular_velocity(const mesh3d &mesh, const vec3f &lv) = 0;
		virtual float get_mass(const mesh3d &mesh) = 0;
	};

	struct physics2d
	{
		// TODO
	};

}
namespace kvasir
{

	struct camera3d
	{
		float fov = 75.f;
		float near = 0.1f;
		float far = 100.f;
		float aspect = 1.f;

		vec3f pos;
		vec3f rot;

		mat4f view();
		mat4f perspective();
		vec4f look_vector();
	};

	struct camera2d : position2d
	{
		float aspect = 1.f;
	};

}
namespace kvasir
{
	enum key
	{
		Unknown = -1,
		KeyA,
		KeyB,
		KeyC,
		KeyD,
		KeyE,
		KeyF,
		KeyG,
		KeyH,
		KeyI,
		KeyJ,
		KeyK,
		KeyL,
		KeyM,
		KeyN,
		KeyO,
		KeyP,
		KeyQ,
		KeyR,
		KeyS,
		KeyT,
		KeyU,
		KeyV,
		KeyW,
		KeyX,
		KeyY,
		KeyZ,
		Num0,
		Num1,
		Num2,
		Num3,
		Num4,
		Num5,
		Num6,
		Num7,
		Num8,
		Num9,
		Escape,
		LControl,
		LShift,
		LAlt,
		LSystem,
		RControl,
		RShift,
		RAlt,
		RSystem,
		Menu,
		LBracket,
		RBracket,
		Semicolon,
		Comma,
		Period,
		Quote,
		Slash,
		Backslash,
		Tilde,
		Equal,
		Hyphen,
		Space,
		Enter,
		Backspace,
		Tab,
		PageUp,
		PageDown,
		End,
		Home,
		Insert,
		Delete,
		Add,
		Subtract,
		Multiply,
		Divide,
		Left,
		Right,
		Up,
		Down,
		Numpad0,
		Numpad1,
		Numpad2,
		Numpad3,
		Numpad4,
		Numpad5,
		Numpad6,
		Numpad7,
		Numpad8,
		Numpad9,
		F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12,
		F13,
		F14,
		F15,
		Pause,
		CapsLock,
		ScrollLock,
		NumLock,
		PrintScreen,
		KeyCount,
		Dash = Hyphen,
		BackSpace = Backspace,
		BackSlash = Backslash,
		SemiColon = Semicolon,
		Return = Enter
	};
	enum keystate
	{
		Release,
		Press,
		Repeat,
		KeyUp = Release,
		KeyDown = Press,
		KeyHeld = Repeat,
		NoPress = -1,
		Stateless = NoPress,
		NoAction = NoPress
	};
	struct key_event
	{
		key k = Unknown;
		keystate action = NoPress;
	};
	struct input
	{
		static key get_glfw_key(int glk);
		static keystate get_glfw_kst(int kst);
		static int get_key(key k);
		static int get_kst(keystate kst);
	};

}
namespace kvasir
{

	struct shader_base
	{
		virtual ~shader_base() = 0;
		virtual void use() = 0;
		virtual bool compile(const char **srcs, size_t n_srcs) = 0;
		virtual void u_bool1(const char *name, bool a) = 0;
		virtual void u_bool2(const char *name, bool a, bool b) = 0;
		virtual void u_bool3(const char *name, bool a, bool b, bool c) = 0;
		virtual void u_bool4(const char *name, bool a, bool b, bool c, bool d) = 0;
		virtual void u_int1(const char *name, int a) = 0;
		virtual void u_int2(const char *name, int a, int b) = 0;
		virtual void u_int3(const char *name, int a, int b, int c) = 0;
		virtual void u_int4(const char *name, int a, int b, int c, int d) = 0;
		virtual void u_float1(const char *name, float a) = 0;
		virtual void u_float2(const char *name, float a, float b) = 0;
		virtual void u_float3(const char *name, float a, float b, float c) = 0;
		virtual void u_float4(const char *name, float a, float b, float c, float d) = 0;
		virtual void u_mat2f(const char *name, float m[2][2]) = 0;
		virtual void u_mat3f(const char *name, float m[3][3]) = 0;
		virtual void u_mat4f(const char *name, float m[4][4]) = 0;
		virtual void render(int) = 0;
		virtual void free_shader() = 0;

		void bind_material(material_base *base);
	};

}

namespace kvasir
{
	struct render_base
	{
		enum type
		{
			OPENGL = 0x01,
			VULKAN = 0x02,
			TERMINAL = 0x04,
			DIRECTX = 0x08,
		};

		virtual ~render_base() = 0;

		virtual bool should_close() = 0;
		virtual void set_clear_colour(long c) = 0;
		virtual void clear() = 0;
		virtual void swap_buffers() = 0;
		virtual void poll_events() = 0;
		virtual void set_position(int x, int y) = 0;
		virtual void get_position(int *x, int *y) = 0;
		virtual void get_size(int *w, int *h) = 0;
		virtual void set_size(int w, int h) = 0;
		virtual void set_title(const char *n) = 0;
		virtual bool is_fullscreen() = 0;
		virtual bool set_fullscreen() = 0;
		virtual bool set_windowed() = 0;
		virtual bool set_resizable(bool b) = 0;
		virtual bool is_resizable() = 0;
		virtual bool set_visible(bool visible) = 0;
		virtual bool is_visible() = 0;
		virtual bool init(const char *n, int w, int h) = 0;
		virtual void destroy() = 0;
		virtual buffer_base *make_buffer();
		virtual shader_base *make_shader();
		virtual texture_base *make_texture();
		virtual material_base *make_material();
		virtual render_buffer *make_render_buffer();
		virtual void render_mesh3d(camera3d &c, mesh3d &m, shader_base *s, render_buffer *buff = nullptr);
		virtual void render_mesh2d(camera2d &c, mesh2d &m, shader_base *s, render_buffer *buff = nullptr);
		virtual void depth_buffer_active(bool b) = 0;
		virtual type get_type() = 0;
		virtual keystate get_keystate(key k) = 0;

		int get_position_x();
		int get_position_y();
		int get_width();
		int get_height();
		void set_width(int w);
		void set_height(int h);
		double get_aspect();
		bool key_pressed(key k);

		static const char *type_to_string(type t);
	};

};

namespace kvasir
{
	void cam_debug_controls(render_base *base, camera3d &cam, float delta, float mv_speed = 3.f, float rot_speed = 1.4f, float spb1 = 3.f, float spb2 = 7.f);
	void cam_debug_rotation(render_base *base, camera3d &cam, float delta, float rot_speed = 1.4f);
	material_base *make_material(render_base *base, const char *diffuse_img_path);
	material_base *make_material(render_base *base, long diffuse_colour);

}
namespace kvasir
{

	bool kvasir_init();

	struct linkverify
	{
		void verify_link();
	};

	struct kvasir_engine
	{
		frame_manager time;
		frame_manager fixed_time;
		render_base *base = nullptr;
		enum result
		{
			NO_ERROR = 0,
			NULL_BASE = 1,
			BASE_INIT_FAIL = 2,
			ON_START_RET_FALSE = 4
		};

		struct user_result
		{
			user_result(const char *m, bool f = true);
			const char *msg = nullptr;
			bool fatal = true;
			static user_result ok();
		};

		~kvasir_engine();
		result start(std::vector<render_base::type> t_bases, const char *name = "Kvasir", int wid = 480, int hei = 480);
		result start(render_base::type t_base, const char *name = "Kvasir", int wid = 480, int hei = 480);
		virtual user_result on_start() = 0;
		virtual void on_update() = 0;
		virtual void on_fixed_update() = 0;
		virtual void on_close() = 0;
		static render_base *get_base(render_base::type b);

		static physics3d *default_physics3d();

	private:
		result start_with_base();
	};
}

#endif