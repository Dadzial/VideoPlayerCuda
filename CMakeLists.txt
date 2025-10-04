cmake_minimum_required(VERSION 3.31)
project(VideoPlayerCuda LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CUDA_ARCHITECTURES 75 86)

if(WIN32)
    # this path is example, you need to change it to your Qt path
    set(CMAKE_PREFIX_PATH "C:/Qt/6.9.1/msvc2019_64/lib/cmake")
elseif(UNIX)
    set(CMAKE_PREFIX_PATH "/home/damiand/Qt/6.9.1/gcc_64/lib/cmake")
endif()

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
find_package(CUDAToolkit REQUIRED)

add_executable(VideoPlayerCuda main.cpp
)

target_link_libraries(VideoPlayerCuda
        Qt::Core
        Qt::Gui
        Qt::Widgets
        CUDA::cudart
)

set_target_properties(VideoPlayerCuda PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON
)
