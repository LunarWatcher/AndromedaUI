// Copyright 2025 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.

#include "andromeda/component/component.hpp"  // for Horizontal, Vertical, Button, Tab
#include "andromeda/component/component_base.hpp"  // for ComponentBase, Component
#include "andromeda/component/event.hpp"  // for Event, Event::Tab, Event::TabReverse, Event::ArrowDown, Event::ArrowLeft, Event::ArrowRight, Event::ArrowUp
#include "catch2/catch_test_macros.hpp"  // for AssertionResult, Message, TestPartResult, EXPECT_EQ, REQUIRE_FALSE, Test, EXPECT_TRUE, TEST
#include <migrate/GTestCompat.hpp>

namespace andromeda {

TEST(DropdownTest, Empty) {
  std::vector<std::string> list = {};
  int index = 0;
  auto dropdown = Dropdown(list, &index);

  dropdown->OnEvent(Event::Return);

  auto screen = Screen(8, 8);
  auto document = dropdown->Render();
  Render(screen, document);

  EXPECT_EQ(screen.ToString(),
            "╭──────╮\r\n"
            "│↓     │\r\n"
            "├──────┤\r\n"
            "│      │\r\n"
            "│      │\r\n"
            "│      │\r\n"
            "│      │\r\n"
            "╰──────╯");
}

}  // namespace andromeda
