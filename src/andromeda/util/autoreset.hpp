// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#ifndef ANDROMEDAUI_UTIL_AUTORESET_HPP
#define ANDROMEDAUI_UTIL_AUTORESET_HPP

#include <utility>

namespace andromeda {

/// Assign a value to a variable, reset its old value when going out of scope.
template <typename T>
class AutoReset {
 public:
  AutoReset(T* variable, T new_value)
      : variable_(variable), previous_value_(std::move(*variable)) {
    *variable_ = std::move(new_value);
  }
  AutoReset(const AutoReset&) = delete;
  AutoReset(AutoReset&&) = delete;
  AutoReset& operator=(const AutoReset&) = delete;
  AutoReset& operator=(AutoReset&&) = delete;
  ~AutoReset() { *variable_ = std::move(previous_value_); }

 private:
  T* variable_;
  T previous_value_;
};

}  // namespace andromeda

#endif /* end of include guard: ANDROMEDAUI_UTIL_AUTORESET_HPP */
