#ifndef PPHYSVECTOR_H
#define PPHYSVECTOR_H

#include <math.h>

namespace pPhys {

#define DEFINE_USING_BASECLASS \
	using BaseClass::operator ==;\
	using BaseClass::operator !=;\
	using BaseClass::operator =;\
	using BaseClass::operator -;\
	using BaseClass::operator +;\
	using BaseClass::operator *;\
	using BaseClass::operator /;\
	using BaseClass::operator +=;\
	using BaseClass::operator -=;

	template <typename T, unsigned N>
	class VectorData
	{
	public:
		typedef T Type;
		typedef T ArrayType[N];

	public:
		ArrayType v;
	};

	template <typename T>
	class VectorData<T, 2>
	{
	public:
		typedef T Type;
		typedef T ArrayType[2];

	public:
		union
		{
			struct { Type x, y; };
			ArrayType v;
		};
	};

	template <typename T>
	class VectorData < T, 3 >
	{
	public:
		typedef T Type;
		typedef T ArrayType[3];

	public:
		union
		{
			struct { Type x, y, z; };
			struct { Type r, g, b; };
			ArrayType v;
		};
	};

	template <typename T>
	class VectorData<T, 4>
	{
	public:
		typedef T Type;
		typedef T ArrayType[4];

	public:
		union
		{
			struct { Type x, y, z, w ;};
			struct { Type r, g, b, a ;};
			ArrayType v;
		};
	};

	template <typename T, typename FinalT, unsigned N>
	class VectorBase : public VectorData<T, N>
	{
	private:
		typedef VectorData<T, N> BaseClass;
		using typename BaseClass::Type;
		using BaseClass::v;

	public:
		using typename BaseClass::ArrayType;

		// Default constructor
		VectorBase()
		{
			for (unsigned i = 0; i < N; ++i)
				v[i] = typename BaseClass::Type(0);
		}

		// Copy constructor
		VectorBase(const VectorBase &other)
		{
			for (unsigned i = 0; i < N; ++i)
				v[i] = other.v[i];
		}

		VectorBase(const typename BaseClass::ArrayType &array)
		{
			for (unsigned i = 0; i < N; ++i)
				v[i] = array[i];
		}

		VectorBase(const FinalT &other)
		{
			for (unsigned i = 0; i < N; ++i)
				v[i] = other[i];
		}

		//equals operator
#ifdef OS_WINDOWS
		inline const FinalT &operator = (const FinalT &src)
		{
			for (unsigned i = 0; i < N; ++i)
				v[i] = src.v[i];
			return (*this);
		}
#endif

		inline const FinalT operator - () const
		{
			FinalT ret;
			for (unsigned i = 0; i < N; ++i)
				ret.v[i] = -v[i];

			return ret;
		}

		//Type from vector to vector
		inline typename BaseClass::Type operator * (const FinalT &src) const
		{
			typename BaseClass::Type dot = typename BaseClass::Type(0);

			for (unsigned i = 0; i < N; ++i)
				dot += v[i] * src.v[i];

			return dot;
		}

		//Vector to Vector operators
		inline FinalT operator + (const FinalT &src)
		{
			FinalT out = src;
			for (unsigned i = 0; i < N; ++i)
				out.v[i] += v[i];
			return out;
		}

		inline FinalT operator - (const FinalT &src)
		{
			FinalT out = src;
			for (unsigned i = 0; i < N; ++i)
				out.v[i] -= v[i];
			return out;
		}

		/*
		inline FinalT operator * (const FinalT &src)
		{
			FinalT out(*this);
			out *= src;
			return out;
		}
		*/

		inline void operator += (const FinalT &src)
		{
			for (unsigned i = 0; i < N; ++i)
				v[i] += src.v[i];
		}

		inline void operator -= (const FinalT &src)
		{
			for (unsigned i = 0; i < N; ++i)
				v[i] -= src.v[i];
		}

		//Type to vector operators
		inline FinalT operator / (typename BaseClass::Type src) const
		{
			FinalT out = *(FinalT *)this;
			return out /= src, out;
		}

