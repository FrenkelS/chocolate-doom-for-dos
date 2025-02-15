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

#ifndef __TEXTSCREEN__
#define __TEXTSCREEN__

#define txt_color_t int
#define txt_label_t int
#define txt_table_t int
#define txt_window_t int
#define txt_window_action_t int

#define TXT_UNCAST_ARG_NAME(name) uncast_ ## name
#define TXT_UNCAST_ARG(name)   void * TXT_UNCAST_ARG_NAME(name)
#define TXT_CAST_ARG(type, name)  type *name = (type *) uncast_ ## name

typedef void (*TxtWidgetSignalFunc)(TXT_UNCAST_ARG(widget), void *user_data);

#define TXT_COLOR_BLUE 0
#define TXT_COLOR_BRIGHT_WHITE 0
#define TXT_COLOR_YELLOW 0
#define TXT_HORIZ_CENTER 0
#define TXT_HORIZ_LEFT 0
#define TXT_HORIZ_RIGHT 0
#define TXT_VERT_BOTTOM 0
#define TXT_VERT_CENTER 0
#define TXT_SCREEN_H 0
#define TXT_SCREEN_W 0

void TXT_AddWidget(txt_window_t*, void*);
void TXT_ClearTable(txt_window_t*);
void TXT_CloseWindow(txt_window_t*);
void TXT_DispatchEvents(void);
void TXT_DrawDesktop(void);
int TXT_Init(void);
void TXT_LowerWindow(txt_window_t*);
txt_label_t *TXT_NewLabel(char*);
int *TXT_NewStrut(int, int);
txt_table_t *TXT_NewTable(int);
int *TXT_NewWindow(char*);
txt_window_action_t *TXT_NewWindowAction(int, char*);
void TXT_SetColor(int, int, int, int);
void TXT_SetDesktopTitle(char*);
void TXT_SetFGColor(txt_label_t*, int);
void TXT_SetLabel(txt_label_t*, char*);
void TXT_SetWindowAction(txt_window_t*, int, txt_window_action_t*);
void TXT_SetWindowPosition(txt_window_t*, int, int, int, int);
void TXT_SignalConnect(TXT_UNCAST_ARG(widget), const char *signal_name,
                       TxtWidgetSignalFunc func, void *user_data);
void TXT_Sleep(int);
void TXT_Shutdown(void);

#endif
