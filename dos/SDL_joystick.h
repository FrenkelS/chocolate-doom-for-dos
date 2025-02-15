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

#ifndef __SDL_JOYSTICK__
#define __SDL_JOYSTICK__

#define SDL_Joystick int
#define SDL_JoystickGUID int

int SDL_NumJoysticks(void);
int SDL_IsGameController(int);
SDL_JoystickGUID SDL_JoystickGetDeviceGUID(int);
SDL_JoystickGUID SDL_JoystickGetGUIDFromString(char*);
void SDL_JoystickGetGUIDString(int, char*, int);
void SDL_JoystickEventState(int);
void SDL_JoystickClose(SDL_Joystick*);
int SDL_JoystickNumHats(SDL_Joystick*);
int SDL_JoystickNumAxes(SDL_Joystick*);
SDL_Joystick *SDL_JoystickOpen(int);
char *SDL_JoystickName(SDL_Joystick*);
int SDL_JoystickGetButton(SDL_Joystick*, int);
int SDL_JoystickGetHat(SDL_Joystick*, int);
int SDL_JoystickGetAxis(SDL_Joystick*, int);

#endif
