#ifndef SERVER_DEBUG_H
#define SERVER_DEBUG_H

#include <iostream>

#define SRV_DEBUG

#ifdef SRV_DEBUG

#define LOG(msg) std::cout << msg << std::endl

#else
#define LOG(msg)
#endif

#endif // SERVER_DEBUG_H
