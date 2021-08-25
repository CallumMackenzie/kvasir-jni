cmake_minimum_required(VERSION 3.0.0)
project(kvasir-jni VERSION 0.1.0)

if(CMAKE_VERSION VERSION_LESS "3.1")
	if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")
	endif()
else()
	set(CMAKE_CXX_STANDARD 17)
endif()

option(BUILD_SHARED_LIBS ON)

include_directories(
	$ENV{JAVA_HOME}/include 
	$ENV{JAVA_HOME}/include/win32 
	$ENV{JAVA_HOME}/include/linux
	./native
	./native/RenderBase
	./native/Buffer
	./native/Shader
	./native/Material
	./native/TextureImage
	./native/Texture
	./native/Mesh3D
)

link_directories(
	./native
	./native/lib
)
add_library(
	kvasir-jni SHARED
	./native/jni-aid.cpp
	./native/RenderBase/RenderBase.cpp
	./native/Texture/Texture.cpp
	./native/Material/Material.cpp
	./native/Shader/Shader.cpp
	./native/Buffer/Buffer.cpp
	./native/Mesh3D/Mesh3D.cpp
	./native/TextureImage/TextureImage.cpp
	./native/KvasirEngine/KvasirEngine.cpp
)
target_link_libraries(
	kvasir-jni
	kvasir-engine
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
