#ifndef NE_VECTOR_H
#define NE_VECTOR_H

#include "types.hpp"

namespace ne {

    class Vec2
    {
    public:
        Vec2(Float x=0.0f, Float y=0.0f);
        Float magnitude() const;
        void normalize();
        Vec2 projection(const Vec2& other);
        Vec2& operator+=(const Vec2& other);
        Vec2& operator-=(const Vec2& other);
        Vec2& operator*=(Float scalar);
        Vec2& operator/=(Float scalar);
        friend Vec2 operator+(const Vec2& lhs, const Vec2& rhs);
        friend Vec2 operator-(const Vec2& lhs, const Vec2& rhs);
        friend Vec2 operator*(const Vec2& lhs, Float rhs);
        friend Vec2 operator*(Float lhs, const Vec2& rhs);
        friend Vec2 operator/(const Vec2& lhs, Float rhs);
        friend Float operator*(const Vec2& lhs, const Vec2& rhs);
    public:
        Float x;
        Float y;
    };

    class Vec3
    {
    public:
        Vec3(Float x=0.0f, Float y=0.0f, Float z=0.0f);
        Float magnitude() const;
        void normalize();
        Vec3 projection(const Vec3& other);
        Vec3& operator+=(const Vec3& other);
        Vec3& operator-=(const Vec3& other);
        Vec3& operator*=(Float scalar);
        Vec3& operator/=(Float scalar);
        friend Vec3 operator+(const Vec3& lhs, const Vec3& rhs);
        friend Vec3 operator-(const Vec3& lhs, const Vec3& rhs);
        friend Vec3 operator*(const Vec3& lhs, Float rhs);
        friend Vec3 operator*(Float lhs, const Vec3& rhs);
        friend Vec3 operator/(const Vec3& lhs, Float rhs);
        friend Float operator*(const Vec3& lhs, const Vec3& rhs);
        friend Vec3 operator^(const Vec3& lhs, const Vec3& rhs);
    public:
        Float x;
        Float y;
        Float z;
    };

    class Vec4
    {
    public:
        Vec4(Float x=0.0f, Float y=0.0f, Float z=0.0f, Float w=0.0f);
        Float magnitude() const;
        void normalize();
        Vec4 projection(const Vec4& other);
        Vec4& operator+=(const Vec4& other);
        Vec4& operator-=(const Vec4& other);
        Vec4& operator*=(Float scalar);
        Vec4& operator/=(Float scalar);
        friend Vec4 operator+(const Vec4& lhs, const Vec4& rhs);
        friend Vec4 operator-(const Vec4& lhs, const Vec4& rhs);
        friend Vec4 operator*(const Vec4& lhs, Float rhs);
        friend Vec4 operator*(Float lhs, const Vec4& rhs);
        friend Vec4 operator/(const Vec4& lhs, Float rhs);
        friend Float operator*(const Vec4& lhs, const Vec4& rhs);
    public:
        Float x;
        Float y;
        Float z;
        Float w;
    };
}

#endif //NE_VECTOR_H
