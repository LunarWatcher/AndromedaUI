// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <andromeda/dom/elements.hpp>  // for text, center, separator, operator|, flex, Element, vbox, Fit, hbox, border
#include <andromeda/screen/screen.hpp>  // for Full, Screen
#include <memory>                   // for allocator

#include "andromeda/dom/node.hpp"      // for Render
#include "andromeda/screen/color.hpp"  // for andromeda

int main() {
  using namespace andromeda;
  auto document = hbox({
                      text("left-column"),
                      separator(),
                      vbox({
                          center(text("top")) | flex,
                          separator(),
                          center(text("bottom")),
                      }) | flex,
                      separator(),
                      text("right-column"),
                  }) |
                  border;
  auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
  Render(screen, document);
  screen.Print();

  return 0;
}
