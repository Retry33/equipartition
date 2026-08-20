#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include "eqp/vector.hpp"

TEST_CASE("vector arithmetic", "[vector]") {
  const eqp::Vector a{1.0, 2.0};
  const eqp::Vector b{3.0, 4.0};

  REQUIRE((a + b).x == 4.0);
  REQUIRE((a + b).y == 6.0);
  REQUIRE((b - a).x == 2.0);
  REQUIRE((2.0 * a).y == 4.0);
}

TEST_CASE("vector length", "[vector]") {
  REQUIRE(eqp::Vector{3.0, 4.0}.length() == 5.0);
  REQUIRE(eqp::Vector{3.0, 4.0}.lengthSquared() == 25.0);
}

TEST_CASE("dot product", "[vector]") {
  REQUIRE(eqp::dotProduct({1.0, 0.0}, {0.0, 1.0}) == 0.0);
  REQUIRE(eqp::dotProduct({1.0, 2.0}, {3.0, 4.0}) == 11.0);
}

TEST_CASE("normalized has unit length", "[vector]") {
  const eqp::Vector n = eqp::normalized({3.0, 4.0});
  REQUIRE_THAT(n.lengthSquared(), Catch::Matchers::WithinRel(1.0, 1e-12));
}