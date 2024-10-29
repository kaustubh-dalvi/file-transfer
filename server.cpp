#include <iostream>
#include <cstring>

#ifdef _WIN32
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#endif

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed.\n";
        return 1;
    }
#endif

    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
#ifdef _WIN32
        WSACleanup();
#endif
        return -1;
    }

    // Setting up the address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
#ifdef _WIN32
        closesocket(server_fd);
        WSACleanup();
#else
        close(server_fd);
#endif
        return -1;
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
#ifdef _WIN32
        closesocket(server_fd);
        WSACleanup();
#else
        close(server_fd);
#endif
        return -1;
    }
    std::cout << "Server is listening on port " << PORT << "...\n";

    // Accepting a connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
#ifdef _WIN32
        closesocket(server_fd);
        WSACleanup();
#else
        close(server_fd);
#endif
        return -1;
    }

    // Receiving data
    int valread = recv(new_socket, buffer, BUFFER_SIZE, 0);
    if (valread > 0) {
        std::cout << "Received message: " << buffer << std::endl;
    }

    // Closing the socket
#ifdef _WIN32
    closesocket(new_socket);
    closesocket(server_fd);
    WSACleanup();
#else
    close(new_socket);
    close(server_fd);
#endif

    return 0;
}




//  Complie command for windows 
//  g++ server.cpp -o server -lws2_32
//  g++ client.cpp -o client -lws2_32


//  Complie command for Mac
//  g++ server.cpp -o server
//  g++ client.cpp -o client
