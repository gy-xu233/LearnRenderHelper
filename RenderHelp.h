#ifndef _RENDERHELP_H_
#define _RENDERHELP_H_

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include <vector>
#include <map>
#include <initializer_list>
#include <stdexcept>
#include <functional>
#include <ostream>
#include <sstream>
#include <iostream>

template <size_t N, typename T> struct Vector
{
	T m[N];
	//-------------
public:
	Vector()
	{
		for (size_t i = 0; i<N; i++)
			m[i] = T();
	}
	//~Vector();
	Vector(const T *yy)
	{
		for (size_t i = 0; i<N; i++)
			//m[i] = yy();
			m[i] = yy[i];
	}
	Vector(const std::initializer_list<T> &u)
	{
		auto it = u.begin();
		for (size_t i = 0; i < N; i++)
			m[i] = *it++;
	}
	//-------------
	const T& operator[] (size_t i) const { assert(i < N); return m[i]; }
	T& operator[] (size_t i) { assert(i < N); return m[i]; }

	void load(const T *yy) { for (size_t i = 0; i < N; i++) m[i] = yy[i]; }
	void save(T *yy) { for (size_t i = 0; i < N; i++) yy[i] = m[i]; }

};

template<typename T> struct Vector<2, T>
{
	union
	{
		struct { T x, y; };
		struct { T u, v; };
		T m[2];
	};
	Vector():x(T()),y(T()){}
	Vector(T _x, T _y):x(_x),y(_y){}
	Vector(const Vector<2,T> &a):x(a.m[0]),y(a.m[1]){}
	Vector(const T *ptr):x(ptr[0]),y(ptr[1]){}
	T& operator [](size_t i) { assert(i < 2); return m[i]; }
	const T operator [] (size_t i) const { assert(i < 2); return m[i]; }
	void load(const T *ptr) {
		for (size_t i = 0; i < 2; i++)
		{
			m[i] = ptr[i];
		}
	}
	void save(T *ptr) {
		for (size_t i = 0; i < 2; i++)
		{
			ptr[i] = m[i];
		}
	}
	Vector<3, T> xy1()const { return Vector<3, T>(x, y, 1); }
	Vector<4, T> xy11()const { return Vector<4, T>(x, y, 1, 1); }
	Vector<2, T> xy()const { return *this; }
};

template<typename T> struct Vector<3, T>
{
	union
	{
		struct { T x, y, z; };
		struct { T r, g, b; };
		T m[3];
	};
	Vector() :x(T()), y(T()),z(T()) {}
	Vector(T _x, T _y, T _z) :x(_x), y(_y), z(_z) {}
	Vector(const Vector<3, T> &a) :x(a.m[0]), y(a.m[1]),z(a.m[2]) {}
	Vector(const T *ptr) :x(ptr[0]), y(ptr[1]),z(ptr[2]) {}
	T& operator [](size_t i) { assert(i < 3); return m[i]; }
	const T operator [] (size_t i) const { assert(i < 3); return m[i]; }
	void load(const T *ptr) {
		for (size_t i = 0; i < 3; i++)
		{
			m[i] = ptr[i];
		}
	}
	void save(T *ptr) {
		for (size_t i = 0; i < 3; i++)
		{
			ptr[i] = m[i];
		}
	}
	Vector<3, T> xyz()const { return *this; }
	Vector<4, T> xyz1()const { return Vector<4, T>(x, y, z, 1); }
	Vector<2, T> xy()const { return Vector<2,T>(x,y); }
};

template<typename T> struct Vector<4, T>
{
	union
	{
		struct { T x, y, z, w; };
		struct { T r, g, b, a; };
		T m[4];
	};
	Vector() :x(T()), y(T()), z(T()), w(T()) {}
	Vector(T _x, T _y, T _z, T _w) :x(_x), y(_y), z(_z),w(_w) {}
	Vector(const Vector<4, T> &a) :x(a.m[0]), y(a.m[1]), z(a.m[2]),w(a.m[3]) {}
	Vector(const T *ptr) :x(ptr[0]), y(ptr[1]), z(ptr[2]),w(ptr[3]) {}
	T& operator [](size_t i) { assert(i < 4); return m[i]; }
	const T operator [] (size_t i) const { assert(i < 4); return m[i]; }
	void load(const T *ptr) {
		for (size_t i = 0; i < 4; i++)
		{
			m[i] = ptr[i];
		}
	}
	void save(T *ptr) {
		for (size_t i = 0; i < 4; i++)
		{
			ptr[i] = m[i];
		}
	}
	Vector<3, T> xyz()const { return Vector<3,T>(x,y,z); }
	Vector<4, T> xyzw()const { return *this; }
	Vector<2, T> xy()const { return Vector<2, T>(x, y); }
};

