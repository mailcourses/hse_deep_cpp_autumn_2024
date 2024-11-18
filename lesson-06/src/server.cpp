#include <iostream>

struct Server
{
    Server(uint16_t port) : port(port)
    {
        std::cout << "Server(uint16_t)" << std::endl;
    }

    Server(const Server&)
    {
        std::cout << "Server(const Server&)" << std::endl;
    }

    Server(Server&&)
    {
        std::cout << "Server(Server&&)" << std::endl;
    }

    Server& operator=(const Server& server)
    {
        std::cout << "operator=(const Server&)" << std::endl;
        return *this;
    }
    uint16_t port;
};

Server makeServer(uint16_t port)
{
    Server server(port);
    return server;
}

Server&& makeServerNew(uint16_t port)
{
    Server server(port);
    return std::move(server);
}

int main()
{
    Server s1 = makeServer(8080);
    Server s2 = Server(8000);
    Server s3 = makeServerNew(8080);
}
