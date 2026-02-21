cmake_minimum_required(VERSION 3.10)
project(PhotoStudio)

set(CMAKE_CXX_STANDARD 14)

add_executable(PhotoStudio
        src/Client.cpp
        src/Consumables.cpp
        src/FilmDeveloping.cpp
        src/Order.cpp
        src/Photographer.cpp
        src/PhotographerReport.cpp
        src/PhotoPrinting.cpp
        src/Receptionist.cpp
        src/ReceptionistReport.cpp
        src/Report.cpp
        src/StudioAdministrator.cpp
        src/main.cpp
)

target_include_directories(PhotoStudio PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")