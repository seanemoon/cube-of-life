#ifndef CHAOS_UTIL_MATH_H
#define CHAOS_UTIL_MATH_H

#include <cmath>

/*******************************************************************************
 * util/math.h
 *
 * This file includes all necesarry math functionality used throughout the
 * codebase. This allows us to decouple the backing math library so that we may
 * do testing and switch math libraries if needed down the road.
 * TODO: Document which functions need to be implemented for a port.
 *
 ******************************************************************************/

// We currently use the Eigen library.
#include "util/math_eigen.h"

#endif  // CHAOS_UTIL_MATH_H
