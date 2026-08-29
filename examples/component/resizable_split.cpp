// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <memory>  // for shared_ptr, allocator, __shared_ptr_access

#include "andromeda/component/captured_mouse.hpp"  // for andromeda
#include "andromeda/component/component.hpp"  // for Renderer, ResizableSplitBottom, ResizableSplitLeft, ResizableSplitRight, ResizableSplitTop
#include "andromeda/component/component_base.hpp"      // for ComponentBase
#include "andromeda/component/screen_interactive.hpp"  // for ScreenInteractive
#include "andromeda/dom/elements.hpp"  // for Element, operator|, text, center, border

using namespace andromeda;

int main() {
  auto screen = ScreenInteractive::Fullscreen();

  auto middle = Renderer([] { return text("middle") | center; });
  auto left = Renderer([] { return text("Left") | center; });
  auto right = Renderer([] { return text("right") | center; });
  auto top = Renderer([] { return text("top") | center; });
  auto bottom = Renderer([] { return text("bottom") | center; });

  int left_size = 20;
  int right_size = 20;
  int top_size = 10;
  int bottom_size = 10;

  auto container = middle;
  container = ResizableSplitLeft(left, container, &left_size);
  container = ResizableSplitRight(right, container, &right_size);
  container = ResizableSplitTop(top, container, &top_size);
  container = ResizableSplitBottom(bottom, container, &bottom_size);

  auto renderer =
      Renderer(container, [&] { return container->Render() | border; });

  screen.Loop(renderer);
}
