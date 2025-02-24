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

#include "m_misc.h"


void I_Error2(const char *error, ...);


void I_Error(const char *error, ...)
{
	char msgbuf[512];
	va_list argptr;

	I_SetScreenMode(3);

	va_start(argptr, error);
	memset(msgbuf, 0, sizeof(msgbuf));
	M_vsnprintf(msgbuf, sizeof(msgbuf), error, argptr);
	va_end(argptr);

	I_Error2(msgbuf);
}
