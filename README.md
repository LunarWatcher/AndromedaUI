# AndromedaUI

AndromedaUI is an AI slop-free fork of [FTXUI](https://github.com/ArthurSonzogni/FTXUI). Upstream commits after [3367c3a](https://codeberg.org/LunarWatcher/AndromedaUI/commit/3367c3a005ac3d8659effb0858526931f68fc434) have been removed.

Please note that this fork and upstream use two different versioning systems. v1.0.0 in this fork is the first release after the fork, and has no relation to upstream v1.0.0.

## Example

```cpp
andromeda::vbox({
    andromeda::hbox({
        andromeda::text("one") | andromeda::border,
        andromeda::text("two") | andromeda::border | andromeda::flex,
        andromeda::text("three") | andromeda::border | andromeda::flex,
    }),

    andromeda::gauge(0.25) | andromeda::color(Color::Red),
    andromeda::gauge(0.50) | andromeda::color(Color::White),
    andromeda::gauge(0.75) | andromeda::color(Color::Blue),
});
```

## Requirements

AndromedaUI requires a C++20 compiler. It should in theory run on all operating systems, but only Linux is verified.

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
    # Choose a submodule (or use all)
    andromedaui::component
    andromedaui::dom
    andromedaui::screen
)
```

## Documentation

The documentation was removed during the split from FTXUI due to a heavy reliance on images not stored in the source tree, as well as heavy use of doxygen-specific functionality that makes the source files very hard to read outside the doxygen-rendered pages. 

The docs will be replaced at some point:tm:. In the meanwhile, there's a long list of examples (see the `examples` folder) that cover basically all the functionality in the library. `dom/component/homescreen.cpp` is a particularly broad example that covers proper TUI use.

## License

MIT. See the LICENSE file.
