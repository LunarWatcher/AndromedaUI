add_library(andromeda::screen ALIAS screen)
add_library(andromeda::dom ALIAS dom)
add_library(andromeda::component ALIAS component)
export(
  TARGETS screen dom component
  NAMESPACE andromeda::
  FILE "${PROJECT_BINARY_DIR}/andromeda-targets.cmake"
)
