// Copyright 2022 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <functional>  // for function

#include "andromeda/component/component.hpp"  // for Renderer, ComponentDecorator, ElementDecorator, operator|, operator|=
#include "andromeda/component/component_base.hpp"  // for Component

namespace andromeda {

// NOLINTNEXTLINE
Component operator|(Component component, ComponentDecorator decorator) {
  return decorator(component);  // NOLINT
}

// NOLINTNEXTLINE
Component operator|(Component component, ElementDecorator decorator) {
  return component | Renderer(decorator);  // NOLINT
}

// NOLINTNEXTLINE
Component& operator|=(Component& component, ComponentDecorator decorator) {
  component = component | decorator;  // NOLINT
  return component;
}

// NOLINTNEXTLINE
Component& operator|=(Component& component, ElementDecorator decorator) {
  component = component | decorator;  // NOLINT
  return component;
}

}  // namespace andromeda
