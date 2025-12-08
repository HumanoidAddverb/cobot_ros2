/**
 * @file socket_server.h
 * @author Siddhi Jain (siddhi.jainu@addverb.com)
 * @brief Server Implementation for Socket Programming
 * used for sending and receiving data in string format using sockets
 * @version 0.1
 * @date 2023-09-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SOCKET_SERVER_H_
#define SOCKET_SERVER_H_

#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/tcp.h>
#include <signal.h>
#include <iostream>
#include <errno.h>
#include <sys/time.h>
#include <poll.h>
#include <fstream>
#include <cassert>
#include <vector>
#include "socket_config.h"

class SocketServer
{
public:
    inline SocketServer()
    {
        socket_created_ = false;
    };

    inline ~SocketServer(){};

    /// @brief method for socket craetion
    void createSocket();

    /// @brief initialisation method for server
    /// @return
    bool initConnect(int &);

    /// @brief method to close connection
    void closeConnection();

    /// @brief shutdown the serve end
    void terminate();

protected:
    /// @brief server address
    struct sockaddr_in server_addr_;

    /// @brief client address
    struct sockaddr_in client_addr_;

    /// @brief file descriptor for the server
    int server_fd_;

    /// @brief file descriptor of client
    int client_fd_;

    /// @brief get the server address
    virtual void getServerAddr_();

    /// @brief parse netwrok config file to get ip and port
    /// @param ip 
    /// @param port 
    void parseNetworkConfig_(std::string&ip,int&port);

private:
    /// @brief socket creation flag
    /// subsequent connect calls to server socket must accept on the same socket
    bool socket_created_;


};

#endif
