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

#include "chocdos.h"

#include "pcsound.h"

#include "SDL.h"

#include "a_inter.h"
#include "a_taskmn.h"


#define SND_TICRATE     140     // tic rate for updating sound

#define TIMER_FREQ 1193181 /* hz */

static SDL_bool PCFX_Installed;

static task *PCFX_ServiceTask;
static pcsound_callback_func func;

static int PCFX_LastSample;

void PCSound_SetSampleRate(int rate)
{
	UNUSED(rate);
}


static void PCFX_Service(void)
{
	int duration;
	int freq;

	func(&duration, &freq);

	if (freq != PCFX_LastSample)
	{
		PCFX_LastSample = freq;
		if (freq)
		{
			int value = TIMER_FREQ / freq;
			outp(0x43, 0xb6);
			outp(0x42, LOBYTE(value));
			outp(0x42, HIBYTE(value));
			outp(0x61, inp(0x61) | 0x3);
		} else
			outp(0x61, inp(0x61) & 0xfc);
	}
}


int PCSound_Init(pcsound_callback_func callback_func)
{
	PCFX_ServiceTask = TS_ScheduleTask(PCFX_Service, SND_TICRATE, 2);
	func = callback_func;
	PCFX_Installed = SDL_TRUE;
	return 1;
}


void PCSound_Shutdown(void)
{
	if (PCFX_Installed)
	{
		uint32_t flags = DisableInterrupts();

		// Turn off speaker
		outp(0x61, inp(0x61) & 0xfc);

		RestoreInterrupts(flags);

		TS_Terminate(PCFX_ServiceTask);
	}
}
