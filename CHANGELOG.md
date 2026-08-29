# Changelog

## v1.0.0 (TBA)

First release.

* Renamed to AndromedaUI
* Removed all commits after https://codeberg.org/LunarWatcher/AndromedaUI/commit/3367c3a005ac3d8659effb0858526931f68fc434 (upstream link: https://github.com/ArthurSonzogni/FTXUI/commit/3367c3a005ac3d8659effb0858526931f68fc434) due to AI slop
* Moved tests out of line
* Removed all non-cmake builds
  * I can't maintain non-CMake builds at this time, because I don't use anything other than CMake, so removing them avoids having to do renames in them that I cannot verify anyway
* Moved tests to catch2
* Dropped separate `include` folder

