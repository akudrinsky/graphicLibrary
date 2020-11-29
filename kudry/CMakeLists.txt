cmake_minimum_required(VERSION 3.15)

set(CMAKE_BUILD_TYPE "Debug")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -DDEBUG -Wformat=2 -Wfloat-equal -fsanitize=address -fsanitize=undefined -fstack-protector")
#set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("\nKUDRY: Debug mode\n")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG -Wall -Wextra -Werror")
endif()

add_library(kudry  
    STATIC 
    ./window/RectangleButton/RectangleButton.cpp
    ./window/Instrument/Instrument.cpp
    ./window/Instrument/Canvas.cpp
    ./window/RectangleWindow/RectangleWindow.cpp
    ./window/SystemWindow/SystemWindow.cpp
    ./window/Components/Shapes/Picture.cpp
    ./window/Components/Shapes/Rectangle.cpp
    ./window/Components/Clickable.cpp
    ./window/AbstractWindow.cpp
    ./window/Text/Text.cpp
    ./window/Text/Font.cpp
    ./window/Scrollbar/Scrollbar.cpp
    ./window/Scrollbar/ScrollableText.cpp
    ./Application/SubscriptionManager/SubscriptionManager.cpp
    ./Application/EventTypes/UserEvent.cpp
    ./Application/Event.cpp
    ./engine/SFML/engineSFML.cpp
    ./engine/OpenGL/engineOpenGL.cpp
    ./simpleGraphics/color/color.cpp
)

find_package(SFML REQUIRED system window graphics)

target_include_directories(kudry PUBLIC ${SFML_INCLUDE_DIR})

target_link_libraries(
    kudry 
    PUBLIC sfml-system sfml-window sfml-graphics
)
