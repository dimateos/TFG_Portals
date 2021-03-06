#include "Platform_SDL.h"
#include <SDL.h>
#include <iostream>

double Platform_SDL::SDL_PERFORMANCE_FREQUENCY_ = 0.0f;
long long unsigned int Platform_SDL::lastFrame_ = 0;
long long unsigned int Platform_SDL::thisFrame_ = 0;
double Platform_SDL::deltaTime_ = 0.0f;
double Platform_SDL::detaTimeSinceStart_ = 0.0f;

Emitter<SDL_Event> Platform_SDL::keyEventEmitter_, Platform_SDL::mouseMotionEventEmitter_, Platform_SDL::mouseButtonEventEmitter_,
	Platform_SDL::windowEventEmitter_, Platform_SDL::platformEventEmitter_;

bool Platform_SDL::init() {
	printf("plat - init\n");
	int flags = SDL_INIT_VIDEO; //SDL_INIT_EVERYTHING

	//init sdl
	if (SDL_Init(flags) < 0) {
		printf("plat - SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	SDL_PERFORMANCE_FREQUENCY_ = SDL_GetPerformanceFrequency();
	return true;
}

void Platform_SDL::release() {
	printf("plat - release\n");
	SDL_Quit();
}

void Platform_SDL::pollEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {

		//distrubuted listening
		if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) keyEventEmitter_.Emit(event);
		else if (event.type == SDL_MOUSEMOTION) mouseMotionEventEmitter_.Emit(event);
		else if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP || event.type == SDL_MOUSEWHEEL)
			mouseButtonEventEmitter_.Emit(event);
		else if (event.type == SDL_WINDOWEVENT || event.type == SDL_DISPLAYEVENT) windowEventEmitter_.Emit(event);

		//others
		else if (event.type == SDL_QUIT || event.type == SDL_SYSWMEVENT) platformEventEmitter_.Emit(event);
		//else printf("plat - ignored event type: %i\n", event.type);
	}
}

void Platform_SDL::startTimings() {
	thisFrame_ = SDL_GetPerformanceCounter();
}

void Platform_SDL::updateTimings() {
	lastFrame_ = thisFrame_;
	thisFrame_ = SDL_GetPerformanceCounter();

	deltaTime_ = (thisFrame_ - lastFrame_) / SDL_PERFORMANCE_FREQUENCY_;
	detaTimeSinceStart_ += deltaTime_;
}
