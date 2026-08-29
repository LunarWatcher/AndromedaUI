// Copyright 2022 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <string>  // for allocator, string

#include "andromeda/dom/elements.hpp"   // for operator|, text, blink, Element
#include "andromeda/dom/node.hpp"       // for Render
#include "andromeda/screen/screen.hpp"  // for Screen, Pixel
#include "catch2/catch_test_macros.hpp"  // for Test, AssertionResult, EXPECT_TRUE, Message, TEST, TestPartResult
#include <migrate/GTestCompat.hpp>

// NOLINTBEGIN
namespace andromeda {

TEST(BlinkTest, Basic) {
  auto element = text("text") | blink;
  Screen screen(5, 1);
  Render(screen, element);
  REQUIRE(true == screen.PixelAt(0, 0).blink);
}

}  // namespace andromeda
// NOLINTEND
