#include "network/Server.hpp"

int main (int argc, char *argv[]) {
    Server::getServer(9010).run();
    return 0;    
}