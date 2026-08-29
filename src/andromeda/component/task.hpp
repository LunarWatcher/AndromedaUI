// Copyright 2022 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#ifndef ANDROMEDAUI_COMPONENT_ANIMATION_HPP
#define ANDROMEDAUI_COMPONENT_ANIMATION_HPP

#include <functional>
#include <variant>
#include "andromeda/component/event.hpp"

namespace andromeda {
class AnimationTask {};
using Closure = std::function<void()>;
using Task = std::variant<Event, Closure, AnimationTask>;
}  // namespace andromeda

#endif  // ANDROMEDAUI_COMPONENT_ANIMATION_HPP
