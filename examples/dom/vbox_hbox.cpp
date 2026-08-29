// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <stdio.h>                  // for getchar
#include <andromeda/dom/elements.hpp>   // for filler, text, hbox, vbox
#include <andromeda/screen/screen.hpp>  // for Full, Screen
#include <memory>                   // for allocator

#include "andromeda/dom/node.hpp"      // for Render
#include "andromeda/screen/color.hpp"  // for andromeda

int main() {
  using namespace andromeda;
  auto document =  //
      vbox({
          hbox({
              text("north-west"),
              filler(),
              text("north-east"),
          }),
          filler(),
          hbox({
              filler(),
              text("center"),
              filler(),
          }),
          filler(),
          hbox({
              text("south-west"),
              filler(),
              text("south-east"),
          }),
      });
  auto screen = Screen::Create(Dimension::Full());
  Render(screen, document);
  screen.Print();
  getchar();

  return 0;
}
