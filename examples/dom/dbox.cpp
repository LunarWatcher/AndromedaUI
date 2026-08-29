// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <andromeda/dom/elements.hpp>  // for text, operator|, border, Element, vbox, center, Fit, dbox
#include <andromeda/screen/screen.hpp>  // for Full, Screen
#include <memory>                   // for allocator

#include "andromeda/dom/node.hpp"      // for Render
#include "andromeda/screen/color.hpp"  // for andromeda

int main() {
  using namespace andromeda;
  auto document = dbox({
      vbox({
          text("line_1"),
          text("line_2"),
          text("line_3"),
          text("line_4"),
          text("line_5"),
      }) | border,
      text("overlay") | border | center,
  });
  auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
  Render(screen, document);

  screen.Print();

  return 0;
}
