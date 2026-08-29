// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#ifndef ANDROMEDAUI_COMPONENT_TERMINAL_INPUT_PARSER
#define ANDROMEDAUI_COMPONENT_TERMINAL_INPUT_PARSER

#include <string>  // for string
#include <vector>  // for vector

#include "andromeda/component/mouse.hpp"     // for Mouse
#include "andromeda/component/receiver.hpp"  // for Sender
#include "andromeda/component/task.hpp"      // for Task

namespace andromeda {
struct Event;

// Parse a sequence of |char| accross |time|. Produces |Event|.
class TerminalInputParser {
 public:
  explicit TerminalInputParser(Sender<Task> out);
  void Timeout(int time);
  void Add(char c);

 private:
  unsigned char Current();
  bool Eat();

  enum Type {
    UNCOMPLETED,
    DROP,
    CHARACTER,
    MOUSE,
    CURSOR_POSITION,
    CURSOR_SHAPE,
    SPECIAL,
  };

  struct CursorPosition {
    int x;
    int y;
  };

  struct Output {
    Type type;
    union {
      Mouse mouse;
      CursorPosition cursor{};
      int cursor_shape;
    };

    Output(Type t)  // NOLINT
        : type(t) {}
  };

  void Send(Output output);
  Output Parse();
  Output ParseUTF8();
  Output ParseESC();
  Output ParseDCS();
  Output ParseCSI();
  Output ParseOSC();
  Output ParseMouse(bool altered, bool pressed, std::vector<int> arguments);
  Output ParseCursorPosition(std::vector<int> arguments);

  Sender<Task> out_;
  int position_ = -1;
  int timeout_ = 0;
  std::string pending_;
};

}  // namespace andromeda

#endif /* end of include guard: ANDROMEDAUI_COMPONENT_TERMINAL_INPUT_PARSER */
