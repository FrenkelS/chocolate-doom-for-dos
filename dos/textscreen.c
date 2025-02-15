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

#include "textscreen.h"
#include "txt_main.h"

void TXT_AddWidget(txt_window_t*, void*) {IMPLEMENT_ME();}
void TXT_ClearTable(txt_window_t*) {IMPLEMENT_ME();}
void TXT_CloseWindow(txt_window_t*) {IMPLEMENT_ME();}
void TXT_DispatchEvents(void) {IMPLEMENT_ME();}
void TXT_DrawDesktop(void) {IMPLEMENT_ME();}
int TXT_Init(void) {IMPLEMENT_ME();}
void TXT_LowerWindow(txt_window_t*) {IMPLEMENT_ME();}
txt_label_t *TXT_NewLabel(char*) {IMPLEMENT_ME();}
int *TXT_NewStrut(int, int) {IMPLEMENT_ME();}
txt_table_t *TXT_NewTable(int) {IMPLEMENT_ME();}
int *TXT_NewWindow(char*) {IMPLEMENT_ME();}
txt_window_action_t *TXT_NewWindowAction(int, char*) {IMPLEMENT_ME();}
void TXT_SetColor(int, int, int, int) {IMPLEMENT_ME();}
void TXT_SetDesktopTitle(char*) {IMPLEMENT_ME();}
void TXT_SetFGColor(txt_label_t*, int) {IMPLEMENT_ME();}
void TXT_SetLabel(txt_label_t*, char*) {IMPLEMENT_ME();}
void TXT_SetWindowAction(txt_window_t*, int, txt_window_action_t*) {IMPLEMENT_ME();}
void TXT_SetWindowPosition(txt_window_t*, int, int, int, int) {IMPLEMENT_ME();}
void TXT_SignalConnect(TXT_UNCAST_ARG(widget), const char *signal_name, TxtWidgetSignalFunc func, void *user_data) {IMPLEMENT_ME();}
void TXT_Sleep(int) {IMPLEMENT_ME();}
void TXT_Shutdown(void) {IMPLEMENT_ME();}
int TXT_GetChar(void) {IMPLEMENT_ME();}
unsigned char *TXT_GetScreenData(void) {IMPLEMENT_ME();}
void TXT_SetWindowTitle(char*) {IMPLEMENT_ME();}
void TXT_UpdateScreen(void) {IMPLEMENT_ME();}
