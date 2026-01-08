cmake_minimum_required(VERSION 3.16)

project(Qt_BlackJack_Ihor_test_task VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Multimedia)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    soundmanager.h
    soundmanager.cpp
    mainwindow.ui
    resources.qrc
    src/logic/Player.cpp
    src/logic/Deck.cpp
    src/logic/Hand.cpp
    src/logic/BlackJackGame.cpp
    src/ui/GameView.cpp
    src/ui/CardItem.cpp
)

qt_add_executable(Qt_BlackJack_Ihor_test_task
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

target_include_directories(Qt_BlackJack_Ihor_test_task
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/ui
)

target_link_libraries(Qt_BlackJack_Ihor_test_task
    PRIVATE Qt6::Widgets Qt6::Multimedia
)

set_target_properties(Qt_BlackJack_Ihor_test_task PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Qt_BlackJack_Ihor_test_task
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_finalize_executable(Qt_BlackJack_Ihor_test_task)
