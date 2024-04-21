/******************************************************************************************************
 * @file  Application.cpp
 * @brief Implementation of the Application class
 ******************************************************************************************************/

#include "Application.hpp"

#include <stdexcept>

Application::Application()
    : width(1280), height(800),
      stop(), fullscreen(),
      set(50, 50, 1230, 50, 750),
      event(), keysFlags() {

    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error(std::string("SDL_Init failed : ").append(SDL_GetError()));
    }

    window = SDL_CreateWindow("Pancake Media Player", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, WINDOW_FLAGS);
    if(!window) {
        throw std::runtime_error(std::string("Window was not created : ") + SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer) {
        throw std::runtime_error(std::string("Renderer was not created : ") + SDL_GetError());
    }

    hull.getHull(set.points);
}

Application::~Application() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Application::run() {
    SDL_Color red(255, 0, 0, 255);

    while(!stop) {
        handleEvents();

        SDL_RenderPresent(renderer);
        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
        SDL_RenderClear(renderer);

        for(auto & point : hull.points) {
            drawCircle(SDL_Point(point.x, point.y), 5, red);
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for(unsigned int i = 0 ; i < hull.hull.size() ; ++i) {
            drawLine(hull.hull[i], hull.hull[(i + 1) % hull.hull.size()]);
        }
    }
}

void Application::drawLine(const Complex& A, const Complex& B) {
    SDL_RenderDrawLineF(renderer, A.x, A.y, B.x, B.y);
}

void Application::handleEvents() {
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_KEYDOWN:
                handleInputs();

                break;
            case SDL_KEYUP:
                if(keysFlags.contains(event.key.keysym.scancode)) {
                    keysFlags[event.key.keysym.scancode] = false;
                }

                break;
            case SDL_QUIT:
                stop = true;

                break;
            case SDL_WINDOWEVENT:
                if(event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    SDL_GetWindowSize(window, &width, &height);
                }

                break;
            default:
                break;
        }
    }
}

void Application::handleInputs() {
    switch(event.key.keysym.scancode) {
        case SDL_SCANCODE_ESCAPE:
            stop = true;

            break;
        case SDL_SCANCODE_F11:
            if(!keysFlags[SDL_SCANCODE_F11]) {
                SDL_SetWindowFullscreen(window, fullscreen ? 0 : SDL_WINDOW_FULLSCREEN);
                fullscreen = !fullscreen;
                keysFlags[SDL_SCANCODE_F11] = true;
            }

            break;
        case SDL_SCANCODE_R:
            set.regenerate(set.points.size(), 50, width - 50, 50, height - 50);
            hull.getHull(set.points);

            break;
        default:
            break;
    }
}

void Application::drawCircle(SDL_Point center, int radius, SDL_Color color) const {
    int x = 0, y = radius;
    SDL_Point points[8];

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    while(x <= y) {
        points[0] = {x, y};
        points[1] = {-x, y};
        points[2] = {x, -y};
        points[3] = {-x, -y};
        points[4] = {y, x};
        points[5] = {-y, x};
        points[6] = {y, -x};
        points[7] = {-y, -x};

        for(SDL_Point& point: points) {
            point.x += center.x;
            point.y += center.y;
        }

        SDL_RenderDrawPoints(renderer, points, 8);

        ++x;
        y = (int) sqrt(radius * radius - x * x);
    }
}