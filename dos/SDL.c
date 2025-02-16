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

#include <string.h>

#include "chocdos.h"

#include "SDL.h"
#include "SDL_endian.h"
#include "SDL_filesystem.h"
#include "SDL_gamecontroller.h"
#include "SDL_joystick.h"
#include "SDL_keycode.h"
#include "SDL_mixer.h"
#include "SDL_net.h"
#include "SDL_opengl.h"
#include "SDL_stdinc.h"

#include "a_taskmn.h"


#define SCREENWIDTH		320
#define SCREENHEIGHT	200

#define PEL_WRITE_ADR	0x3c8
#define PEL_DATA		0x3c9


static uint8_t *videomemory;


char *SDL_GetPrefPath(const char *org, const char *app)
{
	UNUSED(org);
	UNUSED(app);
	return NULL;
}


SDL_bool SDL_SetHint(const char *name, const char *value)
{
	UNUSED(name);
	UNUSED(value);
	return 0;
}


#define TIMER_TICRATE 1000
static task *timerTask;
static volatile Uint32 ticcount;
static SDL_bool isTimerSet;

static void I_TimerISR(void)
{
	ticcount++;
}


#define KEYBOARDINT 9
#define KBDQUESIZE 32
static Uint8 keyboardqueue[KBDQUESIZE];
static int kbdtail, kbdhead;
static SDL_bool isKeyboardIsrSet = SDL_FALSE;

static _go32_dpmi_seginfo oldkeyboardisr, newkeyboardisr;

static void I_KeyboardISR(void)	
{
	Uint8 temp;

	// Get the scan code
	keyboardqueue[kbdhead & (KBDQUESIZE - 1)] = inp(0x60);
	kbdhead++;

	// Tell the XT keyboard controller to clear the key
	outp(0x61, (temp = inp(0x61)) | 0x80);
	outp(0x61, temp);

	// acknowledge the interrupt
	outp(0x20, 0x20);
}


int SDL_Init(Uint32 flags)
{
	return SDL_InitSubSystem(flags);
}


int SDL_InitSubSystem(Uint32 flags)
{
	switch (flags)
	{
		case SDL_INIT_TIMER:
			// Init timer
			timerTask = TS_ScheduleTask(I_TimerISR, TIMER_TICRATE, 0); // max priority
			isTimerSet = SDL_TRUE;

			// Init keyboard
			replaceInterrupt(oldkeyboardisr, newkeyboardisr, KEYBOARDINT, I_KeyboardISR);
			isKeyboardIsrSet = SDL_TRUE;
			break;
		case SDL_INIT_AUDIO:
			break;
		case SDL_INIT_VIDEO:
			__djgpp_nearptr_enable();
			I_SetScreenMode(0x13);
			videomemory = (uint8_t*)(0xa0000 + __djgpp_conventional_base);
			break;
		default:
			I_Error("Implement me: SDL_InitSubSystem(%i)", flags);
			break;
	}

	return 0;
}


int Mix_OpenAudioDevice(int frequency, Uint16 format, int channels, int chunksize, const char* device, int allowed_changes)
{
	UNUSED(frequency);
	UNUSED(format);
	UNUSED(channels);
	UNUSED(chunksize);
	UNUSED(device);
	UNUSED(allowed_changes);
	return -1;
}


char *Mix_GetError(void)
{
	return "Implement me: Mix_GetError()";
}


int SDL_GetNumVideoDisplays(void)
{
	return 1;
}


int SDL_GetDisplayBounds(int displayIndex, SDL_Rect *rect)
{
	rect->x = 0;
	rect->y = 0;
	rect->w = SCREENWIDTH;
	rect->h = SCREENHEIGHT;
	return 0;
}


SDL_Window *SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags)
{
	UNUSED(title);
	UNUSED(x);
	UNUSED(y);
	UNUSED(w);
	UNUSED(h);
	UNUSED(flags);

	return malloc(sizeof(SDL_Window));
}


