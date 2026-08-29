// Copyright 2022 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#ifndef ANDROMEDAUI_COMPONENT_LOOP_HPP
#define ANDROMEDAUI_COMPONENT_LOOP_HPP

#include <memory>  // for shared_ptr

#include "andromeda/component/component_base.hpp"  // for ComponentBase

namespace andromeda {
class ComponentBase;

using Component = std::shared_ptr<ComponentBase>;
class ScreenInteractive;

class Loop {
 public:
  Loop(ScreenInteractive* screen, Component component);
  ~Loop();

  bool HasQuitted();
  void RunOnce();
  void RunOnceBlocking();
  void Run();

  // This class is non copyable/movable.
  Loop(const Loop&) = default;
  Loop(Loop&&) = delete;
  Loop& operator=(Loop&&) = delete;
  Loop(const ScreenInteractive&) = delete;
  Loop& operator=(const Loop&) = delete;

 private:
  ScreenInteractive* screen_;
  Component component_;
};

}  // namespace andromeda

#endif  // ANDROMEDAUI_COMPONENT_LOOP_HPP
