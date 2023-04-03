#include "chatserver.hpp"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    if(argc < 3)
    {
        cerr << "Invalid input!" << endl;
        exit(-1);
    }

    char *ip = argv[1];
    uint16_t port = atoi(argv[2]);

    EventLoop loop;
    InetAddress addr(ip, port);
    ChatServer server(&loop, addr, "ChatServer");

    server.start();
    loop.loop();

    return 0;
}