void SDL_SetWindowMinimumSize(SDL_Window *window, int min_w, int min_h)
{
	UNUSED(window);
	UNUSED(min_w);
	UNUSED(min_h);
}

void SDL_SetWindowTitle(SDL_Window *window, const char *title)
{
	UNUSED(window);
	UNUSED(title);
}


//for windowIcon
SDL_Surface *SDL_CreateRGBSurfaceFrom(void *pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask)
{
	UNUSED(pixels);
	UNUSED(width);
	UNUSED(height);
	UNUSED(depth);
	UNUSED(pitch);
	UNUSED(Rmask);
	UNUSED(Gmask);
	UNUSED(Bmask);
	UNUSED(Amask);

	return malloc(sizeof(SDL_Surface));
}


void SDL_SetWindowIcon(SDL_Window *window, SDL_Surface *icon)
{
	UNUSED(window);
	UNUSED(icon);
}


void SDL_FreeSurface(SDL_Surface *surface)
{
	//TODO free(surface->format);
	//TODO free(surface->pixels);
	free(surface);
}


int SDL_GetCurrentDisplayMode(int displayIndex, SDL_DisplayMode *mode)
{
	UNUSED(displayIndex);

	mode->refresh_rate = 0;

	return 0;
}


SDL_Renderer *SDL_CreateRenderer(SDL_Window *window, int index, Uint32 flags)
{
	UNUSED(window);
	UNUSED(index);
	UNUSED(flags);

	return malloc(sizeof(SDL_Renderer));
}


int SDL_RenderSetLogicalSize(SDL_Renderer *renderer, int w, int h)
{
	UNUSED(renderer);
	UNUSED(w);
	UNUSED(h);
	return 0;
}


int SDL_RenderSetIntegerScale(SDL_Renderer *renderer, SDL_bool enable)
{
	UNUSED(renderer);
	UNUSED(enable);
	return 0;
}


int SDL_SetRenderDrawColor(SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	UNUSED(renderer);
	UNUSED(r);
	UNUSED(g);
	UNUSED(b);
	UNUSED(a);
	return 0;
}


int SDL_RenderClear(SDL_Renderer *renderer)
{
	UNUSED(renderer);
	return 0;
}


void SDL_RenderPresent(SDL_Renderer *renderer)
{
	UNUSED(renderer);
}


//for screenbuffer
SDL_Surface *SDL_CreateRGBSurface(Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask)
{
	SDL_Surface *surface;

	UNUSED(flags);
	UNUSED(width);
	UNUSED(height);
	UNUSED(depth);
	UNUSED(Rmask);
	UNUSED(Gmask);
	UNUSED(Bmask);
	UNUSED(Amask);

	surface = malloc(sizeof(SDL_Surface));
	surface->format = malloc(sizeof(SDL_PixelFormat));
	surface->pixels = malloc(width * height * depth / 8);
	return surface;
}


int SDL_FillRect(SDL_Surface *dst, const SDL_Rect *rect, Uint32 color)
{
	UNUSED(dst);
	UNUSED(rect);
	UNUSED(color);
	return 0;
}


//for argbbuffer
SDL_Surface *SDL_CreateRGBSurfaceWithFormatFrom(void *pixels, int width, int height, int depth, int pitch, Uint32 format)
{
	SDL_Surface *surface;

	UNUSED(pixels);
	UNUSED(width);
	UNUSED(height);
	UNUSED(depth);
	UNUSED(pitch);
	UNUSED(format);

	surface = malloc(sizeof(SDL_Surface));
	return surface;
}


SDL_Texture* SDL_CreateTexture(SDL_Renderer *renderer, Uint32 format, int access, int w, int h)
{
	UNUSED(renderer);
	UNUSED(format);
	UNUSED(access);
	UNUSED(w);
	UNUSED(h);

	return malloc(sizeof(SDL_Texture));
}


int SDL_GetRendererOutputSize(SDL_Renderer *renderer, int *w, int *h)
{
	UNUSED(renderer);

	*w = SCREENWIDTH;
	*h = SCREENHEIGHT;

	return 0;
}


