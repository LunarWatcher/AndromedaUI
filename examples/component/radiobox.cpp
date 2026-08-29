// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <string>  // for string, allocator, basic_string
#include <vector>  // for vector

#include "andromeda/component/captured_mouse.hpp"      // for andromeda
#include "andromeda/component/component.hpp"           // for Radiobox
#include "andromeda/component/screen_interactive.hpp"  // for ScreenInteractive

using namespace andromeda;

int main() {
  std::vector<std::string> radiobox_list = {
      "Use gcc",
      "Use clang",
      "Use emscripten",
      "Use tcc",
  };
  int selected = 0;

  auto screen = ScreenInteractive::TerminalOutput();
  screen.Loop(Radiobox(&radiobox_list, &selected));
  return 0;
}
