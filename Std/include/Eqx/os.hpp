#ifndef EQX_OS_HPP
#define EQX_OS_HPP

#ifdef __linux__

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#endif // __linux__

#ifdef _WIN32

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#endif // _WIN32

#endif // EQX_OS_HPP
