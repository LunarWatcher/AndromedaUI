// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <string>  // for operator+, to_string

#include "andromeda/component/captured_mouse.hpp"  // for andromeda
#include "andromeda/component/component.hpp"  // for Button, Vertical, Renderer, Horizontal, operator|
#include "andromeda/component/component_base.hpp"      // for Component
#include "andromeda/component/component_options.hpp"   // for ButtonOption
#include "andromeda/component/screen_interactive.hpp"  // for ScreenInteractive
#include "andromeda/dom/elements.hpp"  // for Element, separator, text, border
#include "andromeda/screen/color.hpp"  // for Color, Color::Blue, Color::Green, Color::Red

using namespace andromeda;

int main() {
  int value = 0;
  auto action = [&] { value++; };
  auto action_renderer =
      Renderer([&] { return text("count = " + std::to_string(value)); });

  auto buttons =
      Container::Vertical({
          action_renderer,
          Renderer([] { return separator(); }),
          Container::Horizontal({
              Container::Vertical({
                  Button("Ascii 1", action, ButtonOption::Ascii()),
                  Button("Ascii 2", action, ButtonOption::Ascii()),
                  Button("Ascii 3", action, ButtonOption::Ascii()),
              }),
              Renderer([] { return separator(); }),
              Container::Vertical({
                  Button("Simple 1", action, ButtonOption::Simple()),
                  Button("Simple 2", action, ButtonOption::Simple()),
                  Button("Simple 3", action, ButtonOption::Simple()),
              }),
              Renderer([] { return separator(); }),
              Container::Vertical({
                  Button("Animated 1", action, ButtonOption::Animated()),
                  Button("Animated 2", action, ButtonOption::Animated()),
                  Button("Animated 3", action, ButtonOption::Animated()),
              }),
              Renderer([] { return separator(); }),
              Container::Vertical({
                  Button("Animated 4", action,
                         ButtonOption::Animated(Color::Red)),
                  Button("Animated 5", action,
                         ButtonOption::Animated(Color::Green)),
                  Button("Animated 6", action,
                         ButtonOption::Animated(Color::Blue)),
              }),
          }),
      }) |
      border;

  auto screen = ScreenInteractive::FitComponent();
  screen.Loop(buttons);
  return 0;
}
