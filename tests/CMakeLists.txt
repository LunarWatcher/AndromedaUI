add_executable(tests 
    src/screen/color_test.cpp
    src/screen/string_test.cpp

    src/util/ref_test.cpp

    src/component/radiobox_test.cpp
    src/component/animation_test.cpp
    src/component/dropdown_test.cpp
    src/component/collapsible_test.cpp
    src/component/receiver_test.cpp
    src/component/toggle_test.cpp
    src/component/menu_test.cpp
    src/component/slider_test.cpp
    src/component/container_test.cpp
    src/component/button_test.cpp
    src/component/terminal_input_parser_test.cpp
    src/component/hoverable_test.cpp
    src/component/screen_interactive_test.cpp
    src/component/resizable_split_test.cpp
    src/component/input_test.cpp
    src/component/component_test.cpp
    src/component/modal_test.cpp

    src/dom/color_test.cpp
    src/dom/italic_test.cpp
    src/dom/flexbox_helper_test.cpp
    src/dom/spinner_test.cpp
    src/dom/linear_gradient_test.cpp
    src/dom/underlined_test.cpp
    src/dom/flexbox_test.cpp
    src/dom/separator_test.cpp
    src/dom/dim_test.cpp
    src/dom/table_test.cpp
    src/dom/scroll_indicator_test.cpp
    src/dom/dbox_test.cpp
    src/dom/gauge_test.cpp
    src/dom/hbox_test.cpp
    src/dom/hyperlink_test.cpp
    src/dom/border_test.cpp
    src/dom/blink_test.cpp
    src/dom/selection_test.cpp
    src/dom/vbox_test.cpp
    src/dom/gridbox_test.cpp
    src/dom/bold_test.cpp
    src/dom/canvas_test.cpp
    src/dom/text_test.cpp
)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.15.3
)

FetchContent_MakeAvailable(Catch2)

target_link_libraries(tests Catch2::Catch2WithMain)
target_link_libraries(tests
    andromeda::screen
    andromeda::dom
    andromeda::component
)

target_include_directories(tests PUBLIC src/)

# vim:ft=cmake
