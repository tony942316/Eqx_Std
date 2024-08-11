#ifndef OSHEADER_OSH_HPP
#define OSHEADER_OSH_HPP

#ifdef __linux__

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define LINUX true
#define WINDOWS false

#define INVALID_SOCKET -1;
#define SOCKET_ERROR -1;

#endif // __linux__

#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN
#define NOGDICAPMASKS
#define NOSYSMETRICS
#define NOMENUS
#define NOICONS
#define NOSYSCOMMANDS
#define NORASTEROPS
#define OEMRESOURCE
#define NOATOM
#define NOCLIPBOARD
#define NOCOLOR
#define NOCTLMGR
#define NODRAWTEXT
#define NOKERNEL
#define NONLS
#define NOMEMMGR
#define NOMETAFILE
#define NOOPENFILE
#define NOSCROLL
#define NOSERVICE
#define NOSOUND
#define NOTEXTMETRIC
#define NOWH
#define NOCOMM
#define NOKANJI
#define NOHELP
#define NOPROFILER
#define NODEFERWINDOWPOS
#define NOMCX
#define NORPC
#define NOPROXYSTUB
#define NOIMAGE
#define NOTAPE
#define NOMINMAX

#pragma warning(push)
#pragma warning(disable : 5105)
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma warning(pop)
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Mswsock.lib")
#pragma comment(lib, "AdvApi32.lib")

#define LINUX false
#define WINDOWS true

#define SOCK_CLOEXEC 0x80000

#endif // _WIN32

namespace osm::socket
{
    namespace domain
    {
        constexpr auto inet = AF_INET;
    }

    namespace type
    {
        constexpr auto stream = SOCK_STREAM;
    }

    namespace error
    {
        constexpr auto invalid = INVALID_SOCKET;
        constexpr auto socket = SOCKET_ERROR;
    }

    namespace level
    {
        constexpr auto socket = SOL_SOCKET;
    }

    namespace option
    {
        constexpr auto reuseaddr = SO_REUSEADDR;
    }

    namespace flag
    {
        constexpr auto cloexec = SOCK_CLOEXEC;
    }

#if LINUX
    using socket_t = int;
#elif WINDOWS
    using socket_t = SOCKET;
#endif

    void wsaInit() noexcept
    {
#if LINUX
#elif WINDOWS
        WSADATA wsaData = {0};
        WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif
    }

    [[nodiscard]] socket_t open(const int domain, const int type) noexcept
    {
        return ::socket(domain, type, 0);
    }

    [[nodiscard]] int close(const socket_t fd) noexcept
    {
#if LINUX
        return ::close(fd);
#elif WINDOWS
        return ::closesocket(fd);
#endif
    }

    [[nodiscard]] int send(const socket_t fd,
        const char* msg, const unsigned int len) noexcept
    {
#if LINUX
        return static_cast<int>(::send(fd, msg, len, 0));
#elif WINDOWS
        return ::send(fd, msg, len, 0);
#endif
    }

    [[nodiscard]] int recv(const socket_t fd, char* buf,
        const size_t len) noexcept
    {
#if LINUX
        return static_cast<int>(::recv(fd, buf, len, 0));
#elif WINDOWS
        return ::recv(fd, buf, static_cast<int>(len), 0);
#endif
    }

    [[nodiscard]] int connect(const socket_t fd, const char* ip,
        unsigned short port) noexcept
    {
        auto server_address = sockaddr_in{};
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(port);

        inet_pton(AF_INET, ip, &server_address.sin_addr);

        return ::connect(fd, reinterpret_cast<sockaddr*>(&server_address),
            sizeof(server_address));
    }

    [[nodiscard]] int setsockopt(const socket_t fd, const int level,
        const int option_name) noexcept
    {
        static auto enable = 1;
#if LINUX
        return ::setsockopt(fd, level, option_name,
            reinterpret_cast<void*>(&enable), sizeof(enable));
#elif WINDOWS
        return ::setsockopt(fd, level, option_name, (const char*)&enable,
            sizeof(enable));
#endif
    }

    [[nodiscard]] int bind(const socket_t fd,
        const unsigned short port) noexcept
    {
        auto server_address = sockaddr_in();
        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = INADDR_ANY;
        server_address.sin_port = htons(port);

        return ::bind(fd, reinterpret_cast<sockaddr*>(&server_address),
            sizeof(server_address));
    }

    constexpr auto listencount = 5;
    [[nodiscard]] int listen(const socket_t fd) noexcept
    {
        return ::listen(fd, listencount);
    }

    [[nodiscard]] socket_t accept(const socket_t fd,
        [[maybe_unused]] int flags) noexcept
    {
        auto client_address = sockaddr_in();
        socklen_t client_address_size = sizeof(client_address);
#if LINUX
        return ::accept4(fd, reinterpret_cast<sockaddr*>(&client_address),
            &client_address_size, flags);
#elif WINDOWS
        return ::accept(fd, reinterpret_cast<sockaddr*>(&client_address),
            &client_address_size);
#endif
    }
}

#endif // OSHEADER_OSH_HPP
