// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <functional>  // for function
#include <string>      // for string, basic_string
#include <vector>      // for vector

#include "andromeda/component/component.hpp"          // for Menu, Toggle
#include "andromeda/component/component_base.hpp"     // for ComponentBase
#include "andromeda/component/component_options.hpp"  // for MenuOption
#include "andromeda/component/event.hpp"  // for Event, Event::ArrowLeft, Event::ArrowRight, Event::Return, Event::Tab, Event::TabReverse
#include "andromeda/util/ref.hpp"         // for Ref
#include "catch2/catch_test_macros.hpp"  // for AssertionResult, Message, TestPartResult, EXPECT_EQ, Test, EXPECT_TRUE, REQUIRE_FALSE, TEST
#include <migrate/GTestCompat.hpp>

// NOLINTBEGIN
namespace andromeda {

TEST(ToggleTest, leftRightArrow) {
  std::vector<std::string> entries = {"On", "Off"};
  int selected = 0;
  auto toggle = Toggle(&entries, &selected);

  // With arrow key.
  EXPECT_EQ(selected, 0);
  toggle->OnEvent(Event::ArrowRight);
  EXPECT_EQ(selected, 1);
  toggle->OnEvent(Event::ArrowRight);
  EXPECT_EQ(selected, 1);
  toggle->OnEvent(Event::ArrowLeft);
  EXPECT_EQ(selected, 0);
  toggle->OnEvent(Event::ArrowLeft);
  EXPECT_EQ(selected, 0);

  // With vim like characters.
  EXPECT_EQ(selected, 0);
  toggle->OnEvent(Event::Character('l'));
  EXPECT_EQ(selected, 1);
  toggle->OnEvent(Event::Character('l'));
  EXPECT_EQ(selected, 1);
  toggle->OnEvent(Event::Character('h'));
  EXPECT_EQ(selected, 0);
  toggle->OnEvent(Event::Character('h'));
  EXPECT_EQ(selected, 0);

  // With more entries
  entries = {"1", "2", "3"};
  EXPECT_EQ(selected, 0);
  toggle->OnEvent(Event::ArrowRight);
  EXPECT_EQ(selected, 1);
  toggle->OnEvent(Event::ArrowRight);
  EXPECT_EQ(selected, 2);
  toggle->OnEvent(Event::ArrowRight);
  EXPECT_EQ(selected, 2);
  toggle->OnEvent(Event::ArrowLeft);
  EXPECT_EQ(selected, 1);
  toggle->OnEvent(Event::ArrowLeft);
  EXPECT_EQ(selected, 0);
  toggle->OnEvent(Event::ArrowLeft);
  EXPECT_EQ(selected, 0);
}

TEST(ToggleTest, Tab) {
  std::vector<std::string> entries = {"1", "2", "3"};
  int selected = 0;
  auto toggle = Toggle(&entries, &selected);

  EXPECT_EQ(selected, 0);
  toggle->OnEvent(Event::Tab);
  EXPECT_EQ(selected, 1);
  toggle->OnEvent(Event::Tab);
  EXPECT_EQ(selected, 2);
  toggle->OnEvent(Event::Tab);
  EXPECT_EQ(selected, 0);
  toggle->OnEvent(Event::Tab);
  EXPECT_EQ(selected, 1);
  toggle->OnEvent(Event::Tab);
  EXPECT_EQ(selected, 2);
  toggle->OnEvent(Event::TabReverse);
  EXPECT_EQ(selected, 1);
  toggle->OnEvent(Event::TabReverse);
  EXPECT_EQ(selected, 0);
  toggle->OnEvent(Event::TabReverse);
  EXPECT_EQ(selected, 2);
  toggle->OnEvent(Event::TabReverse);
  EXPECT_EQ(selected, 1);
  toggle->OnEvent(Event::TabReverse);
}

TEST(ToggleTest, OnChange) {
  std::vector<std::string> entries = {"1", "2", "3"};
  int selected = 0;
  int counter = 0;
  auto option = MenuOption::Toggle();
  option.on_change = [&] { counter++; };

  auto toggle = Menu(&entries, &selected, option);

  REQUIRE_FALSE(toggle->OnEvent(Event::ArrowLeft));  // Reached far left.
  EXPECT_EQ(counter, 0);

  REQUIRE(true == toggle->OnEvent(Event::ArrowRight));  // [0] -> [1]
  EXPECT_EQ(counter, 1);
  REQUIRE(true == toggle->OnEvent(Event::ArrowRight));  // [1] -> [2]
  EXPECT_EQ(counter, 2);

  REQUIRE_FALSE(toggle->OnEvent(Event::ArrowRight));  // Reached far right.
  EXPECT_EQ(counter, 2);

  REQUIRE(true == toggle->OnEvent(Event::ArrowLeft));  // [2] -> [1]
  EXPECT_EQ(counter, 3);
  REQUIRE(true == toggle->OnEvent(Event::ArrowLeft));  // [1] -> [0]
  EXPECT_EQ(counter, 4);

  REQUIRE_FALSE(toggle->OnEvent(Event::ArrowLeft));  // Reached far left.
  EXPECT_EQ(counter, 4);
}

TEST(ToggleTest, OnEnter) {
  std::vector<std::string> entries = {"1", "2", "3"};
  int selected = 0;
  int counter = 0;

  auto option = MenuOption::Toggle();
  option.on_enter = [&] { counter++; };
  auto toggle = Menu(&entries, &selected, option);

  REQUIRE_FALSE(toggle->OnEvent(Event::ArrowLeft));  // Reached far left.
  REQUIRE(true == toggle->OnEvent(Event::Return));
  EXPECT_EQ(counter, 1);

  REQUIRE(true == toggle->OnEvent(Event::ArrowRight));  // [0] -> [1]
  REQUIRE(true == toggle->OnEvent(Event::Return));
  EXPECT_EQ(counter, 2);
  REQUIRE(true == toggle->OnEvent(Event::ArrowRight));  // [1] -> [2]
  REQUIRE(true == toggle->OnEvent(Event::Return));
  EXPECT_EQ(counter, 3);

  REQUIRE_FALSE(toggle->OnEvent(Event::ArrowRight));  // Reached far right.
  REQUIRE(true == toggle->OnEvent(Event::Return));
  EXPECT_EQ(counter, 4);

  REQUIRE(true == toggle->OnEvent(Event::ArrowLeft));  // [2] -> [1]
  REQUIRE(true == toggle->OnEvent(Event::Return));
  EXPECT_EQ(counter, 5);
  REQUIRE(true == toggle->OnEvent(Event::ArrowLeft));  // [1] -> [0]
  REQUIRE(true == toggle->OnEvent(Event::Return));
  EXPECT_EQ(counter, 6);

  REQUIRE_FALSE(toggle->OnEvent(Event::ArrowLeft));  // Reached far left.
  REQUIRE(true == toggle->OnEvent(Event::Return));
  EXPECT_EQ(counter, 7);
}

TEST(ToggleTest, RemoveEntries) {
  int focused_entry = 0;
  int selected = 0;
  std::vector<std::string> entries = {"1", "2", "3"};
  auto option = MenuOption::Toggle();
  option.focused_entry = &focused_entry;
  auto toggle = Menu(&entries, &selected, option);

  EXPECT_EQ(selected, 0);
  EXPECT_EQ(focused_entry, 0);

  toggle->OnEvent(Event::ArrowRight);
  toggle->OnEvent(Event::ArrowRight);

  EXPECT_EQ(selected, 2);
  EXPECT_EQ(focused_entry, 2);

  entries.resize(2);

  EXPECT_EQ(selected, 2);
  EXPECT_EQ(focused_entry, 2);

  (void)toggle->Render();

  EXPECT_EQ(selected, 1);
  EXPECT_EQ(focused_entry, 1);
}

}  // namespace andromeda
// NOLINTEND
