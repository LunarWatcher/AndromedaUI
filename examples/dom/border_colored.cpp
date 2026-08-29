// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <andromeda/dom/elements.hpp>  // for operator|, text, Element, Fit, borderDouble, borderHeavy, borderLight, borderRounded, vbox
#include <andromeda/screen/screen.hpp>  // for Screen
#include <iostream>                 // for endl, cout, ostream
#include <memory>                   // for allocator

#include "andromeda/dom/node.hpp"      // for Render
#include "andromeda/screen/color.hpp"  // for andromeda

int main() {
  using namespace andromeda;

  auto make_boxed = [] {
    return vbox({
        text("borderLight") | borderStyled(LIGHT, Color::Red),
        text("borderDashed") | borderStyled(DASHED, Color::Green),
        text("borderHeavy") | borderStyled(HEAVY, Color::Blue),
        text("borderDouble") | borderStyled(DOUBLE, Color::Yellow),
        text("borderRounded") | borderStyled(ROUNDED, Color::Cyan),
    });
  };

  auto document = hbox({
                      make_boxed(),
                      separator() | color(Color::Red),
                      make_boxed(),
                      separator() | color(Color::Red),
                      make_boxed(),
                  }) |
                  borderStyled(ROUNDED, Color::Red);

  auto screen =
      Screen::Create(Dimension::Fit(document), Dimension::Fit(document));
  Render(screen, document);
  screen.Print();
  std::cout << std::endl;
}
