// Copyright 2021 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <memory>  // for allocator, __shared_ptr_access
#include <string>  // for string, basic_string, operator+, to_string
#include <vector>  // for vector

#include "andromeda/component/captured_mouse.hpp"  // for andromeda
#include "andromeda/component/component.hpp"       // for Input, Renderer, Vertical
#include "andromeda/component/component_base.hpp"  // for ComponentBase
#include "andromeda/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "andromeda/dom/elements.hpp"  // for operator|, Element, size, border, frame, vscroll_indicator, HEIGHT, LESS_THAN

int main() {
  using namespace andromeda;

  Component input_list = Container::Vertical({});
  std::vector<std::string> items(100, "");
  for (size_t i = 0; i < items.size(); ++i) {
    input_list->Add(Input(&(items[i]), "placeholder " + std::to_string(i)));
  }

  auto renderer = Renderer(input_list, [&] {
    return input_list->Render() | vscroll_indicator | frame | border |
           size(HEIGHT, LESS_THAN, 10);
  });

  auto screen = ScreenInteractive::TerminalOutput();
  screen.Loop(renderer);
}
