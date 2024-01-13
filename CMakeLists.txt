cmake_minimum_required(VERSION 3.27)
project(BankApp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BankApp
        main.cpp
        Date.cpp
        Date.h
        Person.cpp
        Person.h
        Password.cpp
        Password.h
        User.cpp
        User.h
        Database.cpp
        Database.h
        Interface.cpp
        Interface.h
        MainInterface.h
        MainInterface.cpp
        AdminInterface.cpp
        LoginInterface.h
        LoginInterface.cpp
)
