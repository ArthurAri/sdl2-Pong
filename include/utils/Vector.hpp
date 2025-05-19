#pragma once

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

namespace Math {

    struct Vector2 {
        float x, y;
    
        constexpr Vector2(float x = 0, float y = 0) : x(x), y(y) {}
    
        Vector2 operator+(const Vector2 other) const;
        Vector2 operator*(const float other) const;
        Vector2 operator/(const float other) const;
        Vector2 operator-() const;
        Vector2 operator-(const Vector2 other) const;
        Vector2& operator+=(const Vector2 other);
        Vector2& operator-=(const Vector2 other);
        Vector2& operator*=(const float other);
        Vector2& operator/=(const float other);

        bool operator==(const Vector2 other) const;
        bool operator!=(const Vector2 other) const;

        float operator[](int index) const;
        
        float magnitude() const;

        static const Vector2 zero;
        static const Vector2 one;
    };

    struct Vector3 {
        float x, y, z;
        
        constexpr Vector3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
        
        Vector3 operator+(const Vector3 other) const;
        Vector3 operator+(const Vector2 other) const;
        Vector3 operator*(const float other) const;
        Vector3 operator/(const float other) const;
        Vector3& operator+=(const Vector3 other);
        Vector3& operator+=(const Vector2 other);
        Vector3& operator*=(const float other) const;
        Vector3& operator/=(const float other) const;
        Vector3& operator-=(const Vector3 other);
        Vector3& operator-=(const Vector2 other);
        Vector3 operator-() const;
        Vector3 operator-(const Vector3 other) const;
        Vector3 operator-(const Vector2 other) const;
        bool operator==(const Vector3 other) const;
        bool operator!=(const Vector3 other) const;

        float operator[](int index) const;

        float magnitude() const;
    };

    // Função para imprimir vetores
    void printVector(const Vector2 v);
    void printVector(const Vector3& v);

}
#endif // VECTOR_H