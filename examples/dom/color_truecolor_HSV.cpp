// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <andromeda/dom/elements.hpp>  // for operator|, Elements, Fit, bgcolor, color, hbox, text, vbox, Element
#include <andromeda/screen/screen.hpp>  // for Full, Screen
#include <memory>                   // for allocator
#include <utility>                  // for move

#include "andromeda/dom/node.hpp"      // for Render
#include "andromeda/screen/color.hpp"  // for Color, andromeda

int main() {
  using namespace andromeda;

  int saturation = 255;
  Elements array;
  for (int value = 0; value < 255; value += 20) {
    Elements line;
    for (int hue = 0; hue < 255; hue += 2) {
      line.push_back(text("▀")                                    //
                     | color(Color::HSV(hue, saturation, value))  //
                     | bgcolor(Color::HSV(hue, saturation, value + 10)));
    }
    array.push_back(hbox(std::move(line)));
  }

  auto document = vbox(std::move(array));

  auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
  Render(screen, document);

  screen.Print();

  return 0;
}
