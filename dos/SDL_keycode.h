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

#ifndef __SDL_KEYCODE__
#define __SDL_KEYCODE__

#define SDL_SCANCODE_LCTRL 0
#define SDL_SCANCODE_RCTRL 1
#define SDL_SCANCODE_LSHIFT 2
#define SDL_SCANCODE_RSHIFT 3
#define SDL_SCANCODE_LALT 4
#define SDL_SCANCODE_RALT 5

#define SDLK_BACKSPACE 6
#define SDLK_RETURN 7

#define SDL_BUTTON_LEFT 0
#define SDL_BUTTON_RIGHT 1
#define SDL_BUTTON_MIDDLE 2

#define KMOD_SHIFT 255

int SDL_GetModState(void);

#endif
