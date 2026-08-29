// Copyright 2022 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <catch2/catch_test_macros.hpp>  // for Test, EXPECT_EQ, Message, TestPartResult, TestInfo (ptr only), TEST
#include <migrate/GTestCompat.hpp>
#include <string>  // for allocator

#include "andromeda/dom/elements.hpp"  // for operator|, text, bgcolor, color, Element
#include "andromeda/dom/node.hpp"      // for Render
#include "andromeda/screen/color.hpp"   // for Color, Color::Red, Color::RedLight
#include "andromeda/screen/screen.hpp"  // for Screen, Pixel

// NOLINTBEGIN
namespace andromeda {

TEST(ColorTest, Foreground) {
  auto element = text("text") | color(Color::Red);
  Screen screen(5, 1);
  Render(screen, element);
  EXPECT_EQ(screen.PixelAt(0, 0).foreground_color, Color::Red);
  EXPECT_EQ(screen.PixelAt(0, 0).background_color, Color());
}

TEST(ColorTest, Background) {
  auto element = text("text") | bgcolor(Color::Red);
  Screen screen(5, 1);
  Render(screen, element);
  EXPECT_EQ(screen.PixelAt(0, 0).foreground_color, Color());
  EXPECT_EQ(screen.PixelAt(0, 0).background_color, Color::Red);
}

}  // namespace andromeda
// NOLINTEND
