// Copyright 2022 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#ifndef ANDROMEDAUI_SCREEN_UTIL_HPP
#define ANDROMEDAUI_SCREEN_UTIL_HPP

namespace andromeda::util {

// Similar to std::clamp, but allow hi to be lower than lo.
template <class T>
constexpr T clamp(const T& v, const T& lo, const T& hi) {
  return v < lo ? lo : hi < v ? hi : v;
}

}  // namespace andromeda::util

#endif /* end of include guard: ANDROMEDAUI_SCREEN_UTIL_HPP */
