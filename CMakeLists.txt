option(ANDROMEDAUI_BUILD_TESTS "Set to ON to build tests" OFF)
option(ANDROMEDAUI_BUILD_EXAMPLES "Set to ON to build examples" OFF)
option(ANDROMEDAUI_CLANG_TIDY "Execute clang-tidy" OFF)
option(ANDROMEDAUI_DEV_WARNINGS "Enable more compiler warnings and warnings as errors" OFF)
option(ANDROMEDAUI_ENABLE_COVERAGE "Execute code coverage" OFF)
option(ANDROMEDAUI_ENABLE_INSTALL "Generate the install target" ON)
option(ANDROMEDAUI_QUIET "Set to ON for FTXUI to be quiet" OFF)

cmake_minimum_required(VERSION 3.28.2)

project(AndromedaUI
  LANGUAGES CXX
  VERSION 1.0.0
  DESCRIPTION "C++ Functional Terminal User Interface."
)


set(ANDROMEDAUI_MICROSOFT_TERMINAL_FALLBACK_HELP_TEXT "On windows, assume the \
terminal used will be one of Microsoft and use a set of reasonnable fallback \
to counteract its implementations problems.")
if (WIN32)
  option(ANDROMEDAUI_MICROSOFT_TERMINAL_FALLBACK
    ${ANDROMEDAUI_MICROSOFT_TERMINAL_FALLBACK_HELP_TEXT} ON)
else()
  option(ANDROMEDAUI_MICROSOFT_TERMINAL_FALLBACK
    ${ANDROMEDAUI_MICROSOFT_TERMINAL_FALLBACK_HELP_TEXT} OFF)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/andromeda_message.cmake)

add_library(screen
  src/andromeda/screen/box.cpp
  src/andromeda/screen/color.cpp
  src/andromeda/screen/color_info.cpp
  src/andromeda/screen/image.cpp
  src/andromeda/screen/screen.cpp
  src/andromeda/screen/string.cpp
  src/andromeda/screen/terminal.cpp
  src/andromeda/screen/util.hpp
)

add_library(dom
  src/andromeda/dom/automerge.cpp
  src/andromeda/dom/selection_style.cpp
  src/andromeda/dom/blink.cpp
  src/andromeda/dom/bold.cpp
  src/andromeda/dom/border.cpp
  src/andromeda/dom/box_helper.cpp
  src/andromeda/dom/box_helper.hpp
  src/andromeda/dom/canvas.cpp
  src/andromeda/dom/clear_under.cpp
  src/andromeda/dom/color.cpp
  src/andromeda/dom/composite_decorator.cpp
  src/andromeda/dom/dbox.cpp
  src/andromeda/dom/dim.cpp
  src/andromeda/dom/flex.cpp
  src/andromeda/dom/flexbox.cpp
  src/andromeda/dom/flexbox_config.cpp
  src/andromeda/dom/flexbox_helper.cpp
  src/andromeda/dom/flexbox_helper.hpp
  src/andromeda/dom/focus.cpp
  src/andromeda/dom/frame.cpp
  src/andromeda/dom/gauge.cpp
  src/andromeda/dom/graph.cpp
  src/andromeda/dom/gridbox.cpp
  src/andromeda/dom/hbox.cpp
  src/andromeda/dom/hyperlink.cpp
  src/andromeda/dom/inverted.cpp
  src/andromeda/dom/italic.cpp
  src/andromeda/dom/linear_gradient.cpp
  src/andromeda/dom/node.cpp
  src/andromeda/dom/node_decorator.cpp
  src/andromeda/dom/paragraph.cpp
  src/andromeda/dom/reflect.cpp
  src/andromeda/dom/scroll_indicator.cpp
  src/andromeda/dom/selection.cpp
  src/andromeda/dom/separator.cpp
  src/andromeda/dom/size.cpp
  src/andromeda/dom/spinner.cpp
  src/andromeda/dom/strikethrough.cpp
  src/andromeda/dom/table.cpp
  src/andromeda/dom/text.cpp
  src/andromeda/dom/underlined.cpp
  src/andromeda/dom/underlined_double.cpp
  src/andromeda/dom/util.cpp
  src/andromeda/dom/vbox.cpp
)

add_library(component
  src/andromeda/component/animation.cpp
  src/andromeda/component/button.cpp
  src/andromeda/component/catch_event.cpp
  src/andromeda/component/checkbox.cpp
  src/andromeda/component/collapsible.cpp
  src/andromeda/component/component.cpp
  src/andromeda/component/component_options.cpp
  src/andromeda/component/container.cpp
  src/andromeda/component/dropdown.cpp
  src/andromeda/component/event.cpp
  src/andromeda/component/hoverable.cpp
  src/andromeda/component/input.cpp
  src/andromeda/component/loop.cpp
  src/andromeda/component/maybe.cpp
  src/andromeda/component/menu.cpp
  src/andromeda/component/modal.cpp
  src/andromeda/component/radiobox.cpp
  src/andromeda/component/radiobox.cpp
  src/andromeda/component/renderer.cpp
  src/andromeda/component/resizable_split.cpp
  src/andromeda/component/screen_interactive.cpp
  src/andromeda/component/slider.cpp
  src/andromeda/component/terminal_input_parser.cpp
  src/andromeda/component/terminal_input_parser.hpp
  src/andromeda/component/util.cpp
  src/andromeda/component/window.cpp
)

target_include_directories(component PUBLIC ./src)
target_include_directories(dom PUBLIC ./src)
target_include_directories(screen PUBLIC ./src)

target_link_libraries(dom
  PUBLIC screen
)

target_link_libraries(component
  PUBLIC dom
)

if (NOT EMSCRIPTEN)
  find_package(Threads)
  target_link_libraries(component
    PUBLIC Threads::Threads
  )
endif()

include(cmake/andromeda_set_options.cmake)
andromeda_set_options(screen)
andromeda_set_options(dom)
andromeda_set_options(component)

include(cmake/iwyu.cmake)
include(cmake/andromeda_export.cmake)

add_subdirectory(examples)

if (ANDROMEDAUI_BUILD_TESTS)
    add_subdirectory(tests EXCLUDE_FROM_ALL)
    add_custom_target(test
        COMMAND tests
        DEPENDS tests
        COMMENT "Test Andromeda")
endif()

# You can generate ./examples_modules/ by running
# ./tools/generate_examples_modules.sh
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/examples_modules/CMakeLists.txt")
  add_subdirectory(examples_modules)
endif()
