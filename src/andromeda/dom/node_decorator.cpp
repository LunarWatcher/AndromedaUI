// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <andromeda/dom/node.hpp>  // for Node, Elements

#include "andromeda/dom/node_decorator.hpp"
#include "andromeda/dom/requirement.hpp"  // for Requirement
#include "andromeda/screen/box.hpp"       // for Box

namespace andromeda {

void NodeDecorator::ComputeRequirement() {
  Node::ComputeRequirement();
  requirement_ = children_[0]->requirement();
}

void NodeDecorator::SetBox(Box box) {
  Node::SetBox(box);
  children_[0]->SetBox(box);
}

}  // namespace andromeda
