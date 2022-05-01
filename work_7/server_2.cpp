
#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using namespace boost::asio::ip;

std::string read_data(tcp::socket& socket)
{
    boost::asio::streambuf buf;
    read_until(socket, buf, "\n");
    std::string data = buffer_cast<const char*>(buf.data());
    return data;
}

void send_data(tcp::socket& socket, const std::string& message)
{
    write(socket,
          buffer(message + "\n"));
}

int main(int argc, char* argv[])
{
    io_service io_service;
    tcp::acceptor acceptor_server(io_service,tcp::endpoint(tcp::v4(), 65000u));

    tcp::socket server_socket(io_service);
    acceptor_server.accept(server_socket);

    std::string your_name = read_data(server_socket);
    your_name.pop_back();

    std::string msg, reply;
    reply = "Hello " + your_name;
    std::cout << "Server: " << reply << std::endl;
    send_data(server_socket, reply);

    while (true) {

        msg = read_data(server_socket);
        msg.pop_back();

        if (msg == "exit") {
            std::cout << your_name << " left!" << std::endl;
            break;
        }
        std::cout << your_name << ": " << msg << std::endl;

        std::cout << "Server"
             << ": ";
        getline(std::cin, reply);
        send_data(server_socket, reply);

        if (reply == "exit")
            break;
    }
    return 0;
}

