// Copyright 2022 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <catch2/catch_test_macros.hpp>
#include <migrate/GTestCompat.hpp>
#include <cstdint>  // for uint32_t
#include <string>   // for allocator, string

#include "andromeda/dom/canvas.hpp"    // for Canvas
#include "andromeda/dom/elements.hpp"  // for canvas
#include "andromeda/dom/node.hpp"      // for Render
#include "andromeda/screen/color.hpp"  // for Color, Color::Black, Color::Blue, Color::Red, Color::White, Color::Yellow, Color::Cyan, Color::Green
#include "andromeda/screen/screen.hpp"    // for Screen
#include "andromeda/screen/terminal.hpp"  // for SetColorSupport, Color, TrueColor

// NOLINTBEGIN
namespace andromeda {

namespace {
uint32_t Hash(const std::string s) {
  uint32_t hash = 0;
  for (uint8_t c : s) {
    hash += c;
    hash *= 7;
  }
  return hash;
}
}  // namespace

TEST(CanvasTest, GoldPoint) {
  Terminal::SetColorSupport(Terminal::Color::TrueColor);
  auto element = canvas([](Canvas& c) {  //
    c.DrawPoint(3, 3, 1);
    c.DrawPointToggle(2, 8);
    c.DrawPointToggle(2, 8);
    c.DrawPointToggle(2, 8);
    c.DrawPointLine(3, 7, 10, 19);
    c.DrawPointCircle(10, 5, 3);
    c.DrawPointCircleFilled(20, 5, 3);
    c.DrawPointEllipse(10, 10, 5, 2);
    c.DrawPointEllipseFilled(10, 20, 5, 2);
  });
  Screen screen(30, 10);
  Render(screen, element);
  INFO(screen.ToString());
  EXPECT_EQ(Hash(screen.ToString()), 2085952774U);
}

TEST(CanvasTest, GoldPointColor) {
  Terminal::SetColorSupport(Terminal::Color::TrueColor);
  auto element = canvas([](Canvas& c) {  //
    c.DrawPoint(3, 3, 1, Color::Red);
    c.DrawPointLine(3, 7, 10, 19, Color::Blue);
    c.DrawPointCircle(10, 5, 3, Color::Yellow);
    c.DrawPointCircleFilled(20, 5, 3, Color::White);
    c.DrawPointEllipse(10, 10, 5, 2, Color::Black);
    c.DrawPointEllipseFilled(10, 20, 5, 2, Color::Cyan);
  });
  Screen screen(30, 10);
  Render(screen, element);
  INFO(screen.ToString());
  EXPECT_EQ(Hash(screen.ToString()), 2295070594U);
}

TEST(CanvasTest, GoldBlock) {
  Terminal::SetColorSupport(Terminal::Color::TrueColor);
  auto element = canvas([](Canvas& c) {  //
    c.DrawBlock(3, 3, 1);
    c.DrawBlockToggle(2, 8);
    c.DrawBlockToggle(2, 8);
    c.DrawBlockToggle(2, 8);
    c.DrawBlockLine(3, 7, 10, 19);
    c.DrawBlockCircle(10, 5, 3);
    c.DrawBlockCircleFilled(20, 5, 3);
    c.DrawBlockEllipse(10, 10, 5, 2);
    c.DrawBlockEllipseFilled(10, 20, 5, 2);
  });
  Screen screen(30, 10);
  Render(screen, element);
  INFO(screen.ToString());
  EXPECT_EQ(Hash(screen.ToString()), 2625314979U);
}

TEST(CanvasTest, GoldBlockColor) {
  Terminal::SetColorSupport(Terminal::Color::TrueColor);
  auto element = canvas([](Canvas& c) {  //
    c.DrawBlock(3, 3, 1, Color::Red);
    c.DrawBlockLine(3, 7, 10, 19, Color::Green);
    c.DrawBlockCircle(10, 5, 3, Color::Blue);
    c.DrawBlockCircleFilled(20, 5, 3, Color::Yellow);
    c.DrawBlockEllipse(10, 10, 5, 2, Color::White);
    c.DrawBlockEllipseFilled(10, 20, 5, 2, Color::Black);
  });
  Screen screen(30, 10);
  Render(screen, element);
  INFO(screen.ToString());
  EXPECT_EQ(Hash(screen.ToString()), 8392696U);
}

TEST(CanvasTest, GoldText) {
  Terminal::SetColorSupport(Terminal::Color::TrueColor);
  Canvas c(10, 10);
  c.DrawText(0, 0, "test");
  c.DrawText(0, 5, "test");
  c.DrawText(0, 10, "test");
  auto element = canvas(c);
  Screen screen(30, 10);
  Render(screen, element);
  EXPECT_EQ(Hash(screen.ToString()), 1074960375);
}

}  // namespace andromeda
// NOLINTEND
