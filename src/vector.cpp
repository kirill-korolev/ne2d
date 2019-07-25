#include "vector.hpp"
#include "math.hpp"
#include "exception.hpp"

namespace ne {

    Vec2::Vec2(Float x, Float y): x(x), y(y) {}

    Float Vec2::magnitude() const {
        return sqrt((*this) * (*this));
    }

    void Vec2::normalize() {
        const Float invNorm = invSqrt((*this) * (*this));
        x *= invNorm;
        y *= invNorm;
    }

    Vec2 Vec2::projection(const Vec2& other) {
        const Float dot = (*this) * other;
        const Float norm = other.magnitude();
        const Float mult = dot / norm / norm;
        return Vec2(mult * other.x, mult * other.y);
    }

    Vec2& Vec2::operator+=(const Vec2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2& Vec2::operator-=(const Vec2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2& Vec2::operator*=(Float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vec2& Vec2::operator/=(Float scalar) {
        if (scalar == 0)
            throw Exception("Division by zero");

        x /= scalar;
        y /= scalar;

        return *this;
    }

    Vec2 operator+(const Vec2& lhs, const Vec2& rhs) {
        return Vec2(lhs.x + rhs.x, lhs.y + rhs.y);
    }

    Vec2 operator-(const Vec2& lhs, const Vec2& rhs) {
        return Vec2(lhs.x - rhs.x, lhs.y - rhs.y);
    }

    Vec2 operator*(const Vec2& lhs, Float rhs) {
        return Vec2(lhs.x * rhs, lhs.y * rhs);
    }

    Vec2 operator*(Float lhs, const Vec2& rhs) {
        return Vec2(lhs * rhs.x, lhs * rhs.y);
    }

    Vec2 operator/(const Vec2& lhs, Float rhs) {
        if (rhs == 0)
            throw Exception("Division by zero");
        return Vec2(lhs.x / rhs, lhs.y / rhs);
    }

    Float operator*(const Vec2& lhs, const Vec2& rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }

    Vec3::Vec3(Float x, Float y, Float z): x(x), y(y), z(z) {}

    Float Vec3::magnitude() const {
        return sqrt((*this) * (*this));
    }

    void Vec3::normalize() {
        const Float invNorm = invSqrt((*this) * (*this));
        x *= invNorm;
        y *= invNorm;
        z *= invNorm;
    }

    Vec3 Vec3::projection(const Vec3& other) {
        const Float dot = (*this) * other;
        const Float norm = other.magnitude();
        const Float mult = dot / norm / norm;
        return Vec3(mult * other.x, mult * other.y, mult * other.z);
    }

    Vec3& Vec3::operator+=(const Vec3& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vec3& Vec3::operator-=(const Vec3& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vec3& Vec3::operator*=(Float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    Vec3& Vec3::operator/=(Float scalar) {
        if (scalar == 0)
            throw Exception("Division by zero");
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    Vec3 operator+(const Vec3& lhs, const Vec3& rhs) {
        return Vec3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
    }

    Vec3 operator-(const Vec3& lhs, const Vec3& rhs) {
        return Vec3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
    }

    Vec3 operator*(const Vec3& lhs, Float rhs) {
        return Vec3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
    }

    Vec3 operator*(Float lhs, const Vec3& rhs) {
        return Vec3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
    }

    Vec3 operator/(const Vec3& lhs, Float rhs) {
        if (rhs == 0)
            throw Exception("Division by zero");
        return Vec3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
    }

    Float operator*(const Vec3& lhs, const Vec3& rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    Vec3 operator^(const Vec3& lhs, const Vec3& rhs) {
        return Vec3(lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x);
    }

    Vec4::Vec4(Float x, Float y, Float z, Float w) : x(x), y(y), z(z), w(w) {}

    Float Vec4::magnitude() const {
        return sqrt((*this) * (*this));
    }

    void Vec4::normalize() {
        const Float invNorm = invSqrt((*this) * (*this));
        x *= invNorm;
        y *= invNorm;
        z *= invNorm;
        w *= invNorm;
    }

    Vec4 Vec4::projection(const Vec4& other) {
        const Float dot = (*this) * other;
        const Float norm = other.magnitude();
        const Float mult = dot / norm / norm;
        return Vec4(mult * other.x, mult * other.y, mult * other.z, mult * other.w);
    }

    Vec4& Vec4::operator+=(const Vec4& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
    }

    Vec4& Vec4::operator-=(const Vec4& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;
        return *this;
    }

    Vec4& Vec4::operator*=(Float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
        return *this;
    }

    Vec4& Vec4::operator/=(Float scalar) {
        if (scalar == 0)
            throw Exception("Division by zero");
        x /= scalar;
        y /= scalar;
        z /= scalar;
        w /= scalar;
        return *this;
    }


    Vec4 operator+(const Vec4& lhs, const Vec4& rhs) {
        return Vec4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
    }

    Vec4 operator-(const Vec4& lhs, const Vec4& rhs) {
        return Vec4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
    }

    Vec4 operator*(const Vec4& lhs, Float rhs) {
        return Vec4(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs);
    }

    Vec4 operator*(Float lhs, const Vec4& rhs) {
        return Vec4(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w);
    }

    Vec4 operator/(const Vec4& lhs, Float rhs) {
        if (rhs == 0)
            throw Exception("Division by zero");
        return Vec4(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs);
    }

    Float operator*(const Vec4& lhs, const Vec4& rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
    }

}

