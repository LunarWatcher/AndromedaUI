#include <string>  // for string

#include "andromeda/component/component.hpp"       // for Collapsible, Renderer
#include "andromeda/component/component_base.hpp"  // for ComponentBase
#include "andromeda/component/event.hpp"  // for Event, Event::Return, Event::ArrowDown
#include "andromeda/dom/elements.hpp"     // for Element, text
#include "andromeda/dom/node.hpp"         // for Render
#include "andromeda/screen/screen.hpp"  // for Screen
#include "catch2/catch_test_macros.hpp"  // for AssertionResult, Message, Test, TestPartResult, EXPECT_EQ, REQUIRE_FALSE, EXPECT_TRUE, TEST
#include <migrate/GTestCompat.hpp>

// NOLINTBEGIN
namespace andromeda {

TEST(CollapsibleTest, Basic) {
  auto child = Renderer([] { return text("child"); });
  bool show = false;
  auto collapsible = Collapsible("parent", child, &show);

  REQUIRE(true == collapsible->Focused());
  REQUIRE_FALSE(child->Focused());
  REQUIRE_FALSE(collapsible->OnEvent(Event::ArrowDown));
  REQUIRE(true == collapsible->Focused());
  REQUIRE_FALSE(child->Focused());

  {
    Screen screen(8, 3);
    Render(screen, collapsible->Render());
    EXPECT_EQ(screen.ToString(),
              "\xE2\x96\xB6 \x1B[1m\x1B[7mparent\x1B[22m\x1B[27m\r\n"
              "        \r\n"
              "        ");
  }

  collapsible->OnEvent(Event::Return);
  EXPECT_EQ(show, true);

  {
    Screen screen(8, 3);
    Render(screen, collapsible->Render());
    EXPECT_EQ(screen.ToString(),
              "\xE2\x96\xBC \x1B[1m\x1B[7mparent\x1B[22m\x1B[27m\r\n"
              "child   \r\n"
              "        ");
  }

  collapsible->OnEvent(Event::Return);
  EXPECT_EQ(show, false);
}

}  // namespace andromeda
// NOLINTEND

// Copyright 2022 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