int SDL_GetRendererInfo(SDL_Renderer *renderer, SDL_RendererInfo *info)
{
	UNUSED(renderer);

	info->max_texture_width  = SCREENWIDTH;
	info->max_texture_height = SCREENHEIGHT;

	return 0;
}


int SDL_SetPaletteColors(SDL_Palette *palette, const SDL_Color *colors, int firstcolor, int ncolors)
{
	int i;

	UNUSED(palette);

	outp(PEL_WRITE_ADR, 0);
	for (i = firstcolor; i < ncolors; i++)
	{
		outp(PEL_DATA, colors[i].r >> 2);
		outp(PEL_DATA, colors[i].g >> 2);
		outp(PEL_DATA, colors[i].b >> 2);
	}

	return 0;
}


int SDL_SetRelativeMouseMode(SDL_bool enabled)
{
	UNUSED(enabled);
	return 0;
}


Uint32 SDL_GetRelativeMouseState(int *x, int *y)
{
	UNUSED(x);
	UNUSED(y);
	return 0;
}


void SDL_Delay(Uint32 ms)
{
	Uint32 wait = ticcount + ms;
	while (ticcount < wait)
	{
		// do nothing
	}
}


#define SC_LSHIFT		0x2a
#define SC_RSHIFT		0x36

static Uint8 scancodes[128] =
{
//   0   1   2   3   4   5   6   7   8   9   a   b   c   d   e   f     
	 0, 41, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 45, 46, 42, 43, // 00
	20, 26,  8, 21, 23, 28, 24, 12, 18, 19, 47, 48, 40,  0,  4, 22, // 10
	 7,  9, 10, 11, 13, 14, 15, 51, 52, 53,  0, 49, 29, 27,  6, 25, // 20
	 5, 17, 16, 54, 55, 56,  0, 85,  0, 44, 57, 58, 58, 60, 61, 62, // 30
	63, 64, 65, 66, 67, 83, 71, 95, 96, 97, 86, 92, 93, 94, 87, 89, // 40
	90, 91, 98, 99,  0,  0,  0, 68, 69,  0,  0,  0,  0,  0,  0,  0, // 50
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // 60
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0  // 70
};

int SDL_PollEvent(SDL_Event *event)
{
	while (kbdtail < kbdhead)
	{
		int32_t k = keyboardqueue[kbdtail & (KBDQUESIZE - 1)];
		kbdtail++;

		// extended keyboard shift key bullshit
		if ((k & 0x7f) == SC_LSHIFT || (k & 0x7f) == SC_RSHIFT)
		{
			if (keyboardqueue[(kbdtail - 2) & (KBDQUESIZE - 1)] == 0xe0)
				continue;
			k &= 0x80;
			k |= SC_RSHIFT;
		}

		if (k == 0xe0)
			continue;               // special / pause keys
		if (keyboardqueue[(kbdtail - 2) & (KBDQUESIZE - 1)] == 0xe1)
			continue;                               // pause key bullshit

		if (k == 0xc5 && keyboardqueue[(kbdtail - 2) & (KBDQUESIZE - 1)] == 0x9d)
		{
			event->type = SDL_KEYDOWN;
			event->key.keysym.scancode = 72;
			return 1;
		}

		if (k & 0x80)
			event->type = SDL_KEYUP;
		else
			event->type = SDL_KEYDOWN;
		k &= 0x7f;
		event->key.keysym.scancode = scancodes[k];
		return 1;
	}

	return 0;
}


Uint32 SDL_GetTicks(void)
{
	return ticcount;
}


void SDL_PumpEvents(void)
{
}


int SDL_LockTexture(SDL_Texture *texture, const SDL_Rect *rect, void **pixels, int *pitch)
{
	UNUSED(texture);
	UNUSED(rect);
	UNUSED(pixels);
	UNUSED(pitch);
	return 0;
}


