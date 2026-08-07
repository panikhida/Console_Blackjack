cmake_minimum_required(VERSION 4.2)
project(Console_Blackjack)

set(CMAKE_CXX_STANDARD 23)

add_executable(Console_Blackjack main.cpp
        Card.h
        deck.cpp
        game.cpp
        includes.h
        Card.cpp
        deck.h
        game.h
        btui/src/BTUI.cpp
        btui/includes/BTUI.h
        btui/includes/formats.h
        btui/src/formats.cpp
        btui/src/converter.cpp
        btui/includes/converter.h
        btui/includes/paints.h
        btui/src/paints.cpp)
