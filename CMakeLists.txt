cmake_minimum_required(VERSION 3.0.0)
project(kvasir-jni VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(
	./native
)
link_directories(
	./native
)
add_library(
	kvasir-jni SHARED
	./native/kvasir-jni.cpp
)
target_link_libraries(
	kvasir-jni
	kvasir-engine
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
