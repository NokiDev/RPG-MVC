cmake_minimum_required(VERSION 3.3)

set(PROJECT "RPG-MVC")

project(${PROJECT} CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_BUILD_TYPE Debug) #If you have problems check if you have SFML debug libraries or release libraries
set(CMAKE_MODULE_PATH "$ENV{SFML_ROOT}/cmake/Modules")
find_package(SFML 2.3 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR} ${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.hpp)
foreach(file_paths ${HEADERS})
    GET_FILENAME_COMPONENT(dir_path ${file_paths} PATH)
    SET(dir_list ${dir_list} ${dir_path})
endforeach()
if(dir_list)
    LIST(REMOVE_DUPLICATES dir_list)
endif()
include_directories(${dir_list})

add_executable(${PROJECT} main.cpp ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT} ${SFML_LIBRARIES})