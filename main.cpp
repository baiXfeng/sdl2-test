
#include "myapp.h"

#if defined(__PSP__)
#include <SDL_main.h>
int SDL_main(int argc, char * argv[]) {
#else
int main(int argc, char * argv[]) {
#endif
    MyApp app;
    return app.run();
}