		inline FinalT operator * (typename BaseClass::Type src) const
		{
			FinalT out = *(FinalT *)this;
			return out *= src, out;
		}


		inline void operator /= (typename BaseClass::Type src)
		{
			for (unsigned i = 0; i < N; ++i)
				v[i] /= src;
		}

		inline void operator *= (typename BaseClass::Type src)
		{
			for (unsigned i = 0; i < N; ++i)
				v[i] *= src;
		}

		//Comparing functions
		inline bool operator == (const FinalT &src) const
		{
			for (unsigned i = 0; i < N; ++i)
			{
				if (v[i] != src[i])
					return false;
			}

			return true;
		}

		inline bool operator != (const FinalT &src) const
		{
			if (this == src)
				return false;
			return true;
		}

		//Vector functions
		inline typename BaseClass::Type getSquareLenght() const
		{
			typename BaseClass::Type ret = typename BaseClass::Type();

			for (unsigned i = 0; i < N; ++i)
				ret += v[i] * v[i];

			return ret;
		}

		inline typename BaseClass::Type getLenght()
		{
			return std::sqrt(getSquareLenght());
		}

		inline void normalize()
		{
			*this /= getLenght();
		}

		// Dot product
		inline typename BaseClass::Type getDotProduct(const FinalT &other) const
		{
			typename BaseClass::Type ret = typename BaseClass::Type();
			for (size_t i = 0; i < N; ++i)
				ret += v[i] * other.v[i];

			return ret;
		}
	};


	//General Implementation
	template <typename T, unsigned N>
	class Vector : public VectorBase<T, Vector<T, N>, N>
	{
	public:
		typedef VectorBase<T, Vector<T, N>, N> BaseClass;
		using typename BaseClass::ArrayType;

	public:
		DEFINE_USING_BASECLASS;

		Vector()
			: BaseClass()
		{}

		Vector(const typename BaseClass::ArrayType &arr)
			: BaseClass(arr)
		{ }

		Vector(const Vector &other)
			: BaseClass(other)
		{ }

	};

	//2D Implementation
	template <typename T>
	class Vector<T, 2> : public VectorBase<T, Vector<T, 2>, 2>
	{
	public:
		typedef VectorBase<T, Vector<T, 2>, 2> BaseClass;
		using BaseClass::x;
		using BaseClass::y;

	public:
		DEFINE_USING_BASECLASS;

		Vector()
			: BaseClass()
		{ }

		Vector(T x, T y)
		{
			this->x = x;
			this->y = y;
		}

		Vector(const Vector<T, 3> &other)
		{
			this->x = other.x;
			this->y = other.y;
		}

		inline float getAngle() const
		{
			return std::atan2(y, x);
		}

		inline const Vector getCrossProduct() const
		{
			return Vector(y, -x);
		}
	};

	//3D Implementation
	template <typename T>
	class Vector<T, 3> : public VectorBase<T, Vector<T, 3>, 3>
	{
	public:
		typedef VectorBase<T, Vector<T, 3>, 3> BaseClass;
		using BaseClass::x;
		using BaseClass::y;
		using BaseClass::z;

	public:
		DEFINE_USING_BASECLASS;

		Vector()
			: BaseClass()
		{ }

		Vector(const Vector<T, 2> &other)
		{
			this->x = other.x;
			this->y = other.y;
			this->z = 1.0f;
		}

		Vector(T x, T y, T z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}


		Vector(T x, T y)
		{
			this->x = x;
			this->y = y;
			this->z = 1.f;
		}

		inline const Vector getCrossProduct(const Vector &other) const
		{
			return Vector((y * other.z) - (other.y * z), (z * other.x) - (other.z * x), (x * other.y) - (other.x * y));
		}
	};

	//Typedefs
	typedef Vector<float, 2> Vec2;
	typedef Vector<double, 2> Vec2d;
	typedef Vector<int, 2> Vec2i;

	typedef Vector<float, 3> Vec3;
	typedef Vector<double, 3> Vec3d;
	typedef Vector<int, 3> Vec3i;

	typedef Vector<float, 4> Vec4;
	typedef Vector<double, 4> Vec4d;
	typedef Vector<int, 4> Vec4i;
}

#endif
