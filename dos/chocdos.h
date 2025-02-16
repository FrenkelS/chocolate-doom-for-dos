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

#ifndef __CHOCDOS__
#define __CHOCDOS__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "compiler.h"

#define UNUSED(x)	(x = x)	// for pesky compiler / lint warnings

#define IMPLEMENT_ME() I_Error("Implement me: %s: %s @ %i\n", __FILE__, __PRETTY_FUNCTION__ , __LINE__)

void I_Error (const char *error, ...);
void I_SetScreenMode(uint16_t mode);

#endif
