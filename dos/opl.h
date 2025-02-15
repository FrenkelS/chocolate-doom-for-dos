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

#ifndef __OPL__
#define __OPL__

#define opl_init_result_t int

#define OPL_NUM_VOICES 9
#define OPL_REGS_LEVEL 0
#define OPL_REGS_TREMOLO 0
#define OPL_REGS_ATTACK 0
#define OPL_REGS_SUSTAIN 0
#define OPL_REGS_WAVEFORM 0
#define OPL_REGS_FEEDBACK 0
#define OPL_REGS_FEEDBACK 0
#define OPL_REGS_FREQ_1 0
#define OPL_REGS_FREQ_2 0
#define OPL_INIT_NONE 0
#define OPL_INIT_OPL3 1

void OPL_AdjustCallbacks(float);
void OPL_ClearCallbacks(void);
opl_init_result_t OPL_Init(unsigned int);
void OPL_InitRegisters(int);
void OPL_Lock(void);
void OPL_SetCallback(int, void (*)(void *), void*);
void OPL_SetPaused(int);
void OPL_SetSampleRate(unsigned int);
void OPL_Shutdown(void);
void OPL_Unlock(void);
void OPL_WriteRegister(int, int);

#endif
