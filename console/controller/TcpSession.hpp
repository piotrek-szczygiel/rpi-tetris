#pragma once
#include "Controller.hpp"
#include <boost/asio.hpp>
#include <memory>

class TcpSession : public std::enable_shared_from_this<TcpSession> {
public:
    explicit TcpSession(boost::asio::ip::tcp::socket socket, std::shared_ptr<ControllerState> state)
        : m_socket(std::move(socket))
        , m_controller_state(std::move(state))
        , m_data {}
        , m_valid_controller { false }
    {
    }

    void start();

private:
    static const size_t MAX_LENGTH { 4 };

    boost::asio::ip::tcp::socket m_socket;
    std::array<uint8_t, MAX_LENGTH> m_data;

    std::shared_ptr<ControllerState> m_controller_state;

    bool m_valid_controller;

    void do_read();
};
