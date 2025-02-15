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

#define SDL_CONTROLLER_BUTTON_MAX 0
#define SDL_CONTROLLER_AXIS_TRIGGERLEFT 0
#define SDL_CONTROLLER_AXIS_TRIGGERRIGHT 0
#define SDL_CONTROLLER_AXIS_MAX 0
#define SDL_CONTROLLER_BUTTON_DPAD_UP 0
#define SDL_CONTROLLER_BUTTON_DPAD_DOWN 0
#define SDL_CONTROLLER_BUTTON_DPAD_LEFT 0
#define SDL_CONTROLLER_BUTTON_DPAD_RIGHT 0
#define SDL_CONTROLLER_AXIS_LEFTX 0
#define SDL_CONTROLLER_AXIS_LEFTY 0
#define SDL_CONTROLLER_AXIS_RIGHTX 0
#define SDL_CONTROLLER_AXIS_RIGHTY 0

SDL_GameController *SDL_GameControllerOpen(int);
void SDL_GameControllerClose(SDL_GameController*);
char *SDL_GameControllerName(SDL_GameController*);
int SDL_GameControllerTypeForIndex(int);
void SDL_GameControllerEventState(int);
int SDL_GameControllerGetButton(SDL_GameController*, int);
int SDL_GameControllerGetAxis(SDL_GameController*, int);

#endif
