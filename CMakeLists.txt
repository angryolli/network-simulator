cmake_minimum_required(VERSION 3.20)

project(NetworkSimulator 
    VERSION 1.0.0
    DESCRIPTION "Discrete-event Network Simulator"
    LANGUAGES CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find Qt6 (preferred) or fall back to Qt5
find_package(Qt6 QUIET COMPONENTS Core Widgets Gui)
if(Qt6_FOUND)
    set(QT_VERSION_MAJOR 6)
    message(STATUS "Using Qt6")
else()
    find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)
    set(QT_VERSION_MAJOR 5)
    message(STATUS "Using Qt5")
endif()

# Enable Qt MOC, UIC, and RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Include directories
include_directories(src/include)

# Header files for MOC processing
set(GUI_HEADERS
    src/gui/main_window.hpp
    src/gui/node_item.hpp
    src/gui/link_item.hpp
)

# Source files
set(CORE_SOURCES
    src/node.cpp
    src/link.cpp
    src/packet.cpp
    src/interface.cpp
    src/event_queue.cpp
    src/network_simulator.cpp
    src/traffic_generator.cpp
    src/stats.cpp
    src/config_manager.cpp
    src/limited_queue.cpp
)

set(GUI_SOURCES
    src/gui/main_window.cpp
    src/gui/node_item.cpp
    src/gui/link_item.cpp
)

# Create executable
add_executable(network_simulator
    main.cpp
    ${CORE_SOURCES}
    ${GUI_SOURCES}
    ${GUI_HEADERS}
)

# Link Qt libraries
if(QT_VERSION_MAJOR EQUAL 6)
    target_link_libraries(network_simulator
        Qt6::Core
        Qt6::Widgets
        Qt6::Gui
    )
else()
    target_link_libraries(network_simulator
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
    )
endif()

# Compiler-specific options
if(MSVC)
    target_compile_options(network_simulator PRIVATE /W4)
else()
    target_compile_options(network_simulator PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Debug/Release configurations
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(network_simulator PRIVATE DEBUG_BUILD)
endif()

# Installation
install(TARGETS network_simulator DESTINATION bin)