// Copyright 2023 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <memory>   // for make_shared
#include <utility>  // for move

#include "andromeda/dom/elements.hpp"        // for Element, underlinedDouble
#include "andromeda/dom/node.hpp"            // for Node
#include "andromeda/dom/node_decorator.hpp"  // for NodeDecorator
#include "andromeda/screen/box.hpp"          // for Box
#include "andromeda/screen/screen.hpp"       // for Pixel, Screen

namespace andromeda {

/// @brief Apply a underlinedDouble to text.
/// @ingroup dom
Element underlinedDouble(Element child) {
  class Impl : public NodeDecorator {
   public:
    using NodeDecorator::NodeDecorator;

    void Render(Screen& screen) override {
      for (int y = box_.y_min; y <= box_.y_max; ++y) {
        for (int x = box_.x_min; x <= box_.x_max; ++x) {
          screen.PixelAt(x, y).underlined_double = true;
        }
      }
      Node::Render(screen);
    }
  };

  return std::make_shared<Impl>(std::move(child));
}

}  // namespace andromeda
