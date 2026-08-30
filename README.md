# AndromedaUI

AndromedaUI is an AI slop-free fork of [FTXUI](https://github.com/ArthurSonzogni/FTXUI). Upstream commits after [3367c3a](https://codeberg.org/LunarWatcher/AndromedaUI/commit/3367c3a005ac3d8659effb0858526931f68fc434) have been removed.

Please note that this fork and upstream use two different versioning systems. v1.0.0 in this fork is the first release after the fork, and has no relation to upstream v1.0.0.

## Example
```cpp
    vbox({
      hbox({
        text("one") | border,
        text("two") | border | flex,
        text("three") | border | flex,
      }),

      gauge(0.25) | color(Color::Red),
      gauge(0.50) | color(Color::White),
      gauge(0.75) | color(Color::Blue),
    });
```

## Requirements

AndromedaUI requires a C++20 compiler.

## Build using CMake

It is **highly** recommended to use CMake FetchContent to depend on FTXUI so you may specify which commit you would like to depend on.
```cmake
include(FetchContent)
FetchContent_Declare(andromedaui
  GIT_REPOSITORY https://codeberg.org/LunarWatcher/AndromedaUI
  GIT_TAG v1.0.0 # Make sure this is set to the latest version
)
FetchContent_MakeAvailable(andromedaui)

target_link_libraries(your_target PRIVATE
    # Chose a submodule
    andromedaui::component
    andromedaui::dom
    andromedaui::screen
)
```

## License

MIT. See the LICENSE file.
