#pragma once

#include "../Logic/Scene.h"

#include "../Platform/Listening.h"
typedef union SDL_Event; //forwarded

class Viewport;
class Projection;
class Camera;

class SampleScene : public Scene, Listener<SDL_Event>
{
public:
	SampleScene(App* app);
	virtual ~SampleScene();

	virtual bool init();

	virtual bool handleEvent(SDL_Event const & e);
	virtual void update(float delta);
	virtual void render();

protected:
	Viewport* _vp;
	Projection* _proj;
	Camera* _cam;
};