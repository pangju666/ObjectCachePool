#ifndef REDIS_CLIENT_H
#define REDIS_CLIENT_H

#include "msgpack.h"
#include "hiredis.h"

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
    void getValue(const char* key, T value) {

    }

    template<typename T>
    void deleteValue(const char* key, T value) {

    }

private:
    redisContext* context;
};

#endif