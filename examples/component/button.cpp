#include "andromeda/component/component.hpp"
#include "andromeda/component/screen_interactive.hpp"

int main(){
    auto screen = andromeda::ScreenInteractive::Fullscreen();
    auto testComponent = andromeda::Renderer([](){return andromeda::text("test Component");});
    screen.Loop(testComponent);
    return 0;
}
