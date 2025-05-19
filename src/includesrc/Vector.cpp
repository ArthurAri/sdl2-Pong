#include <utils/math.hpp>

using namespace Math;

//V2
Vector2 Vector2::operator+(const Vector2 other) const {
    return Vector2(x + other.x, y + other.y);
}
Vector2 Vector2::operator*(const float mult) const {
    return Vector2(x * mult, y * mult);
}
Vector2 Vector2::operator/(const float mult) const {
    return Vector2(x / mult, y / mult);
}
Vector2 Vector2::operator-(const Vector2 other) const {
    return Vector2(x - other.x, y - other.y);
}
Vector2 Vector2::operator-() const{
    return Vector2(-x,-y);
}
Vector2& Vector2::operator+=(const Vector2 other){
    *this = *this + other;
    return *this;
}
Vector2& Vector2::operator-=(const Vector2 other){
    *this = *this - other;
    return *this;
}
Vector2& Vector2::operator/=(const float other){
    *this = *this / other;
    return *this;
}
Vector2& Vector2::operator*=(const float other){
    *this = *this * other;
    return *this;
}

bool Vector2::operator==(const Vector2 other) const{
    return x == other.x && y == other.y;
}
bool Vector2::operator!=(const Vector2 other) const{
    return !(*this == other);
}
float Vector2::magnitude() const{
    return std::sqrt(x*x+y*y);
}

const Vector2 Vector2::zero(0.f, 0.f);
const Vector2 Vector2::one(1.f, 1.f);
//V3
Vector3 Vector3::operator+(const Vector3 other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}
Vector3 Vector3::operator+(const Vector2 other) const {
    return Vector3(x + other.x, y + other.y, z);
}
Vector3 Vector3::operator*(const float mult) const {
    return Vector3(x * mult, y * mult, z * mult);
}
Vector3 Vector3::operator/(const float mult) const {
    return Vector3(x / mult, y / mult, z / mult);
}
Vector3 Vector3::operator-(const Vector3 other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}
Vector3 Vector3::operator-(const Vector2 other) const {
    return Vector3(x - other.x, y - other.y, z);
}
Vector3 Vector3::operator-() const{
    return Vector3(-x,-y,-z);
}
Vector3& Vector3::operator+=(const Vector3 other){
    *this = *this + other;
    return *this;
}
Vector3& Vector3::operator-=(const Vector3 other){
    *this = *this - other;
    return *this;
}
Vector3& Vector3::operator+=(const Vector2 other){
    *this = *this + other;
    return *this;
}
Vector3& Vector3::operator-=(const Vector2 other){
    *this = *this - other;
    return *this;
}

bool Vector3::operator==(const Vector3 other) const{
    return x == other.x && y == other.y && z == other.z;
}
bool Vector3::operator!=(const Vector3 other) const{
    return x == other.x && y == other.y && z == other.z;
}

float Vector3::magnitude() const{
    return std::sqrt(x*x+y*y+z*z);
}

void printVector(const Vector2 v) {
    std::cout << "Vector2(" << v.x << ", " << v.y << ")\n";
}

void printVector(const Vector3 v) {
    std::cout << "Vector3(" << v.x << ", " << v.y << ", " << v.z << ")\n";
}