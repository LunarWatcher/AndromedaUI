// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <chrono>                  // for operator""s, chrono_literals
#include <andromeda/dom/elements.hpp>  // for Element, operator|, separator, filler, hbox, size, spinner, text, vbox, bold, border, Fit, EQUAL, WIDTH
#include <andromeda/screen/screen.hpp>  // for Full, Screen
#include <iostream>                 // for cout, endl, ostream
#include <string>                   // for to_string, operator<<, string
#include <thread>                   // for sleep_for
#include <utility>                  // for move
#include <vector>                   // for vector

#include "andromeda/dom/node.hpp"      // for Render
#include "andromeda/screen/color.hpp"  // for andromeda

int main() {
  using namespace andromeda;
  using namespace std::chrono_literals;

  std::string reset_position;
  for (int index = 0; index < 200; ++index) {
    std::vector<Element> entries;
    for (int i = 0; i < 23; ++i) {
      if (i != 0)
        entries.push_back(separator());
      entries.push_back(  //
          hbox({
              text(std::to_string(i)) | size(WIDTH, EQUAL, 2),
              separator(),
              spinner(i, index) | bold,
          }));
    }
    auto document = hbox({
        vbox(std::move(entries)) | border,
        filler(),
    });
    auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
    Render(screen, document);
    std::cout << reset_position;
    screen.Print();
    reset_position = screen.ResetPosition();

    std::this_thread::sleep_for(0.1s);
  }
  std::cout << std::endl;
}
