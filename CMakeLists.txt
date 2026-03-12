cmake_minimum_required(VERSION 3.16)
project(Helpdesk VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(Helpdesk
    main.cpp
    mainwindow.cpp mainwindow.h mainwindow.ui
    ticketdialog.cpp ticketdialog.h ticketdialog.ui
    tickettablemodel.cpp tickettablemodel.h
    tickettablemodel.h tickettablemodel.cpp
)

target_link_libraries(Helpdesk PRIVATE Qt6::Widgets)
