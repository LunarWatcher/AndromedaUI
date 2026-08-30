// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <memory>  // for shared_ptr, __shared_ptr_access
#include <string>  // for string, basic_string, operator+, to_string
#include <vector>  // for vector

#include "andromeda/component/captured_mouse.hpp"      // for andromeda
#include "andromeda/component/component.hpp"           // for Radiobox, Renderer
#include "andromeda/component/component_base.hpp"      // for ComponentBase
#include "andromeda/component/screen_interactive.hpp"  // for ScreenInteractive
#include "andromeda/dom/elements.hpp"  // for operator|, Element, size, border, frame, HEIGHT, LESS_THAN

using namespace andromeda;

int main() {
    std::vector<std::string> entries;
    int selected = 0;

    entries.reserve(30);
    for (int i = 0; i < 30; ++i) {
        entries.push_back("RadioBox " + std::to_string(i));
    }
    auto radiobox = Radiobox(&entries, &selected);
    auto renderer = Renderer(radiobox, [&] {
        return radiobox->Render() | vscroll_indicator | frame |
            size(HEIGHT, LESS_THAN, 10) | border;
    });

    auto screen = ScreenInteractive::FitComponent();
    screen.Loop(renderer);

    return 0;
}
