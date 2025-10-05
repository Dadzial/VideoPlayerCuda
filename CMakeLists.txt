cmake_minimum_required(VERSION 3.21)
project(VideoPlayerCuda LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CUDA_ARCHITECTURES 86)

if(UNIX)
    set(CMAKE_PREFIX_PATH "/home/damiand/Qt/6.9.1/gcc_64/lib/cmake")
elseif(WIN32)
    set(CMAKE_PREFIX_PATH "C:/Qt/6.9.1/msvc2019_64/lib/cmake")
endif()

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
find_package(CUDAToolkit REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(VideoPlayerCuda main.cpp cuda/test.cu )

set_source_files_properties(cuda/test.cu PROPERTIES LANGUAGE CUDA)

target_link_libraries(VideoPlayerCuda PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        CUDA::cudart
        ${OpenCV_LIBS}
)

set_target_properties(VideoPlayerCuda PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON
)