template<size_t N, typename T>
inline std::ostream& operator << (std::ostream &os, const Vector<N, T> &v)
{
	if (N == 0)
		return os;
	os << "("<<v[0];
	for (size_t i = 1; i < N; i++)
	{
		os << ","<<v[i];
	}
	os << ")";
	return os;
}

template<size_t N, typename T>
inline Vector<N, T> operator+(const Vector<N, T> &v) { return v; }

template<size_t N, typename T>
inline Vector<N, T> operator-(const Vector<N, T> &v1)
{
	Vector<N, T> v;
	for (size_t i = 0; i < N; i++)
	{
		v[i] = v1[i] * -1;
	}
	return v;
}

template<size_t N, typename T>
inline Vector<N, T> operator+(const Vector<N, T> &v1, const Vector<N,T> &v2)
{
	Vector<N, T> v;
	for (size_t i = 0; i < N; i++)
	{
		v[i] = v1[i] + v2[i];
	}
	return v;
}

template<size_t N, typename T>
inline Vector<N, T> operator-(const Vector<N, T> &v1, const Vector<N, T> &v2)
{
	Vector<N, T> v;
	for (size_t i = 0; i < N; i++)
	{
		v[i] = v1[i] - v2[i];
	}
	return v;
}

template<size_t N1,size_t N2, typename T>
inline bool operator==(const Vector<N1, T> &v1, const Vector<N2, T> &v2)
{
	if (N1 != N2)
		return false;
	for (size_t i = 0; i < N1; i++)
	{
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

template<size_t N1, size_t N2, typename T>
inline bool operator!=(const Vector<N1, T> &v1, const Vector<N2, T> &v2)
{
	return !(v1 == v2);
}

template<size_t N, typename T>
inline Vector<N, T> operator*(const Vector<N, T> &v1, const Vector<N, T> &v2)
{
	Vector<N, T> v;
	for (size_t i = 0; i < N; i++)
	{
		v[i] = v1[i] * v2[i];
	}
	return v;
}

template<size_t N, typename T>
inline Vector<N, T> operator/(const Vector<N, T> &v1, const Vector<N, T> &v2)
{
	Vector<N, T> v;
	for (size_t i = 0; i < N; i++)
	{
		v[i] = v1[i] / v2[i];
	}
	return v;
}

template<size_t N, typename T>
inline Vector<N, T>& operator+=(Vector<N, T> &v1, const Vector<N, T> &v2)
{
	for (size_t i = 0; i < N; i++)
	{
		v1[i] += v2[i];
	}
	return v1;
}

template<size_t N, typename T>
inline Vector<N, T>& operator-=(Vector<N, T> &v1, const Vector<N, T> &v2)
{
	for (size_t i = 0; i < N; i++)
	{
		v1[i] -= v2[i];
	}
	return v1;
}

template<size_t N, typename T>
inline Vector<N, T> operator*(const Vector<N, T> &v1, const T &t)
{
	Vector<N, T> v;
	for (size_t i = 0; i < N; i++)
	{
		v[i] = v1[i] * t;
	}
	return v;
}

template<size_t N, typename T>
inline Vector<N, T> operator*(const T &t, const Vector<N, T> &v1)
{
	Vector<N, T> v;
	for (size_t i = 0; i < N; i++)
	{
		v[i] = v1[i] * t;
	}
	return v;
}

template<size_t N, typename T>
inline Vector<N, T> operator/(const Vector<N, T> &v1, const T &t)
{
	Vector<N, T> v;
	for (size_t i = 0; i < N; i++)
	{
		v[i] = v1[i] / t;
	}
	return v;
}

template<size_t N, typename T>
inline Vector<N, T> operator/(const T &t, const Vector<N, T> &v1)
{
	Vector<N, T> v;
	for (size_t i = 0; i < N; i++)
	{
		v[i] = t / v1[i];
	}
	return v;
}

#endif // !_RENDERHELP_H


