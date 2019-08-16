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

    void Send(int32_t cmd, int32_t seq, int32_t errorcode, const std::string& filemd5, int64_t offset, int64_t filesize, const std::string& filedata);

private:
    //֧�ִ��ļ�����int64_t���洢�������ǵ�����һ���ļ��ϴ��������߼�
    void SendPackage(const char* body, int64_t bodylength);

protected:
    std::shared_ptr<TcpConnection>    conn_;
};