int SDL_LowerBlit(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect)
{
	UNUSED(srcrect);
	UNUSED(dst);
	UNUSED(dstrect);

	memcpy(videomemory, src->pixels, SCREENWIDTH * SCREENHEIGHT);

	return 0;
}


void SDL_UnlockTexture(SDL_Texture *texture)
{
	UNUSED(texture);
}


int SDL_SetRenderTarget(SDL_Renderer *renderer, SDL_Texture *texture)
{
	UNUSED(renderer);
	UNUSED(texture);
	return 0;
}


int SDL_RenderCopy(SDL_Renderer *renderer, SDL_Texture *texture, const SDL_Rect *srcrect, const SDL_Rect *dstrect)
{
	UNUSED(renderer);
	UNUSED(texture);
	UNUSED(srcrect);
	UNUSED(dstrect);
}


void SDL_QuitSubSystem(Uint32 flags)
{
	switch (flags)
	{
		case SDL_INIT_VIDEO:
			//TODO I_SetScreenMode(3);
			break;
		default:
			printf("Implement me: SDL_QuitSubSystem(%i)\n", flags);
			IMPLEMENT_ME();
			break;
	}
}


void SDL_Quit(void)
{
	if (isTimerSet) {
		TS_Terminate(timerTask);
		timerTask = NULL;
		TS_Shutdown();
	}

	if (isKeyboardIsrSet)
	{
		restoreInterrupt(KEYBOARDINT, oldkeyboardisr, newkeyboardisr);
	}
}


int SDL_GetModState(void)
{
	return 0;
}


SDL_mutex *SDL_CreateMutex(void)
{
	return malloc(sizeof(SDL_mutex));
}


int SDL_LockMutex(SDL_mutex *mutex)
{
	UNUSED(mutex);
	return 0;
}


int SDL_UnlockMutex(SDL_mutex *mutex)
{
	UNUSED(mutex);
	return 0;
}


