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

#include <sys/nearptr.h>

#include "chocdos.h"

#include "textscreen.h"
#include "txt_io.h"
#include "txt_main.h"


int TXT_Init(void)
{
	I_SetScreenMode(3);
	return 1;
}


void TXT_SetWindowTitle(const char *title)
{
	UNUSED(title);
}


unsigned char *TXT_GetScreenData(void)
{
	return (unsigned char*)(0xb8000 + __djgpp_conventional_base);
}


void TXT_UpdateScreen(void)
{
}


int TXT_GetChar(void)
{
	return 1;
}


void TXT_Shutdown(void)
{
	TXT_GotoXY(0, 23);
	printf("\n");
}


static int bgcolor;
static txt_color_t fgcolor;
static int cur_x;
static int cur_y;

void TXT_BGColor(int color, int blinking)
{
	UNUSED(blinking);

	bgcolor = color;
}


void TXT_FGColor(txt_color_t color)
{
	fgcolor = color;
}


void TXT_GotoXY(int x, int y)
{
	union REGS regs;
	regs.h.ah = 2;
	regs.h.bh = 0;
	regs.h.dl = x;
	regs.h.dh = y;
	int386(0x10, &regs, &regs); // Set text pos

	cur_x = x;
	cur_y = y;
}


void TXT_Puts(const char *s)
{
	printf("%s\n", s);
}


void TXT_PutChar(int c)
{
	union REGS regs;
	regs.h.ah = 9;
	regs.h.al = c;
	regs.h.bh = 0;
	regs.h.bl = (bgcolor << 4) | fgcolor;
	regs.w.cx = 1;
	int386(0x10, &regs, &regs);

	cur_x++;
	TXT_GotoXY(cur_x, cur_y);
}


void TXT_AddWidget(TXT_UNCAST_ARG(table), TXT_UNCAST_ARG(widget)) {IMPLEMENT_ME();}
void TXT_ClearTable(TXT_UNCAST_ARG(table)) {IMPLEMENT_ME();}
void TXT_CloseWindow(txt_window_t*) {IMPLEMENT_ME();}
void TXT_DispatchEvents(void) {IMPLEMENT_ME();}
void TXT_DrawDesktop(void) {IMPLEMENT_ME();}
int TXT_LowerWindow(txt_window_t*) {IMPLEMENT_ME();}
txt_label_t *TXT_NewLabel(const char*) {IMPLEMENT_ME();}
txt_strut_t *TXT_NewStrut(int, int) {IMPLEMENT_ME();}
txt_table_t *TXT_NewTable(int) {IMPLEMENT_ME();}
txt_window_t *TXT_NewWindow(const char*) {IMPLEMENT_ME();}
txt_window_action_t *TXT_NewWindowAction(int, const char*) {IMPLEMENT_ME();}
void TXT_SetColor(txt_color_t, int, int, int) {IMPLEMENT_ME();}
void TXT_SetDesktopTitle(const char*) {IMPLEMENT_ME();}
void TXT_SetFGColor(txt_label_t*, txt_color_t) {IMPLEMENT_ME();}
void TXT_SetLabel(txt_label_t*, const char*) {IMPLEMENT_ME();}
void TXT_SetWindowAction(txt_window_t*, txt_horiz_align_t, TXT_UNCAST_ARG(action)) {IMPLEMENT_ME();}
void TXT_SetWindowPosition(txt_window_t*, txt_horiz_align_t, txt_vert_align_t, int, int) {IMPLEMENT_ME();}
void TXT_SignalConnect(TXT_UNCAST_ARG(widget), const char *signal_name, TxtWidgetSignalFunc func, void *user_data) {IMPLEMENT_ME();}
void TXT_Sleep(int) {IMPLEMENT_ME();}
