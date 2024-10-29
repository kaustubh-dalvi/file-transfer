File Transfer App
A C++ project that enables seamless transfer of text, audio, and video files between two laptops on the same network using socket programming. The app sets up a TCP connection between a server and a client, making data transfer fast and secure over a shared network. The project is compatible with Windows, macOS, and Linux.

Features
Cross-Platform Compatibility: Runs on Windows, macOS, and Linux with minor platform-specific modifications.
Versatile Data Transfer: Supports the transfer of text, audio, and video files.
Reliable Connection: Uses the TCP protocol for stable and secure data transmission.

Getting Started

Prerequisites
Compiler: Ensure you have g++ installed (part of GCC for Linux/macOS or MinGW for Windows).
Git: Install Git to manage and push the project to GitHub.


Setup and Installation
1. Clone the Repository (or manually download files):
git clone https://github.com/username/file-transfer-app.git
cd file-transfer-app


2. Compile the Code: Compile the server and client files separately.
for Linux and MacOS
g++ server.cpp -o server
g++ client.cpp -o client

for Windows
g++ server.cpp -o server -lws2_32
g++ client.cpp -o client -lws2_32

Running the projects
1. Open a terminal in the project folder.

2. Run the client executable:
./client           # for Linux/macOS
client.exe         # for Windows


3.The client will attempt to connect to the server. Once connected, it can send data (e.g., text, audio, video files).


Configuration Note
In client.cpp, make sure to replace the placeholder SERVER_IP with the actual IP address of the server machine:Configuration Note
In client.cpp, make sure to replace the placeholder SERVER_IP with the actual IP address of the server machine:

File Transfer Process
Send Data: After the client successfully connects to the server, you can send messages or file data from the client to the server.
Receive Data: The server receives data and displays it in the terminal. In the case of large file transfers, consider adding file handling and buffering logic.

License
This project is open-source and available under the MIT License. Feel free to use, modify, and distribute the code as needed.

