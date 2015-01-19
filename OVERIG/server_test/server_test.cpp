#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <pthread.h>

using namespace std;

// some server constants
const char *PORT = "12345";
const int MAXLEN = 1024; // the maximum length of a message
const int MAXFD = 7; // maximum number of clients
const int BACKLOG = 5; // number of connections that can wait in queue before they be accepted

int server_start_listen()
{
    struct addrinfo hostinfo, *res;
    
    int sock_fd;
    
    int server_fd;
    int ret;
    int yes = 1;
    
    // first, load up address structs with getaddrinfo()
    memset(&hostinfo, 0, sizeof(hostinfo));
    
    hostinfo.ai_family = AF_UNSPEC; // use IPv4 or IPv6, whichever
    hostinfo.ai_socktype = SOCK_STREAM;
    hostinfo.ai_flags = AI_PASSIVE; // fill in my IP for me
    
    getaddrinfo(NULL, PORT, &hostinfo, &res);
    
    server_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    ret = setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
    
    if(ret != 0)
    {
        cout << "error: " << strerror(errno) << endl;
        return -1;
    }
    ret = listen(server_fd, BACKLOG);
    
    return server_fd;
}

void mainloop(int server_fd)
{
    // this loop will wait for a client to connect. When the client connects, it creates a new thread for the client and starts waiting again for a new client.
    pthread_t threads[MAXFD];
    
    // TODO vanaf hier
}

int main()
{
    cout << "Server started" << endl;
    
    // start the main and make the server listen on port 12345
    // server_start_listen(12345) will return the server's file descriptor
    int server_fd = server_start_listen();
    if(server_fd == -1)
    {
        cout << "An error has occured." << endl;
        return 1;
    }
    
    mainloop(server_fd);
    
    return 0;
}