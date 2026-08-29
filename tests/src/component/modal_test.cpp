// Copyright 2022 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <catch2/catch_test_macros.hpp>
#include <migrate/GTestCompat.hpp>
#include <andromeda/dom/elements.hpp>  // for Element, operator|, text, border

#include "andromeda/component/component.hpp"       // for Renderer, Modal
#include "andromeda/component/component_base.hpp"  // for ComponentBase
#include "andromeda/dom/node.hpp"                  // for Render
#include "andromeda/screen/screen.hpp"             // for Screen

// NOLINTBEGIN
namespace andromeda {

TEST(ModalTest, Basic) {
  auto main = Renderer([] { return text("main") | border; });
  auto modal = Renderer([] { return text("modal") | border; });
  bool show_modal = false;
  auto component = Modal(main, modal, &show_modal);

  Screen screen(10, 7);
  Render(screen, component->Render());
  EXPECT_EQ(screen.ToString(),
            "╭────────╮\r\n"
            "│main    │\r\n"
            "│        │\r\n"
            "│        │\r\n"
            "│        │\r\n"
            "│        │\r\n"
            "╰────────╯");

  show_modal = true;
  Render(screen, component->Render());
  EXPECT_EQ(screen.ToString(),
            "╭────────╮\r\n"
            "│main    │\r\n"
            "│╭─────╮ │\r\n"
            "││modal│ │\r\n"
            "│╰─────╯ │\r\n"
            "│        │\r\n"
            "╰────────╯");
}

}  // namespace andromeda
// NOLINTEND
