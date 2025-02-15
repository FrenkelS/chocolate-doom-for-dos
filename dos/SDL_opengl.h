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

#ifndef __SDL_OPENGL__
#define __SDL_OPENGL__

#define SDL_Renderer int
#define SDL_Texture int

#define Uint16 uint16_t

#define SDL_WINDOWEVENT_EXPOSED 0
#define SDL_WINDOWEVENT_RESIZED 1
#define SDL_WINDOWEVENT_MINIMIZED 2
#define SDL_WINDOWEVENT_MAXIMIZED 3
#define SDL_WINDOWEVENT_RESTORED 4
#define SDL_WINDOWEVENT_FOCUS_GAINED 5
#define SDL_WINDOWEVENT_FOCUS_LOST 6
#define SDL_WINDOWEVENT_MOVED 7

#define SDL_HINT_RENDER_SCALE_QUALITY 0

#define KMOD_LALT 0
#define KMOD_RALT 0

#define SDL_SCANCODE_RETURN 0
#define SDL_SCANCODE_KP_ENTER 1

#define SDL_WINDOW_BORDERLESS 0
#define SDL_WINDOW_FULLSCREEN 0
#define SDL_WINDOW_FULLSCREEN_DESKTOP 0
#define SDL_WINDOW_RESIZABLE 0
#define SDL_WINDOW_ALLOW_HIGHDPI 0

#define SDL_WINDOWPOS_UNDEFINED 0

#define SDL_PIXELFORMAT_ARGB8888 0

#define SDL_TEXTUREACCESS_TARGET 0
#define SDL_TEXTUREACCESS_STREAMING 0

#define SDL_RENDERER_TARGETTEXTURE 0
#define SDL_RENDERER_PRESENTVSYNC 0
#define SDL_RENDERER_SOFTWARE 0

#define SDL_ALPHA_OPAQUE 0

#define SDL_max(x, y) (((x) > (y)) ? (x) : (y))

typedef struct SDL_DisplayMode
{
	int refresh_rate;
} SDL_DisplayMode;

typedef struct SDL_Rect
{
	int x;
	int y;
	int w;
	int h;
} SDL_Rect;

typedef struct SDL_RendererInfo
{
	int max_texture_width;
	int max_texture_height;
} SDL_RendererInfo;

typedef struct SDL_Color
{
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
} SDL_Color;

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


SDL_Renderer *SDL_CreateRenderer(SDL_Window*, int, Uint32);
SDL_Surface *SDL_CreateRGBSurface(Uint32, int, int, int, Uint32, Uint32, Uint32, Uint32);
SDL_Surface *SDL_CreateRGBSurfaceFrom(void*, int, int, int, int, Uint32, Uint32, Uint32, Uint32);
SDL_Surface *SDL_CreateRGBSurfaceWithFormatFrom(void*, int, int, int, int, Uint32);
SDL_Texture* SDL_CreateTexture(SDL_Renderer*, Uint32, int, int, int);
SDL_Window *SDL_CreateWindow(const char*, int, int, int, int, Uint32);
void SDL_DestroyRenderer(SDL_Renderer*);
void SDL_DestroyTexture(SDL_Texture*);
int SDL_FillRect(SDL_Surface*, const SDL_Rect*, Uint32);
void SDL_FreeSurface(SDL_Surface*);
int SDL_GetCurrentDisplayMode(int, SDL_DisplayMode*);
int SDL_GetDisplayBounds(int, SDL_Rect*);
int SDL_GetNumVideoDisplays(void);
int SDL_GetRendererInfo(SDL_Renderer*, SDL_RendererInfo*);
int SDL_GetRendererOutputSize(SDL_Renderer*, int*, int*);
int SDL_GetWindowDisplayIndex(SDL_Window*);
int SDL_GetWindowFlags(SDL_Window*);
int SDL_GetWindowID(SDL_Window*);
void SDL_GetWindowSize(SDL_Window*, int*, int*);
int SDL_LockTexture(SDL_Texture*, const SDL_Rect*, void**, int*);
int SDL_LowerBlit(SDL_Surface*, SDL_Rect*, SDL_Surface*, SDL_Rect*);
int SDL_PollEvent(SDL_Event*);
void SDL_PumpEvents(void);
int SDL_RenderClear(SDL_Renderer*);
int SDL_RenderCopy(SDL_Renderer*, SDL_Texture*, const SDL_Rect*, const SDL_Rect*);
void SDL_RenderPresent(SDL_Renderer*);
int SDL_RenderSetIntegerScale(SDL_Renderer*, SDL_bool);
int SDL_RenderSetLogicalSize(SDL_Renderer*, int, int);
int SDL_SetPaletteColors(SDL_Palette*, const SDL_Color*, int, int);
int SDL_SetRelativeMouseMode(SDL_bool);
int SDL_SetRenderDrawColor(SDL_Renderer*, Uint8, Uint8, Uint8, Uint8);
int SDL_SetRenderTarget(SDL_Renderer*, SDL_Texture*);
void SDL_SetWindowFullscreen(SDL_Window*, unsigned int);
void SDL_SetWindowIcon(SDL_Window*, SDL_Surface*);
void SDL_SetWindowMinimumSize(SDL_Window*, int, int);
void SDL_SetWindowSize(SDL_Window*, int, int);
void SDL_SetWindowTitle(SDL_Window*, const char*);
void SDL_UnlockTexture(SDL_Texture*);
void SDL_WarpMouseInWindow(SDL_Window*, int, int);

#endif
