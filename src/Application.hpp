/******************************************************************************************************
 * @file  Application.hpp
 * @brief Declaration of the Application class
 ******************************************************************************************************/

#pragma once

extern "C" {
#include <SDL2/SDL.h>
}

#include <string>
#include <unordered_map>

#include "Hull.hpp"
#include "Set.hpp"

#define WINDOW_FLAGS (SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)

/**
 * @class Application
 * @brief The main core of the software
 */
class Application {
public:
    Application();
    ~Application();

    void run();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    int width, height;

    bool stop;
    bool fullscreen;

    SDL_Event event;
    std::unordered_map<SDL_Scancode, bool> keysFlags;

    Set set;
    Hull hull;

    void drawLine(const Complex& A, const Complex& B);
    void drawCircle(SDL_Point center, int radius, SDL_Color color) const;
    
    void handleEvents();
    void handleInputs();
};