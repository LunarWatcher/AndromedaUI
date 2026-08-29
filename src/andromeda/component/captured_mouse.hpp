// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#ifndef ANDROMEDAUI_CAPTURED_MOUSE_HPP
#define ANDROMEDAUI_CAPTURED_MOUSE_HPP

#include <memory>

namespace andromeda {
class CapturedMouseInterface {
 public:
  CapturedMouseInterface() = default;
  CapturedMouseInterface(const CapturedMouseInterface&) = default;
  CapturedMouseInterface(CapturedMouseInterface&&) = delete;
  CapturedMouseInterface& operator=(const CapturedMouseInterface&) = default;
  CapturedMouseInterface& operator=(CapturedMouseInterface&&) = delete;
  virtual ~CapturedMouseInterface() = default;
};
using CapturedMouse = std::unique_ptr<CapturedMouseInterface>;
}  // namespace andromeda

#endif /* end of include guard: ANDROMEDAUI_CAPTURED_MOUSE_HPP */
