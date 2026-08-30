// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <memory>   // for allocator, make_shared, __shared_ptr_access
#include <utility>  // for move
#include <vector>   // for vector

#include "andromeda/component/captured_mouse.hpp"  // for andromeda
#include "andromeda/component/component.hpp"  // for Collapsible, Renderer, Vertical
#include "andromeda/component/component_base.hpp"  // for ComponentBase
#include "andromeda/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "andromeda/dom/elements.hpp"                  // for text, hbox, Element

using namespace andromeda;

// Take a list of component, display them vertically, one column shifted to the
// right.
static Component Inner(std::vector<Component> children) {
    Component vlist = Container::Vertical(std::move(children));
    return Renderer(vlist, [vlist] {
        return hbox({
                text(" "),
                vlist->Render(),
            });
    });
}

static Component Empty() {
    return std::make_shared<ComponentBase>();
}

int main() {
    auto component =
        Collapsible("Collapsible 1",
            Inner({
                    Collapsible("Collapsible 1.1",
                        Inner({
                                Collapsible("Collapsible 1.1.1", Empty()),
                                Collapsible("Collapsible 1.1.2", Empty()),
                                Collapsible("Collapsible 1.1.3", Empty()),
                            })),
                    Collapsible("Collapsible 1.2",
                        Inner({
                                Collapsible("Collapsible 1.2.1", Empty()),
                                Collapsible("Collapsible 1.2.2", Empty()),
                                Collapsible("Collapsible 1.2.3", Empty()),
                            })),
                    Collapsible("Collapsible 1.3",
                        Inner({
                                Collapsible("Collapsible 1.3.1", Empty()),
                                Collapsible("Collapsible 1.3.2", Empty()),
                                Collapsible("Collapsible 1.3.3", Empty()),
                            })),
                }));

    ScreenInteractive::FitComponent().Loop(component);
}
