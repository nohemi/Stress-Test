CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
FIND_PACKAGE(OpenCV REQUIRED)

INCLUDE_DIRECTORIES(${OPENCV_INCLUDE_DIR})
include_directories(include)

SET(INCLUDE_LIBRARIES ${OpenCV_LIBS})

add_subdirectory(src)

ADD_EXECUTABLE(stresstest src/metriccontainer.cpp main.cpp)
target_link_libraries(stresstest ${INCLUDE_LIBRARIES})