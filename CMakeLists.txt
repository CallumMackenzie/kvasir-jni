cmake_minimum_required(VERSION 3.0.0)
project(kvasir-jni VERSION 0.1.0)

if(CMAKE_VERSION VERSION_LESS "3.1")
	if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")
	endif()
else()
	set(CMAKE_CXX_STANDARD 17)
endif()

include(CTest)
enable_testing()

option(BUILD_SHARED_LIBS ON)

include_directories(
	$ENV{JAVA_HOME}/include 
	$ENV{JAVA_HOME}/include/win32 
	$ENV{JAVA_HOME}/include/linux
	./native
)

link_directories(
	./native
)
add_library(
	kvasir-jni SHARED
	./native/kvasir-jni.cpp
	./native/RenderBase.cpp
	./native/Shader.cpp
	./native/Mesh3D.cpp
)
target_link_libraries(
	kvasir-jni
	kvasir-engine
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
