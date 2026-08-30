// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <andromeda/component/captured_mouse.hpp>  // for andromeda
#include <string>  // for allocator, operator+, char_traits, string

#include "andromeda/component/component.hpp"           // for Renderer, Vertical
#include "andromeda/component/screen_interactive.hpp"  // for ScreenInteractive, Component
#include "andromeda/dom/elements.hpp"  // for text, Decorator, focus, focusCursorBar, focusCursorBarBlinking, focusCursorBlock, focusCursorBlockBlinking, focusCursorUnderline, focusCursorUnderlineBlinking, hbox, Element

using namespace andromeda;

static Component Instance(const std::string& label, const Decorator& focusCursor) {
  return Renderer([=](bool focused) {
    if (focused) {
      return hbox({
          text("> " + label + " "),
          focusCursor(text(" ")),
      });
    }
    return text("  " + label + " ");
  });
};

int main() {
  auto screen = ScreenInteractive::Fullscreen();
  screen.Loop(Container::Vertical({
      Instance("focus", focus),
      Instance("focusCursorBlock", focusCursorBlock),
      Instance("focusCursorBlockBlinking", focusCursorBlockBlinking),
      Instance("focusCursorBar", focusCursorBar),
      Instance("focusCursorBarBlinking", focusCursorBarBlinking),
      Instance("focusCursorUnderline", focusCursorUnderline),
      Instance("focusCursorUnderlineBlinking", focusCursorUnderlineBlinking),
  }));
  return 0;
}
