// Copyright 2022 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <andromeda/dom/direction.hpp>  // for Direction, Direction::Down, Direction::Left, Direction::Right, Direction::Up
#include <string>                   // for string

#include "andromeda/component/component.hpp"  // for ResizableSplit, Renderer, ResizableSplitBottom, ResizableSplitLeft, ResizableSplitRight, ResizableSplitTop
#include "andromeda/component/component_base.hpp"  // for ComponentBase, Component
#include "andromeda/component/event.hpp"           // for Event
#include "andromeda/component/mouse.hpp"  // for Mouse, Mouse::Left, Mouse::Pressed, Mouse::Released
#include "andromeda/dom/elements.hpp"   // for Element, separatorDouble, text
#include "andromeda/dom/node.hpp"       // for Render
#include "andromeda/screen/screen.hpp"  // for Screen
#include "catch2/catch_test_macros.hpp"  // for AssertionResult, Message, TestPartResult, Test, EXPECT_EQ, EXPECT_TRUE, TEST
#include <migrate/GTestCompat.hpp>

// NOLINTBEGIN
namespace andromeda {

namespace {
Component BasicComponent() {
  return Renderer([](bool focused) { return text(""); });
}

Event MousePressed(int x, int y) {
  Mouse mouse;
  mouse.button = Mouse::Left;
  mouse.motion = Mouse::Pressed;
  mouse.shift = false;
  mouse.meta = false;
  mouse.control = false;
  mouse.x = x;
  mouse.y = y;
  return Event::Mouse("jjj", mouse);
}

Event MouseReleased(int x, int y) {
  Mouse mouse;
  mouse.button = Mouse::Left;
  mouse.motion = Mouse::Released;
  mouse.shift = false;
  mouse.meta = false;
  mouse.control = false;
  mouse.x = x;
  mouse.y = y;
  return Event::Mouse("jjj", mouse);
}
}  // namespace

TEST(ResizableSplit, BasicLeft) {
  int position = 3;
  auto component =
      ResizableSplitLeft(BasicComponent(), BasicComponent(), &position);
  auto screen = Screen(20, 20);
  Render(screen, component->Render());
  EXPECT_EQ(position, 3);
  REQUIRE(true == component->OnEvent(MousePressed(3, 1)));
  EXPECT_EQ(position, 3);
  REQUIRE(true == component->OnEvent(MousePressed(10, 1)));
  EXPECT_EQ(position, 10);
  REQUIRE(true == component->OnEvent(MouseReleased(10, 1)));
  EXPECT_EQ(position, 10);
}

TEST(ResizableSplit, BasicLeftWithCustomSeparator) {
  int position = 1;
  auto component = ResizableSplit({
      .main = BasicComponent(),
      .back = BasicComponent(),
      .direction = Direction::Left,
      .main_size = &position,
      .separator_func = [] { return separatorDouble(); },
  });
  auto screen = Screen(4, 4);
  Render(screen, component->Render());
  EXPECT_EQ(position, 1);
  EXPECT_EQ(screen.ToString(),
            " ║  \r\n"
            " ║  \r\n"
            " ║  \r\n"
            " ║  ");
  REQUIRE(true == component->OnEvent(MousePressed(1, 1)));
  EXPECT_EQ(position, 1);
  REQUIRE(true == component->OnEvent(MousePressed(2, 1)));
  EXPECT_EQ(position, 2);
  REQUIRE(true == component->OnEvent(MouseReleased(2, 1)));
  EXPECT_EQ(position, 2);
}

TEST(ResizableSplit, BasicRight) {
  int position = 3;
  auto component =
      ResizableSplitRight(BasicComponent(), BasicComponent(), &position);
  auto screen = Screen(20, 20);
  Render(screen, component->Render());
  EXPECT_EQ(position, 3);
  REQUIRE(true == component->OnEvent(MousePressed(16, 1)));
  EXPECT_EQ(position, 3);
  REQUIRE(true == component->OnEvent(MousePressed(10, 1)));
  EXPECT_EQ(position, 9);
  REQUIRE(true == component->OnEvent(MouseReleased(10, 1)));
  EXPECT_EQ(position, 9);
}

TEST(ResizableSplit, BasicRightWithCustomSeparator) {
  int position = 1;
  auto component = ResizableSplit({
      .main = BasicComponent(),
      .back = BasicComponent(),
      .direction = Direction::Right,
      .main_size = &position,
      .separator_func = [] { return separatorDouble(); },
  });
  auto screen = Screen(4, 4);
  Render(screen, component->Render());
  EXPECT_EQ(position, 1);
  EXPECT_EQ(screen.ToString(),
            "  ║ \r\n"
            "  ║ \r\n"
            "  ║ \r\n"
            "  ║ ");
  REQUIRE(true == component->OnEvent(MousePressed(2, 1)));
  EXPECT_EQ(position, 1);
  REQUIRE(true == component->OnEvent(MousePressed(1, 1)));
  EXPECT_EQ(position, 2);
  REQUIRE(true == component->OnEvent(MouseReleased(1, 1)));
  EXPECT_EQ(position, 2);
}

TEST(ResizableSplit, BasicTop) {
  int position = 3;
  auto component =
      ResizableSplitTop(BasicComponent(), BasicComponent(), &position);
  auto screen = Screen(20, 20);
  Render(screen, component->Render());
  EXPECT_EQ(position, 3);
  REQUIRE(true == component->OnEvent(MousePressed(1, 3)));
  EXPECT_EQ(position, 3);
  REQUIRE(true == component->OnEvent(MousePressed(1, 10)));
  EXPECT_EQ(position, 10);
  REQUIRE(true == component->OnEvent(MouseReleased(1, 10)));
  EXPECT_EQ(position, 10);
}

TEST(ResizableSplit, BasicTopWithCustomSeparator) {
  int position = 1;
  auto component = ResizableSplit({
      .main = BasicComponent(),
      .back = BasicComponent(),
      .direction = Direction::Up,
      .main_size = &position,
      .separator_func = [] { return separatorDouble(); },
  });
  auto screen = Screen(4, 4);
  Render(screen, component->Render());
  EXPECT_EQ(position, 1);
  EXPECT_EQ(screen.ToString(),
            "    \r\n"
            "════\r\n"
            "    \r\n"
            "    ");
  REQUIRE(true == component->OnEvent(MousePressed(1, 1)));
  EXPECT_EQ(position, 1);
  REQUIRE(true == component->OnEvent(MousePressed(1, 2)));
  EXPECT_EQ(position, 2);
  REQUIRE(true == component->OnEvent(MouseReleased(1, 2)));
  EXPECT_EQ(position, 2);
}

TEST(ResizableSplit, BasicBottom) {
  int position = 3;
  auto component =
      ResizableSplitBottom(BasicComponent(), BasicComponent(), &position);
  auto screen = Screen(20, 20);
  Render(screen, component->Render());
  EXPECT_EQ(position, 3);
  REQUIRE(true == component->OnEvent(MousePressed(1, 16)));
  EXPECT_EQ(position, 3);
  REQUIRE(true == component->OnEvent(MousePressed(1, 10)));
  EXPECT_EQ(position, 9);
  REQUIRE(true == component->OnEvent(MouseReleased(1, 10)));
  EXPECT_EQ(position, 9);
}

TEST(ResizableSplit, BasicBottomWithCustomSeparator) {
  int position = 1;
  auto component = ResizableSplit({
      .main = BasicComponent(),
      .back = BasicComponent(),
      .direction = Direction::Down,
      .main_size = &position,
      .separator_func = [] { return separatorDouble(); },
  });
  auto screen = Screen(4, 4);
  Render(screen, component->Render());
  EXPECT_EQ(position, 1);
  EXPECT_EQ(screen.ToString(),
            "    \r\n"
            "    \r\n"
            "════\r\n"
            "    ");
  REQUIRE(true == component->OnEvent(MousePressed(1, 2)));
  EXPECT_EQ(position, 1);
  REQUIRE(true == component->OnEvent(MousePressed(1, 1)));
  EXPECT_EQ(position, 2);
  REQUIRE(true == component->OnEvent(MouseReleased(1, 1)));
  EXPECT_EQ(position, 2);
}

TEST(ResizableSplit, NavigationVertical) {
  int position = 0;
  auto component_top = BasicComponent();
  auto component_bottom = BasicComponent();
  auto component =
      ResizableSplitTop(component_top, component_bottom, &position);

  REQUIRE(true == component_top->Active());
  REQUIRE_FALSE(component_bottom->Active());

  REQUIRE_FALSE(component->OnEvent(Event::ArrowRight));
  REQUIRE(true == component_top->Active());
  REQUIRE_FALSE(component_bottom->Active());

  REQUIRE(true == component->OnEvent(Event::ArrowDown));
  REQUIRE_FALSE(component_top->Active());
  REQUIRE(true == component_bottom->Active());

  REQUIRE_FALSE(component->OnEvent(Event::ArrowDown));
  REQUIRE_FALSE(component_top->Active());
  REQUIRE(true == component_bottom->Active());

  REQUIRE(true == component->OnEvent(Event::ArrowUp));
  REQUIRE(true == component_top->Active());
  REQUIRE_FALSE(component_bottom->Active());
}

}  // namespace andromeda
// NOLINTEND
