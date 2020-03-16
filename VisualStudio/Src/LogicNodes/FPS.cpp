#include "FPS.h"

#include <glad\glad.h>

#include "../Platform/Platform_SDL.h"
#include <SDL_events.h>

#include "../Platform/Window_SDL_GL.h"
#include <gtc/type_ptr.hpp>

FPS::FPS(Camera * cam) : Node(), _cam(cam) {
	Platform_SDL::_keyEventEmitter.registerListener(this);
}

FPS::~FPS() {}

void FPS::update() {
}

bool FPS::handleEvent(SDL_Event const & e) {
	bool handled = false;

	if (e.type == SDL_KEYDOWN) {
		handled = true;

		switch (e.key.keysym.sym) {
		//case SDLK_w: _cam->trans.localPostion.y +=
		default: handled = false;
		}
	}

	//else printf("cube - ignored event type: %i\n", e.type);
	return handled;
}