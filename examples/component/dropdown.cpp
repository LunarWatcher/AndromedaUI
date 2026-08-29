// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <string>  // for basic_string, string, allocator
#include <vector>  // for vector

#include "andromeda/component/captured_mouse.hpp"  // for andromeda
#include "andromeda/component/component.hpp"  // for Dropdown, Horizontal, Vertical
#include "andromeda/component/screen_interactive.hpp"  // for ScreenInteractive

int main() {
  using namespace andromeda;

  std::vector<std::string> entries = {
      "tribute",     "clearance", "ally",        "bend",        "electronics",
      "module",      "era",       "cultural",    "sniff",       "nationalism",
      "negotiation", "deliver",   "figure",      "east",        "tribute",
      "clearance",   "ally",      "bend",        "electronics", "module",
      "era",         "cultural",  "sniff",       "nationalism", "negotiation",
      "deliver",     "figure",    "east",        "tribute",     "clearance",
      "ally",        "bend",      "electronics", "module",      "era",
      "cultural",    "sniff",     "nationalism", "negotiation", "deliver",
      "figure",      "east",
  };

  int selected_1 = 0;
  int selected_2 = 0;
  int selected_3 = 0;
  int selected_4 = 0;

  auto layout = Container::Vertical({
      Container::Horizontal({
          Dropdown(&entries, &selected_1),
          Dropdown(&entries, &selected_2),
      }),
      Container::Horizontal({
          Dropdown(&entries, &selected_3),
          Dropdown(&entries, &selected_4),
      }),
  });

  auto screen = ScreenInteractive::FitComponent();
  screen.Loop(layout);
}
