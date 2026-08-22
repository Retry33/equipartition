#ifndef EQUIPARTITION_PARTICLE_H_
#define EQUIPARTITION_PARTICLE_H_

#include <cstdint>

#include "eqp/vector.hpp"

namespace eqp {
struct Particle {
  Vector position{};
  Vector velocity{};
  std::uint64_t collisionCount{};
};
}  // namespace eqp

#endif