/* this is an echo server that properly passes every supported Autobahn test */

#include <iostream>
#include <string>
using namespace std;

#include <uWS.h>
using namespace uWS;

int main()
{
    try {
        SSLContext context("/tmp/cert.pem", "/tmp/key.pem");
        Server server(3000, true, 0, 1048576, context);
        server.onConnection([](WebSocket socket) {

        });

        server.onMessage([](WebSocket socket, char *message, size_t length, OpCode opCode) {
            socket.send(message, length, opCode);
        });

        server.onDisconnection([](WebSocket socket, int code, char *message, size_t length) {

        });

        server.run();
    } catch (...) {
        cout << "ERR_LISTEN" << endl;
    }

    return 0;
}
