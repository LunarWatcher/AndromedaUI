// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <array>   // for array
#include <memory>  // for shared_ptr, __shared_ptr_access
#include <string>  // for operator+, to_string

#include "andromeda/component/captured_mouse.hpp"  // for andromeda
#include "andromeda/component/component.hpp"  // for Checkbox, Renderer, Vertical
#include "andromeda/component/component_base.hpp"      // for ComponentBase
#include "andromeda/component/screen_interactive.hpp"  // for ScreenInteractive
#include "andromeda/dom/elements.hpp"  // for operator|, Element, size, border, frame, vscroll_indicator, HEIGHT, LESS_THAN

using namespace andromeda;

int main() {
  std::array<bool, 30> states;

  auto container = Container::Vertical({});
  for (int i = 0; i < 30; ++i) {
    states[i] = false;
    container->Add(Checkbox("Checkbox" + std::to_string(i), &states[i]));
  }

  auto renderer = Renderer(container, [&] {
    return container->Render() | vscroll_indicator | frame |
           size(HEIGHT, LESS_THAN, 10) | border;
  });

  auto screen = ScreenInteractive::FitComponent();
  screen.Loop(renderer);

  return 0;
}
