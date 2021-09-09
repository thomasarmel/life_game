cmake_minimum_required(VERSION 3.20)
project(life_game)

set(CMAKE_CXX_STANDARD 14)

include_directories("D:\\lib\\opencv\\build\\install\\include")
set(OpenCV_DIR "D:\\lib\\opencv\\build\\install")

FIND_PACKAGE( OpenCV REQUIRED core highgui imgproc)
set(OpenCV_LIBS opencv_core opencv_highgui opencv_imgproc)
set(OpenCV_FOUND TRUE)

add_executable(life_game main.cpp Board.cpp Board.h BoardDisplayer.cpp BoardDisplayer.h BoardObserver.h ObservableBoard.cpp ObservableBoard.h)

target_link_libraries(life_game ${OpenCV_LIBS})