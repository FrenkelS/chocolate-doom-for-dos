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

#ifndef __TXT_MAIN__
#define __TXT_MAIN__

#define TXT_SCREEN_W 0
#define TXT_SCREEN_H 0

int TXT_GetChar(void);
unsigned char *TXT_GetScreenData(void);
int TXT_Init(void);
void TXT_SetWindowTitle(char*);
void TXT_Shutdown(void);
void TXT_Sleep(int);
void TXT_UpdateScreen(void);

#endif
