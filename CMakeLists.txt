CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
FIND_PACKAGE(OpenCV REQUIRED)

INCLUDE_DIRECTORIES(${OPENCV_INCLUDE_DIR})
include_directories(include)

SET(INCLUDE_LIBRARIES ${OpenCV_LIBS})

add_subdirectory(src)

ADD_EXECUTABLE(stresstest src/finder.cpp src/trainingdata.cpp src/trainloader.cpp src/neuralnetwork.cpp src/metriccontainer.cpp main.cpp)
add_executable(stressgen src/stressgen.cpp)
target_link_libraries(stresstest ${INCLUDE_LIBRARIES})
target_link_libraries(stressgen ${INCLUDE_LIBRARIES})
