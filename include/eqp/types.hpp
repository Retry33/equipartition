#ifndef EQUIPARTITION_TYPES_H_
#define EQUIPARTITION_TYPES_H_

#include <cstdint>
#include <limits>

namespace eqp {
struct Piston {
  double position{};
  double velocity{};
  double mass = std::numeric_limits<double>::infinity();
};

struct Box {
  double left{};
  double right{};
  double bottom{};
};

struct SimParams {
  double particleRadius = 0.01;
  double particleMass = 1.0;
  std::size_t particleCount = 500;
  std::uint64_t seed = 42;
};
}  // namespace eqp

#endif