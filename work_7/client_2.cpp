#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using namespace boost::asio::ip;


std::string read_data(tcp::socket &socket) {
    boost::asio::streambuf buf;
    read_until(socket, buf, "\n");
    std::string data = buffer_cast<const char *>(buf.data());
    return data;
}

void send_data(tcp::socket &socket, const std::string &message) {
    write(socket,
          buffer(message + "\n"));
}

int main(int argc, char *argv[]) {
    io_service io_service;
    ip::tcp::socket client_socket(io_service);

    client_socket.connect(tcp::endpoint(address::from_string("127.0.0.1"), 65000u));

    std::cout << "Enter your name: ";
    std::string your_name, reply, msg;
    getline(std::cin, your_name);

    send_data(client_socket, your_name);

    while (true) {

        msg = read_data(client_socket);
        msg.pop_back();
        if (msg == "exit") {
            std::cout << "Connection terminated" << std::endl;
            break;
        }
        std::cout << "Server: " << msg << std::endl;
        std::cout << your_name << ": ";
        getline(std::cin, reply);
        send_data(client_socket, reply);

        if (reply == "exit")
            break;
    }
    return 0;
}

