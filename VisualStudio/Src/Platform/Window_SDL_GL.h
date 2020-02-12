#pragma once

class SDL_Window; //forwarded
typedef void *SDL_GLContext;

class Window_SDL_GL
{
public:
	static bool init(int SDL_window_flags, const char* title, int w, int h, int x, int y, int GL_minor, int GL_major);
	static void release();

	//swap window buffers and present
	static void swap();

	//Window data
	inline static SDL_Window* getWindow() { return _window; };
	inline static int getWidth() { return _width; };
	inline static int getHeight() { return _height; };
	//Context data
	inline static SDL_GLContext getContext() { return _context; };

private:
	Window_SDL_GL() {};

	//Window data
	static SDL_Window* _window;
	static int _width, _height;

	//Context data
	static SDL_GLContext _context;
};