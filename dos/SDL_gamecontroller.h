//
// Copyright(C) 2025 Frenkel Smeijers
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//

#ifndef __SDL_GAMECONTROLLER__
#define __SDL_GAMECONTROLLER__

#define SDL_GameController int
#define SDL_GameControllerAxis int

#define SDL_Joystick int
#define SDL_JoystickGUID int
#define SDL_JoystickID int

#define SDL_CONTROLLER_AXIS_INVALID			-1
#define SDL_CONTROLLER_AXIS_LEFTX			0
#define SDL_CONTROLLER_AXIS_LEFTY			1
#define SDL_CONTROLLER_AXIS_RIGHTX			2
#define SDL_CONTROLLER_AXIS_RIGHTY			3
#define SDL_CONTROLLER_AXIS_TRIGGERLEFT		4
#define SDL_CONTROLLER_AXIS_TRIGGERRIGHT	5
#define SDL_CONTROLLER_AXIS_MAX				6

#define SDL_CONTROLLER_BUTTON_A 0
#define SDL_CONTROLLER_BUTTON_B 0
#define SDL_CONTROLLER_BUTTON_DPAD_UP 0
#define SDL_CONTROLLER_BUTTON_DPAD_DOWN 0
#define SDL_CONTROLLER_BUTTON_DPAD_LEFT 0
#define SDL_CONTROLLER_BUTTON_DPAD_RIGHT 0
#define SDL_CONTROLLER_BUTTON_LEFTSHOULDER 0
#define SDL_CONTROLLER_BUTTON_RIGHTSHOULDER 0
#define SDL_CONTROLLER_BUTTON_START 0
#define SDL_CONTROLLER_BUTTON_X 0
#define SDL_CONTROLLER_BUTTON_Y 0
#define SDL_CONTROLLER_BUTTON_LEFTSTICK 0
#define SDL_CONTROLLER_BUTTON_BACK 0
#define SDL_CONTROLLER_BUTTON_GUIDE 0
#define SDL_CONTROLLER_BUTTON_RIGHTSTICK 0
#define SDL_CONTROLLER_BUTTON_MISC1 0
#define SDL_CONTROLLER_BUTTON_PADDLE1 0
#define SDL_CONTROLLER_BUTTON_PADDLE2 0
#define SDL_CONTROLLER_BUTTON_PADDLE3 0
#define SDL_CONTROLLER_BUTTON_PADDLE4 0
#define SDL_CONTROLLER_BUTTON_TOUCHPAD 0
#define SDL_CONTROLLER_BUTTON_MAX 21

#define SDL_CONTROLLERBUTTONDOWN 0
#define SDL_CONTROLLERAXISMOTION 0

#define SDL_CONTROLLER_TYPE_UNKNOWN				0
#define SDL_CONTROLLER_TYPE_XBOX360				1
#define SDL_CONTROLLER_TYPE_XBOXONE				2
#define SDL_CONTROLLER_TYPE_PS3					3
#define SDL_CONTROLLER_TYPE_PS4					4
#define SDL_CONTROLLER_TYPE_NINTENDO_SWITCH_PRO	5
#define SDL_CONTROLLER_TYPE_PS5					6

void SDL_free(void*);

SDL_GameController *SDL_GameControllerOpen(int);
void SDL_GameControllerClose(SDL_GameController*);
char *SDL_GameControllerName(SDL_GameController*);
int SDL_GameControllerTypeForIndex(int);
void SDL_GameControllerEventState(int);
int SDL_GameControllerGetButton(SDL_GameController*, int);
int SDL_GameControllerGetAxis(SDL_GameController*, int);
char *SDL_GameControllerMappingForGUID(int);

char *SDL_JoystickName(SDL_Joystick*);
int SDL_JoystickNumAxes(SDL_Joystick*);
int SDL_JoystickNumButtons(SDL_Joystick*);
int SDL_JoystickNumHats(SDL_Joystick*);
SDL_JoystickGUID SDL_JoystickGetGUIDFromString(char*);
int SDL_NumJoysticks(void);
void SDL_JoystickGetGUIDString(int, char*, int);
SDL_JoystickGUID SDL_JoystickGetDeviceGUID(int);
char *SDL_JoystickNameForIndex(int);
SDL_Joystick *SDL_JoystickOpen(int);
void SDL_JoystickClose(SDL_Joystick*);
void SDL_JoystickEventState(int);
int SDL_JoystickInstanceID(int*);
int SDL_JoystickGetGUID(int*);
int SDL_IsGameController(int);
int SDL_JoystickGetButton(SDL_Joystick*, int);
int SDL_JoystickGetHat(SDL_Joystick*, int);
int SDL_JoystickGetAxis(SDL_Joystick*, int);

#endif
