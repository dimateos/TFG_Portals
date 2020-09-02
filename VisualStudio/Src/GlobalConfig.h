#pragma once

//static global config to easily edit hotkeys
class GlobalConfig
{
public:
	static char
		ACTION_escape,				//exit application
		ACTION_captureCursor,		//switch free amd hidden cursor
		ACTION_screenPostFilter,	//Switch post-processing effect (hold and press 1-9)

		ACTION_moveRIGHT,			//movement
		ACTION_moveLEFT,
		ACTION_moveBACK,
		ACTION_moveFORE,
		ACTION_moveUP,
		ACTION_moveDOWN,
		ACTION_rotENABLE,			//rotation
		ACTION_rotRIGHT,
		ACTION_rotLEFT,
		ACTION_SPRINTtransform,		//modifiers
		ACTION_RESETtransform,

		ACTION_switchControl,			//start/stop controling the portal to move/rotate it locally
		ACTION_cycleCamerasPositions,	//switch between camera positions

		ACTION_togglePortalCameraAxis,	//show/hide virtual portal cameras axes
		ACTION_switchPortalRenderModes	//switch portal rendering options
		;

private:
	GlobalConfig() {}; //non instanciable
};