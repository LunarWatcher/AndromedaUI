// Copyright 2021 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <functional>  // for function
#include <utility>     // for move

#include "andromeda/component/component.hpp"  // for Checkbox, Maybe, Make, Vertical, Collapsible
#include "andromeda/component/component_base.hpp"  // for Component, ComponentBase
#include "andromeda/component/component_options.hpp"  // for CheckboxOption, EntryState
#include "andromeda/dom/elements.hpp"  // for operator|=, text, hbox, Element, bold, inverted
#include "andromeda/util/ref.hpp"  // for Ref, ConstStringRef

namespace andromeda {

/// @brief A collapsible component. It displays a checkbox with an arrow. Once
/// activated, the child is displayed.
/// @param label The label of the checkbox.
/// @param child The child to display.
/// @param show Hold the state about whether the child is displayed or not.
///
/// ### Example
/// ```cpp
/// auto component = Collapsible("Show details", details);
/// ```
///
/// ### Output
/// ```
///
/// ▼ Show details
/// <details component>
/// ```
// NOLINTNEXTLINE
Component Collapsible(ConstStringRef label, Component child, Ref<bool> show) {
  class Impl : public ComponentBase {
   public:
    Impl(ConstStringRef label, Component child, Ref<bool> show) : show_(show) {
      CheckboxOption opt;
      opt.transform = [](EntryState s) {            // NOLINT
        auto prefix = text(s.state ? "▼ " : "▶ ");  // NOLINT
        auto t = text(s.label);
        if (s.active) {
          t |= bold;
        }
        if (s.focused) {
          t |= inverted;
        }
        return hbox({prefix, t});
      };
      Add(Container::Vertical({
          Checkbox(std::move(label), show_.operator->(), opt),
          Maybe(std::move(child), show_.operator->()),
      }));
    }
    Ref<bool> show_;
  };

  return Make<Impl>(std::move(label), std::move(child), show);
}

}  // namespace andromeda
