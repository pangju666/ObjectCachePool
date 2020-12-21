#include <iostream>  
#include <string>  
#include <vector>  
#include <functional>
#include <winsock.h>
#include <unordered_map>

#include "msgpack.h"
#include "hiredis.h"

using namespace std;

class SerializableObject {
    virtual void setDataMap(unordered_map<string, void*> dataMap) = 0;

    unordered_map<string, void*> getDataMap() const { return dataMap; }

    void serializableObject() {

    }

private:
    unordered_map<string, void*> dataMap;
};

class RedisClient {
public:
    RedisClient(const char* ip = "127.0.0.1", int port = 6379) {
        context = redisConnect(ip, port);
    }

    RedisClient(int seconds, int millseconds, const char* ip = "127.0.0.1", int port = 6379) {
        timeval tv = { seconds, millseconds };
        context = redisConnectWithTimeout(ip, port, tv);
    }

    RedisClient(const redisOptions* options) {
        context = redisConnectWithOptions(options);
    }

    ~RedisClient() {
        if (context != nullptr) {
            redisFree(context);
        }
    }

    bool isConnect() {
        return context != nullptr;
    }

    bool isError() {
        return context->err != 0;
    }

    bool getError() {
        return context->errstr;
    }

    template<typename T>
    void putValue(const char* key, T value) {
        
    }

    template<typename T>
    void putObject(const char* key, T value) {

    }

    template<typename T>
    void getValue(const char* key, T value) {

    }

    template<typename T>
    void getObject(const char* key, T value) {

    }

    template<typename T>
    void deleteValue(const char* key, T value) {

    }

    template<typename T>
    void deleteObject(const char* key, T value) {

    }

private:
    redisContext* context;
};

int main(int argc, char** argv)
{
    redisContext* context = redisConnect("127.0.0.1", 6379);
    if (context == nullptr || context->err)
    {
        if (context)
        {
            cout << context->errstr;
        } 
        else
        {
            cout << "redis 连接错误";
        }
    }
    else {
        cout << "连接成功";
        redisCommand(context, "set test 1");
    }
    return 0;
}