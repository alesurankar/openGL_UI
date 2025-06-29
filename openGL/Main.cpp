#include <stdexcept>
#include <SDL3/SDL.h>

int main() 
{
    try 
    {
        SDL_Init(SDL_INIT_VIDEO);

        SDL_Window* window = SDL_CreateWindow("SDL3 Window", 800, 800, SDL_WINDOW_OPENGL);
        if (!window) 
        {
            throw std::runtime_error(SDL_GetError());
        }

        bool running = true;
        while (running) 
        {
            SDL_Event event;
            while (SDL_PollEvent(&event)) 
            {
                if (event.type == SDL_EVENT_QUIT) 
                {
                    running = false;
                }
            }
        }

        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
    }
    catch (const std::exception& e) 
{
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Error", e.what(), nullptr);
        return -1;
    }

}
