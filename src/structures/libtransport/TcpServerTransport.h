/// @author [Software Engineer]
/// @date [2024]
/// @name TcpServerTransport
/// @{

#ifndef TCPSERVER_TRANSPORT_H_
#define TCPSERVER_TRANSPORT_H_

#include <sys/socket.h>
#include <arpa/inet.h>

// From C++ STL
#include <array>

#define MAX_PACKET_SIZE 1024
namespace libdsa
{
    namespace libstructures
    {
        class TcpServerTransport
        {
        public:
            /// @brief Builds the @c TcpServerTransport object, but does not ready it for immediate use.
            /// @param ip IP address the user wants to communicate with.
            /// @param port The port the Server Socket will use.
            TcpServerTransport(uint32_t ip, uint16_t port = 8080);

            /// @brief Opens the @c TcpServerTransport socket for send/receive.
            /// @return Whether the attempt to open the transport was successful.
            bool open();

            /// @brief Closes the @c TcpServerTransport socket.
            /// @return Whether the attempt to close the socket was successful.
            bool close();

            bool send(std::array<char, MAX_PACKET_SIZE> buffer);

            std::array<char, MAX_PACKET_SIZE> receive(std::array<char, MAX_PACKET_SIZE> buffer);

        private:
            /// @brief Reference ID to the underlying socket file descriptor
            int _socket_fd;

            struct sockaddr_in _address;

        }; // TcpServerTransport

        libdsa::libstructures::TcpServerTransport::TcpServerTransport(uint32_t ip, uint16_t port)
        {
            this->_address.sin_port = htons(port);
            this->_address.sin_family = AF_INET6;
            this->_address.sin_addr.s_addr = ip;

            if (this->_socket_fd = socket(AF_INET6, SOCK_STREAM, 0) < 0)
            {
                printf("*** ERROR: Unable to create server socket");
                exit(-1);
            }
        }

        bool libdsa::libstructures::TcpServerTransport::open()
        {

            if (bind(this->_socket_fd, (const struct sockaddr *)&(this->_address), 1024) == 0)
            {
                printf("*** ERROR: Unable to bind server socket to port %u", this->_address.sin_port);
                return false;
            }

            if (listen(this->_socket_fd, 20) < 0)
            {
                printf("*** ERROR: More than 20 connection attempts made. Unable to find a connection for server.\n");
                return false;
            }

            if (accept(this->_socket_fd, (sockaddr *)&this->_address, ((socklen_t *)sizeof(this->_address))) < 0)
            {
                printf("*** ERROR: Server unable to accept client connection.\n");
                return false;
            }

            return true;
        }
    } // libstructures
} // libdsa

#endif // TCPSERVER_TRANSPORT_H_

/// @}
