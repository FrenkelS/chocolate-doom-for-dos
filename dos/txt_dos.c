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

#include "txt_main.h"
#include "doomkeys.h"

SDL_Window *TXT_SDLWindow;

static unsigned char *screendata;


static const int scancode_translate_table[] = SCANCODE_TO_KEYS_ARRAY;


void TXT_SetWindowTitle(const char *title)
{
	UNUSED(title);
}


int TXT_Init(void)
{
	SDL_InitSubSystem(SDL_INIT_TIMER);

	I_SetScreenMode(3);
	__djgpp_nearptr_enable();
	screendata = (unsigned char*)(0xb8000 + __djgpp_conventional_base);
	return 1;
}


#define PEL_WRITE_ADR	0x3c8
#define PEL_DATA		0x3c9

void TXT_SetColor(txt_color_t color, int r, int g, int b)
{
	outp(PEL_WRITE_ADR, color);
	outp(PEL_DATA, r >> 2);
	outp(PEL_DATA, g >> 2);
	outp(PEL_DATA, b >> 2);
}


int TXT_GetChar(void)
{
	SDL_Event ev;

	while (SDL_PollEvent(&ev))
	{
		if (ev.type == SDL_KEYDOWN)
		{
			return scancode_translate_table[ev.key.keysym.scancode];
		}
	}

	return 0;
}


unsigned char *TXT_GetScreenData(void)
{
	return screendata;
}


void TXT_GetKeyDescription(int key, char *buf, size_t buf_len)
{
	const char *keyname;

	switch (key)
	{
		case   9: keyname = "TAB";    break;
		case  13: keyname = "ENTER";  break;
		case  27: keyname = "ESC";    break;
		case  32: keyname = "SPACE";  break;
		case 127: keyname = "BACKSP"; break;
		case 157: keyname = "CTRL";   break;
		case 172: keyname = "LEFT";   break;
		case 173: keyname = "UP";     break;
		case 174: keyname = "RIGHT";  break;
		case 175: keyname = "DOWN";   break;
		case 182: keyname = "SHIFT";  break;
		case 184: keyname = "ALT";    break;
		case 199: keyname = "HOME";   break;
		case 201: keyname = "PAGEUP"; break;
		case 207: keyname = "END";    break;
		case 209: keyname = "PGDN";   break;
		case 210: keyname = "INSERT"; break;
		case 211: keyname = "DELETE"; break;
		case 215: keyname = "F11";    break;
		case 216: keyname = "F12";    break;
		case 255: keyname = "PAUSE";  break;
		default:
			if (44 <= key && key <= 93)
				snprintf(buf, buf_len, "%c", key);
			else if ('a' <= key && key <= 'z')
				snprintf(buf, buf_len, "%c", key - 32);
			else if (187 <= key && key <= 196)
				snprintf(buf, buf_len, "F%i", key - 186);
			else
				snprintf(buf, buf_len, "??%i", key);
			return;
	}

	snprintf(buf, buf_len, "%s", keyname);
}


void TXT_GetMousePosition(int *x, int *y)
{
	*x = 0;
	*y = 0;
}


int TXT_UnicodeCharacter(unsigned int c)
{
	return c;
}


void TXT_UpdateScreen(void)
{
}


void TXT_Sleep(int timeout)
{
	if (timeout == 0)
	{
		while (SDL_PollEvent(NULL) == 0)
		{
		}
	}
	else
	{
		unsigned int start_time = SDL_GetTicks();

		while (SDL_GetTicks() < start_time + timeout)
		{
			if (SDL_PollEvent(NULL) != 0)
			{
				break;
			}
		}
	}
}


void TXT_Shutdown(void)
{
	SDL_Quit();
	I_SetScreenMode(3);
}


int TXT_GetModifierState(txt_modifier_t mod)
{
	UNUSED(mod);
	return 0;
}


int TXT_vsnprintf(char *buf, size_t buf_len, const char *s, va_list args)
{
	return vsnprintf(buf, buf_len, s, args);
}


void TXT_SetInputMode(txt_input_mode_t mode)
{
	UNUSED(mode);
}


void TXT_StringCopy(char *dest, const char *src, size_t dest_len)
{
	if (dest_len < 1)
	{
		return;
	}

	dest[dest_len - 1] = '\0';
	strncpy(dest, src, dest_len - 1);
}


int TXT_snprintf(char *buf, size_t buf_len, const char *s, ...)
{
	va_list args;
	int result;
	va_start(args, s);
	result = TXT_vsnprintf(buf, buf_len, s, args);
	va_end(args);
	return result;
}


void TXT_SDL_SetEventCallback(TxtSDLEventCallbackFunc callback, void *user_data) {IMPLEMENT_ME();}
