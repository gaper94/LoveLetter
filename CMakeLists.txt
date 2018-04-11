project(LoveLetter)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 14)

add_library(Network SHARED  Network/IConnection.h
                            Network/IConnection.cpp
                            Network/NetworkDefines.h
                            Network/Network.h
                            Network/Network.cpp
                            Network/Network.cpp
                            Network/TCPClientConnection.h
                            Network/TCPClientConnection.cpp
                            Network/TCPServerConnection.h
                            Network/TCPServerConnection.cpp)

add_library(Serialize SHARED    Msg/Deserializer.h
                                Msg/Deserializer.cpp
                                Msg/Serializer.h
                                Msg/Serializer.cpp
                                Msg/GenericMsg.h
                                Msg/GenericMsg.hpp
                                Msg/GenericMsg.cpp
                                Msg/TestStruct.h
                                Msg/TypesSerializer.cpp
                                Msg/TypesTools.h
                                Msg/TypesTools.cpp)

add_executable(game_controller App/Application.h
                               GameController/GameController.h
                               GameController/GameController.cpp
                               GameController/main.cpp)

add_executable(view App/Application.h
                              View/View.h
                              View/View.cpp
                              View/main.cpp)

add_executable(game_server App/Application.h
                           GameServer/GameServer.h
                           GameServer/GameServer.cpp
                           GameServer/main.cpp)

target_link_libraries(game_controller Network Serialize)
target_link_libraries(view Network Serialize)
target_link_libraries(game_server Network Serialize)
