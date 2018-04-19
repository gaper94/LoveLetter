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

add_library(GameCommon SHARED  GameCommon/GameDefinitions.h
                               GameCommon/GameUtils.h
                               GameCommon/GameUtils.cpp
                               GameCommon/TypesSerializers.cpp
                               GameCommon/Card.h)

add_executable(game_controller App/Application.h
                               GameController/GameController.h
                               GameController/GameController.cpp
                               GameController/Game.h
                               GameController/Game.cpp
                               GameController/main.cpp )

add_executable(game_server App/Application.h
                           GameServer/ServerDebug.h
                           GameServer/GameServer.h
                           GameServer/GameServer.cpp
                           GameServer/Game.h
                           GameServer/Game.cpp
                           GameServer/Joueur.h
                           GameServer/Joueur.cpp
                           GameServer/Bot_Random.h
                           GameServer/Bot_Random.cpp
                           GameServer/InfSup_Bot.h
                           GameServer/InfSup_Bot.cpp
                           GameServer/Terminator.h
                           GameServer/Terminator.cpp
                           GameServer/Deck.h
                           GameServer/Deck.cpp
                           GameServer/main.cpp)

target_link_libraries(game_controller Network Serialize GameCommon)
target_link_libraries(game_server Network Serialize GameCommon)
