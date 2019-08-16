/** 
 *  �ļ��������������࣬FileServer.h
 *  zhangyl 2017.03.17
 **/
#pragma once
#include <memory>
#include <list>
#include <map>
#include <mutex>
#include "../net/tcpserver.h"
#include "../net/eventloop.h"
#include "FileSession.h"

using namespace net;

struct StoredUserInfo
{
    int32_t         userid;
    std::string     username;
    std::string     password;
    std::string     nickname;
};

class FileServer final
{
public:
    FileServer() = default;
    ~FileServer() = default;

    FileServer(const FileServer& rhs) = delete;
    FileServer& operator =(const FileServer& rhs) = delete;

    bool Init(const char* ip, short port, EventLoop* loop, const char* fileBaseDir = "filecache/");

private:
    //�����ӵ������û����ӶϿ���������Ҫͨ��conn->connected()���жϣ�һ��ֻ����loop�������
    void OnConnection(std::shared_ptr<TcpConnection> conn);  
    //���ӶϿ�
    void OnClose(const std::shared_ptr<TcpConnection>& conn);
   

private:
    std::shared_ptr<TcpServer>                     m_server;
    std::list<std::shared_ptr<FileSession>>        m_sessions;
    std::mutex                                     m_sessionMutex;      //���߳�֮�䱣��m_sessions
    int                                            m_baseUserId{};
    std::mutex                                     m_idMutex;           //���߳�֮�䱣��m_baseUserId
    std::string                                    m_strFileBaseDir;    //�ļ�Ŀ¼
};