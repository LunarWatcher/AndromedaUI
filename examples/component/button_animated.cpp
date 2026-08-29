// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <memory>  // for shared_ptr, __shared_ptr_access
#include <string>  // for operator+, to_string

#include "andromeda/component/captured_mouse.hpp"  // for andromeda
#include "andromeda/component/component.hpp"  // for Button, Horizontal, Renderer
#include "andromeda/component/component_base.hpp"      // for ComponentBase
#include "andromeda/component/component_options.hpp"   // for ButtonOption
#include "andromeda/component/screen_interactive.hpp"  // for ScreenInteractive
#include "andromeda/dom/elements.hpp"  // for gauge, separator, text, vbox, operator|, Element, border
#include "andromeda/screen/color.hpp"  // for Color, Color::Blue, Color::Green, Color::Red

using namespace andromeda;

int main() {
  int value = 50;

  // The tree of components. This defines how to navigate using the keyboard.
  auto buttons = Container::Horizontal({
      Button(
          "Decrease", [&] { value--; }, ButtonOption::Animated(Color::Red)),
      Button(
          "Reset", [&] { value = 50; }, ButtonOption::Animated(Color::Green)),
      Button(
          "Increase", [&] { value++; }, ButtonOption::Animated(Color::Blue)),
  });

  // Modify the way to render them on screen:
  auto component = Renderer(buttons, [&] {
    return vbox({
        vbox({
            text("value = " + std::to_string(value)),
            separator(),
            gauge(value * 0.01f),
        }) | border,
        buttons->Render(),
    });
  });

  auto screen = ScreenInteractive::FitComponent();
  screen.Loop(component);
  return 0;
}
