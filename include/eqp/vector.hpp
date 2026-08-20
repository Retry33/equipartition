#ifndef EQUIPARTITION_VECTOR_H_
#define EQUIPARTITION_VECTOR_H_

#include <cassert>
#include <cmath>

namespace eqp {
struct Vector {
  double x{};
  double y{};

  constexpr Vector operator-() const { return {-x, -y}; }
  constexpr Vector& operator+=(const Vector rhv) {
    x += rhv.x;
    y += rhv.y;
    return *this;
  }

  constexpr Vector& operator-=(const Vector rhv) {
    x -= rhv.x;
    y -= rhv.y;
    return *this;
  }

  double length() const { return std::sqrt(lengthSquared()); }

  constexpr double lengthSquared() const { return x * x + y * y; }
};

constexpr Vector operator+(Vector lhv, Vector rhv) {
  lhv += rhv;
  return lhv;
}

constexpr Vector operator-(Vector lhv, Vector rhv) {
  lhv -= rhv;
  return lhv;
}

constexpr Vector operator*(Vector v, double s) { return {v.x * s, v.y * s}; }

constexpr Vector operator*(double s, Vector v) { return v * s; }

constexpr Vector operator/(Vector v, double s) {
  assert(s != 0.0);
  return {v.x / s, v.y / s};
}

constexpr double dotProduct(Vector lhv, Vector rhv) {
  return lhv.x * rhv.x + lhv.y * rhv.y;
}

inline Vector normalized(Vector v) {
  assert(v.lengthSquared() > 0.0);
  return v / v.length();
}
}  // namespace eqp

#endif