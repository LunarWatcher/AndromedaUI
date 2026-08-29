// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <andromeda/dom/elements.hpp>  // for text, operator|, Element, bgcolor, color, blink, bold, dim, inverted, underlined, Fit, hbox
#include <andromeda/screen/screen.hpp>  // for Full, Screen
#include <memory>                   // for allocator

#include "andromeda/dom/node.hpp"      // for Render
#include "andromeda/screen/color.hpp"  // for Color, Color::Blue, andromeda

int main() {
  using namespace andromeda;
  // clang-format off
  auto document =
    hbox({
      text("normal")                                    , text(" ") ,
      text("bold")               | bold                 , text(" ") ,
      text("italic")             | italic               , text(" ") ,
      text("dim")                | dim                  , text(" ") ,
      text("inverted")           | inverted             , text(" ") ,
      text("underlined")         | underlined           , text(" ") ,
      text("underlinedDouble")   | underlinedDouble     , text(" ") ,
      text("blink")              | blink                , text(" ") ,
      text("strikethrough")      | strikethrough        , text(" ") ,
      text("color")              | color(Color::Blue)   , text(" ") ,
      text("bgcolor")            | bgcolor(Color::Blue) , text(" ") ,
      text("hyperlink")          | hyperlink("https://github.com/ArthurSonzogni/FTXUI"),
    });
  // clang-format on
  auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
  Render(screen, document);
  screen.Print();

  return 0;
}
