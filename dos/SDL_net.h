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

#ifndef __SDL_NET__
#define __SDL_NET__

#define UDPsocket int*

#define INADDR_BROADCAST 0

typedef struct IPaddress
{
	int host;
	int port;
} IPaddress;

typedef struct UDPpacket
{
	int channel;
	char *data;
	int len;
	IPaddress address;
} UDPpacket;

void SDLNet_Init(void);
UDPsocket SDLNet_UDP_Open(int);
UDPpacket *SDLNet_AllocPacket(int);
int SDLNet_ResolveHost(void*, void*, int);
int SDLNet_UDP_Send(void*, int, void*);
int SDLNet_UDP_Recv(void*, void*);
char *SDLNet_GetError(void);
int SDLNet_Read32(void*);
short SDLNet_Read16(void*);

#endif
