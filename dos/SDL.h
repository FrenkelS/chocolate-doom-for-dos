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

#ifndef __SDL__
#define __SDL__

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#define Uint8  uint8_t
#define Sint16  int16_t
#define Uint16 uint16_t
#define Sint32  int32_t
#define Uint32 uint32_t

#define SDL_bool int
#define SDL_Window int
#define SDL_Scancode int
#define SDL_Keycode Sint32

#define SDL_FALSE	0
#define SDL_TRUE	1

#define SDL_Joystick int
#define SDL_JoystickID int

typedef struct SDL_MouseWheelEvent
{
	Sint32 y;
} SDL_MouseWheelEvent;

typedef struct SDL_JoyButtonEvent
{
	SDL_JoystickID which;
	Uint8 button;
} SDL_JoyButtonEvent;

typedef struct SDL_ControllerAxisEvent
{
	Uint8 axis;
	Sint16 value;
} SDL_ControllerAxisEvent;

typedef struct SDL_ControllerButtonEvent
{
	Uint8 button;
} SDL_ControllerButtonEvent;

typedef struct SDL_Keysym
{
	SDL_Scancode scancode;
	SDL_Keycode sym;
	Uint16 mod;
} SDL_Keysym;

typedef struct SDL_KeyboardEvent
{
	SDL_Keysym keysym;
} SDL_KeyboardEvent;

typedef struct SDL_MouseButtonEvent
{
	Uint8 button;
} SDL_MouseButtonEvent;

typedef struct SDL_TextInputEvent
{
	char text[32];
} SDL_TextInputEvent;

typedef struct SDL_WindowEvent
{
	Uint32 windowID;
	Uint8 event;
} SDL_WindowEvent;

typedef struct SDL_Event
{
	Uint32 type;
	SDL_WindowEvent window;
	SDL_KeyboardEvent key;
	SDL_TextInputEvent text;
	SDL_MouseButtonEvent button;
	SDL_MouseWheelEvent wheel;
	SDL_JoyButtonEvent jbutton; 
	SDL_ControllerAxisEvent caxis;
	SDL_ControllerButtonEvent cbutton;
} SDL_Event;

#define SDL_Palette int

typedef struct SDL_PixelFormat
{
	SDL_Palette *palette;
} SDL_PixelFormat;

typedef struct SDL_Surface
{
	SDL_PixelFormat *format;
	uint8_t *pixels;
	int pitch;
} SDL_Surface;

typedef struct SDL_Rect
{
	int x;
	int y;
	int w;
	int h;
} SDL_Rect;

typedef struct SDL_Color
{
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
} SDL_Color;

#define SDLK_BACKSPACE 6
#define SDLK_RETURN 7
#define SDLK_ESCAPE 8

#define AUDIO_S16SYS 0
#define SDL_AUDIO_ALLOW_FREQUENCY_CHANGE 0

#define SDL_MESSAGEBOX_ERROR 0
#define SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING 0

#define SDL_PEEKEVENT 0
#define SDL_FIRSTEVENT 0
#define SDL_LASTEVENT 0
#define SDL_TEXTINPUT 0

#define SDL_QUIT			0x100
#define SDL_WINDOWEVENT		0x200
#define SDL_KEYDOWN			0x300
#define SDL_KEYUP			0x301
#define SDL_MOUSEBUTTONDOWN	0x401
#define SDL_MOUSEBUTTONUP	0x402
#define SDL_MOUSEWHEEL		0x403
#define SDL_JOYBUTTONDOWN	0x603

#define SDL_ENABLE 1
#define SDL_DISABLE 0

#define SDL_HAT_CENTERED	0x00
#define SDL_HAT_UP			0x01
#define SDL_HAT_RIGHT		0x02
#define SDL_HAT_DOWN		0x04
#define SDL_HAT_LEFT		0x08

