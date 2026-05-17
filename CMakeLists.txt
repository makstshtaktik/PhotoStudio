cmake_minimum_required(VERSION 3.16)
project(PhotoStudio)

# Force modern standard required by Qt 6
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Point to your MSVC 2022 Qt binaries 
set(CMAKE_PREFIX_PATH "C:/Qt/6.11.1/msvc2022_64")

# Crucial for generating metadata signals/slots
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

if(MSVC)
    add_compile_options(/Zc:__cplusplus /permissive-)
endif()

find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Cleaned, structured list. One file per line. No duplicates.
add_executable(PhotoStudio
        # Header Files (So AUTOMOC scans them correctly)
        include/mainwindow.h
        include/Transaction.h

        # Source Files
        src/main.cpp
        src/mainwindow.cpp
        src/Client.cpp
        src/Consumables.cpp
        src/FilmDeveloping.cpp
        src/Order.cpp
        src/Photographer.cpp
        src/PhotoPrinting.cpp
        src/Receptionist.cpp
        src/Report.cpp
        src/StudioAdministrator.cpp
        src/Repo.cpp
        src/Transaction.cpp
)

target_include_directories(PhotoStudio PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(PhotoStudio PRIVATE Qt6::Widgets)