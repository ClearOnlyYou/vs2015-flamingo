/**
 * TcpSession.h
 * zhangyl 2017.03.09
 **/

#pragma once

#include <memory>
#include "../net/tcpconnection.h"

using namespace net;

//Ϊ����ҵ�����߼��ֿ���ʵ��Ӧ������һ������̳���TcpSession����TcpSession��ֻ���߼����룬��������ҵ�����
class TcpSession
{
public:
    TcpSession(const std::shared_ptr<TcpConnection>& conn);
    ~TcpSession();

    TcpSession(const TcpSession& rhs) = delete;
    TcpSession& operator =(const TcpSession& rhs) = delete;

    std::shared_ptr<TcpConnection> GetConnectionPtr()
    {
        return conn_;
    }

    void Send(int32_t cmd, int32_t seq, const std::string& data);
    void Send(int32_t cmd, int32_t seq, const char* data, int32_t dataLength);
    void Send(const std::string& p);
    void Send(const char* p, int32_t length);

private:
    void SendPackage(const char* p, int32_t length);

protected:
    std::shared_ptr<TcpConnection>    conn_;
};