#define SDL_INIT_TIMER			0x00000001u
#define SDL_INIT_AUDIO			0x00000010u
#define SDL_INIT_VIDEO			0x00000020u
#define SDL_INIT_JOYSTICK		0x00000200u
#define SDL_INIT_GAMECONTROLLER	0x00002000u

#define MIX_INIT_MID 0
#define MIX_INIT_FLAC 0
#define MIX_INIT_OGG 0
#define MIX_INIT_MP3 0
#define MIX_CHANNEL_POST 0
#define MIX_MAX_VOLUME 0

void SDL_Delay(Uint32);
char* SDL_GetError(void);
Uint32 SDL_GetRelativeMouseState(int*, int*);
Uint32 SDL_GetTicks(void);
int SDL_Init(Uint32);
int SDL_InitSubSystem(Uint32);
void SDL_QuitSubSystem(Uint32);
int SDL_PeepEvents(void*, int, int, int, int);
SDL_bool SDL_SetHint(const char*, const char*);
void SDL_ShowSimpleMessageBox(int, char*, char*, char*);
void SDL_StartTextInput(void);
void SDL_StopTextInput(void);
void SDL_Quit(void);

#define Mix_Music int

void Mix_HaltMusic(void);
void Mix_CloseAudio(void);
char *Mix_GetError(void);
int Mix_QuerySpec(void*, void*, void*);
int Mix_OpenAudioDevice(int, Uint16, int, int, const char*, int);
void Mix_Init(int);
void Mix_SetMusicCMD(char*);
void Mix_VolumeMusic(int);
int Mix_PlayMusic(void*, int);
void Mix_FreeMusic(void*);
int *Mix_LoadMUS(const char*);
int Mix_PlayingMusic(void);
void Mix_RegisterEffect(int, void*, void*, void*);

void SDL_PauseAudio(int);

void SDL_LockAudio(void);
void SDL_UnlockAudio(void);
void Mix_PauseMusic(void);
void Mix_ResumeMusic(void);
void Mix_SetMusicPosition(int);

#define SDL_mutex int

int SDL_LockMutex(SDL_mutex*);
int SDL_UnlockMutex(SDL_mutex*);
SDL_mutex *SDL_CreateMutex(void);

#define AUDIO_U8 0

typedef struct Mix_Chunk
{
	int alen;
	char *abuf;
	int allocated;
	int volume;
} Mix_Chunk;

typedef struct SDL_AudioCVT
{
	int len;
	char *buf;
	int len_mult;
} SDL_AudioCVT;

void Mix_HaltChannel(int);
int SDL_BuildAudioCVT(void*, int, int, int, int, int, int);
void SDL_ConvertAudio(void*);
void Mix_SetPanning(int, int, int);
void Mix_PlayChannel(int, void*, int);
int Mix_Playing(int);
void Mix_AllocateChannels(int);

SDL_Window *SDL_CreateWindow(const char*, int, int, int, int, Uint32);
SDL_Surface *SDL_CreateRGBSurface(Uint32, int, int, int, Uint32, Uint32, Uint32, Uint32);
SDL_Surface *SDL_CreateRGBSurfaceFrom(void*, int, int, int, int, Uint32, Uint32, Uint32, Uint32);
void SDL_SetWindowIcon(SDL_Window*, SDL_Surface*);
void SDL_FreeSurface(SDL_Surface*);
int SDL_FillRect(SDL_Surface*, const SDL_Rect*, Uint32);
int SDL_LockSurface(SDL_Surface*);
void SDL_UnlockSurface(SDL_Surface*);
void SDL_BlitSurface(SDL_Surface*, const SDL_Rect*, SDL_Surface*, SDL_Rect*);
SDL_Surface *SDL_GetWindowSurface(SDL_Window*);
void SDL_UpdateWindowSurfaceRects(SDL_Window*, const SDL_Rect*, int);
void SDL_UpdateWindowSurface(SDL_Window*);
int SDL_PollEvent(SDL_Event*);
int SDL_SetPaletteColors(SDL_Palette*, const SDL_Color*, int, int);

#endif
