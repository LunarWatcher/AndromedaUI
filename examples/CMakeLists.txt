if(NOT ANDROMEDAUI_BUILD_EXAMPLES)
  return()
endif()

set(EXAMPLES_DIR ${CMAKE_CURRENT_SOURCE_DIR})
function(example name)
  add_executable(andromeda_example_${name} ${name}.cpp)
  target_link_libraries(andromeda_example_${name} PUBLIC ${DIRECTORY_LIB})
  file(RELATIVE_PATH dir ${EXAMPLES_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
  set_property(GLOBAL APPEND PROPERTY FTXUI::EXAMPLES ${dir}/${name})
  target_compile_features(andromeda_example_${name} PRIVATE cxx_std_20)
endfunction(example)

add_subdirectory(component)
add_subdirectory(dom)

