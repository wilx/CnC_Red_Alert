#pragma once

enum SocketEvent
{
    SOCKET_READ,
    SOCKET_WRITE,
    SOCKET_ERROR,
};

typedef void (*SocketCallback)(int, SocketEvent, void *);

bool Socket_Register_Select(int socket, SocketCallback callback, void *data);
void Socket_Unregister_Select(int socket);

void Socket_Check_Write(int socket, bool check);

void Socket_Select();