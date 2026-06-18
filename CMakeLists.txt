cmake_minimum_required(VERSION 4.2)
project(Console_Blackjack)

set(CMAKE_CXX_STANDARD 23)

add_executable(Console_Blackjack main.cpp
        Card.h
        deck.cpp
        player.cpp
        game.cpp
        includes.h
        Card.cpp
        deck.h)
