# CPPLearning
 CPP Learning docs and code


GCC 编译 需要安装g++

gcc -o main main.cpp -lstdc++ -pthread
然后执行./main 就可以
--------------------------------------------------------------
cmake :undefined reference to 'pthread_create',当CMake需要pthread库问题

cmakelist中添加
find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
  set_property(TARGET my_app PROPERTY COMPILE_OPTIONS "-pthread")
  set_property(TARGET my_app PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(my_app "${CMAKE_THREAD_LIBS_INIT}")
endif()
然后就出现以下问题：

/usr/share/cmake-3.10/Modules/FindThreads.cmake:54: error: FindThreads only works if either C or CXX language is enabled CMakeLists.txt:3 (find_package)


出现以上两个问题可以用以下方式设置

CMakeLists.txt
--------------------------------------------------------------
cmake_minimum_required(VERSION 2.8)

project(CPPLearningCode)
add_executable(${PROJECT_NAME} "main.cpp")


TARGET_LINK_LIBRARIES( ${PROJECT_NAME}
pthread
)
--------------------------------------------------------------

