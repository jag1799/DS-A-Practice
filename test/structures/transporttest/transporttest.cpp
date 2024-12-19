/// @author [Software Engineer]
/// @date [2024]
/// @file tcpservertransporttest
/// @brief Contains test functions for all member functions and use cases of the @c TcpServerTransport class.

/// Class Header
#include <TcpServerTransport.h>

// From Gtest
#include <gtest/gtest.h>

TEST(TcpServerTransportTest, testValidServerCreation)
{
    ASSERT_NO_THROW(libdsa::libstructures::TcpServerTransport server(INADDR_ANY, 8080U));
}

TEST(TcpServerTransportTest, testServerOpenToManyAttempts)
{
    libdsa::libstructures::TcpServerTransport server(INADDR_ANY, 8080U);

    ASSERT_EQ(server.open(), false);
}