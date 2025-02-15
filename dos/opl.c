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

#include "opl.h"


void OPL_SetSampleRate(unsigned int rate)
{
	UNUSED(rate);
}

opl_init_result_t OPL_Init(unsigned int port_base)
{
	UNUSED(port_base);
	return 0;
}


void OPL_AdjustCallbacks(float) {IMPLEMENT_ME();}
void OPL_ClearCallbacks(void) {IMPLEMENT_ME();}
void OPL_InitRegisters(int) {IMPLEMENT_ME();}
void OPL_Lock(void) {IMPLEMENT_ME();}
void OPL_SetCallback(uint64_t, opl_callback_t, void*) {IMPLEMENT_ME();}
void OPL_SetPaused(int) {IMPLEMENT_ME();}
void OPL_Shutdown(void) {IMPLEMENT_ME();}
void OPL_Unlock(void) {IMPLEMENT_ME();}
void OPL_WriteRegister(int, int) {IMPLEMENT_ME();}
