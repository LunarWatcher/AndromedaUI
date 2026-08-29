// Copyright 2023 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <andromeda/dom/elements.hpp>  // for bgcolor, operator|, operator|=, text, center, Element
#include <andromeda/dom/linear_gradient.hpp>  // for LinearGradient::Stop, LinearGradient
#include <andromeda/screen/screen.hpp>        // for Full, Screen
#include <memory>                         // for allocator, shared_ptr

#include "andromeda/dom/node.hpp"  // for Render
#include "andromeda/screen/color.hpp"  // for Color, Color::DeepPink1, Color::DeepSkyBlue1, Color::Yellow, andromeda

int main() {
  using namespace andromeda;
  auto document = text("gradient") | center;

  document |= bgcolor(LinearGradient()
                          .Angle(45)
                          .Stop(Color::DeepPink1)
                          .Stop(Color::DeepSkyBlue1));
  auto screen = Screen::Create(Dimension::Full(), Dimension::Full());
  Render(screen, document);
  screen.Print();

  return 0;
}
