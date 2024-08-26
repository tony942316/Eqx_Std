#ifdef __linux__

import <unistd.h>;
import <sys/types.h>;
import <sys/socket.h>;
import <netinet/in.h>;
import <netdb.h>;
import <arpa/inet.h>;

#endif // __linux__

#ifdef _WIN32

import <windows.h>;
import <winsock2.h>;
import <ws2tcpip.h>;

#endif // _WIN32
