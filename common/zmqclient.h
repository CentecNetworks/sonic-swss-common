#pragma once

#include <memory>
#include <vector>
#include <queue>
#include <thread> 
#include <mutex> 
#include "zmqserver.h"

namespace swss {

class ZmqClient
{
public:
    ZmqClient(const std::string& endpoint);
    ~ZmqClient();

    bool isConnected();

    void connect();

    void sendMsg(const std::string& key,
                 const std::vector<swss::FieldValueTuple>& values,
                 const std::string& command,
                 const std::string& dbName,
                 const std::string& tableName,
                 std::vector<char>& sendbuffer);
private:
    void initialize(const std::string& endpoint);


    std::string m_endpoint;

    void* m_context;

    void* m_socket;

    bool m_connected;

    std::mutex m_socketMutex;
};

}
