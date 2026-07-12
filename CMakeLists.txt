cmake_minimum_required(VERSION 3.20)

project(BlackjackSolver)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    blackjack_solver

    src/main.cpp

    src/cards/card.hpp
    src/cards/hand.hpp
    src/cards/shoe.hpp

    src/rules/rules.hpp
    src/rules/rules.cpp

    src/engine/dealer.hpp
    src/engine/dealer.cpp

    src/engine/ev.hpp
    src/engine/ev.cpp

    src/engine/dealer_result.hpp
    src/engine/dealer_solver.hpp
    src/engine/dealer_solver.cpp
)
