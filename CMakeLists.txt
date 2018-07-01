cmake_minimum_required(VERSION 3.9)
project(sauron)

set(CMAKE_CXX_STANDARD 11)

set(INCLUDE_SCREEN_CAPTURE_DIRECTORY "include/screen_capture/")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_OUTPUT_PATH bin)

# Where to find CMake modules and OpenCV
set(OpenCV_DIR "C:\\opencv-3.4.1\\mingw-build")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenCV REQUIRED)

# add libs you need
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

add_executable(
        sauron

        main.cpp

        src/screen_capture/ScreenCapture.cpp
        include/screen_capture/ScreenCapture.h
)

include_directories(
        ${INCLUDE_SCREEN_CAPTURE_DIRECTORY}
        ${OpenCV_INCLUDE_DIRS}
)

# linking
target_link_libraries(sauron ${OpenCV_LIBS})
