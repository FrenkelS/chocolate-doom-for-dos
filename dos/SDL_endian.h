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

#ifndef __SDL_ENDIAN__
#define __SDL_ENDIAN__

#define SDL_SwapLE16(x) (x)
#define SDL_SwapLE32(x) (x)

#define SDL_SwapBE16(x) __builtin_bswap16(x)
#define SDL_SwapBE32(x) __builtin_bswap32(x)

#endif