char* SDL_GetError(void) {IMPLEMENT_ME();}
int SDL_PeepEvents(void*, int, int, int, int) {IMPLEMENT_ME();}
void SDL_ShowSimpleMessageBox(int, char*, char*, char*) {IMPLEMENT_ME();}
void SDL_StartTextInput(void) {IMPLEMENT_ME();}
void SDL_StopTextInput(void) {IMPLEMENT_ME();}
void Mix_HaltMusic(void) {IMPLEMENT_ME();}
void Mix_CloseAudio(void) {IMPLEMENT_ME();}
int Mix_QuerySpec(void*, void*, void*) {IMPLEMENT_ME();}
void Mix_Init(int) {IMPLEMENT_ME();}
void Mix_SetMusicCMD(char*) {IMPLEMENT_ME();}
void Mix_VolumeMusic(int) {IMPLEMENT_ME();}
int Mix_PlayMusic(void*, int) {IMPLEMENT_ME();}
void Mix_FreeMusic(void*) {IMPLEMENT_ME();}
int *Mix_LoadMUS(const char*) {IMPLEMENT_ME();}
int Mix_PlayingMusic(void) {IMPLEMENT_ME();}
void Mix_RegisterEffect(int, void*, void*, void*) {IMPLEMENT_ME();}
void SDL_PauseAudio(int) {IMPLEMENT_ME();}
void SDL_free(char*) {IMPLEMENT_ME();}
SDL_GameController *SDL_GameControllerOpen(int) {IMPLEMENT_ME();}
void SDL_GameControllerClose(SDL_GameController*) {IMPLEMENT_ME();}
char *SDL_GameControllerName(SDL_GameController*) {IMPLEMENT_ME();}
int SDL_GameControllerTypeForIndex(int) {IMPLEMENT_ME();}
void SDL_GameControllerEventState(int) {IMPLEMENT_ME();}
int SDL_GameControllerGetButton(SDL_GameController*, int) {IMPLEMENT_ME();}
int SDL_GameControllerGetAxis(SDL_GameController*, int) {IMPLEMENT_ME();}
int SDL_NumJoysticks(void) {IMPLEMENT_ME();}
int SDL_IsGameController(int) {IMPLEMENT_ME();}
SDL_JoystickGUID SDL_JoystickGetDeviceGUID(int) {IMPLEMENT_ME();}
SDL_JoystickGUID SDL_JoystickGetGUIDFromString(char*) {IMPLEMENT_ME();}
void SDL_JoystickGetGUIDString(int, char*, int) {IMPLEMENT_ME();}
void SDL_JoystickEventState(int) {IMPLEMENT_ME();}
void SDL_JoystickClose(SDL_Joystick*) {IMPLEMENT_ME();}
int SDL_JoystickNumHats(SDL_Joystick*) {IMPLEMENT_ME();}
int SDL_JoystickNumAxes(SDL_Joystick*) {IMPLEMENT_ME();}
SDL_Joystick *SDL_JoystickOpen(int) {IMPLEMENT_ME();}
char *SDL_JoystickName(SDL_Joystick*) {IMPLEMENT_ME();}
int SDL_JoystickGetButton(SDL_Joystick*, int) {IMPLEMENT_ME();}
int SDL_JoystickGetHat(SDL_Joystick*, int) {IMPLEMENT_ME();}
int SDL_JoystickGetAxis(SDL_Joystick*, int) {IMPLEMENT_ME();}
void SDLNet_Init(void) {IMPLEMENT_ME();}
UDPsocket SDLNet_UDP_Open(int) {IMPLEMENT_ME();}
UDPpacket *SDLNet_AllocPacket(int) {IMPLEMENT_ME();}
int SDLNet_ResolveHost(void*, void*, int) {IMPLEMENT_ME();}
int SDLNet_UDP_Send(void*, int, void*) {IMPLEMENT_ME();}
int SDLNet_UDP_Recv(void*, void*) {IMPLEMENT_ME();}
char *SDLNet_GetError(void) {IMPLEMENT_ME();}
int SDLNet_Read32(void*) {IMPLEMENT_ME();}
short SDLNet_Read16(void*) {IMPLEMENT_ME();}
void SDL_DestroyRenderer(SDL_Renderer*) {IMPLEMENT_ME();}
void SDL_DestroyTexture(SDL_Texture*) {IMPLEMENT_ME();}
int SDL_GetWindowDisplayIndex(SDL_Window*) {IMPLEMENT_ME();}
int SDL_GetWindowFlags(SDL_Window*) {IMPLEMENT_ME();}
int SDL_GetWindowID(SDL_Window*) {IMPLEMENT_ME();}
void SDL_GetWindowSize(SDL_Window*, int*, int*) {IMPLEMENT_ME();}
void SDL_SetWindowFullscreen(SDL_Window*, unsigned int) {IMPLEMENT_ME();}
void SDL_SetWindowSize(SDL_Window*, int, int) {IMPLEMENT_ME();}
void SDL_WarpMouseInWindow(SDL_Window*, int, int) {IMPLEMENT_ME();}
void SDL_LockAudio(void) {IMPLEMENT_ME();}
void SDL_UnlockAudio(void) {IMPLEMENT_ME();}
void Mix_PauseMusic(void) {IMPLEMENT_ME();}
void Mix_ResumeMusic(void) {IMPLEMENT_ME();}
void Mix_SetMusicPosition(int) {IMPLEMENT_ME();}
void Mix_HaltChannel(int) {IMPLEMENT_ME();}
int SDL_BuildAudioCVT(void*, int, int, int, int, int, int) {IMPLEMENT_ME();}
void SDL_ConvertAudio(void*) {IMPLEMENT_ME();}
void Mix_SetPanning(int, int, int) {IMPLEMENT_ME();}
void Mix_PlayChannel(int, void*, int) {IMPLEMENT_ME();}
int Mix_Playing(int) {IMPLEMENT_ME();}
void Mix_AllocateChannels(int) {IMPLEMENT_ME();}
