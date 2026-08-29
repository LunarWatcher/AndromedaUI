// Copyright 2022 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <string>  // for allocator, string

#include "andromeda/dom/elements.hpp"   // for operator|, text, dim, Element
#include "andromeda/dom/node.hpp"       // for Render
#include "andromeda/screen/screen.hpp"  // for Screen, Pixel
#include "catch2/catch_test_macros.hpp"  // for Test, AssertionResult, EXPECT_TRUE, Message, TEST, TestPartResult
#include <migrate/GTestCompat.hpp>

// NOLINTBEGIN
namespace andromeda {

TEST(DimTest, Basic) {
  auto element = text("text") | dim;
  Screen screen(5, 1);
  Render(screen, element);
  REQUIRE(true == screen.PixelAt(0, 0).dim);
}

}  // namespace andromeda
// NOLINTEND
