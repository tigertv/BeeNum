cmake_minimum_required (VERSION 3.10)

project (Bint
	VERSION "0.1.0"
	DESCRIPTION "Bint is an arbitrary-precision arithmetic library."
	LANGUAGES CXX
)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
if(MSVC)
	#add_compile_options(/Wall)
else()
	add_compile_options(-Wall -Wextra -pedantic)
endif()

# sources
include_directories(include)
aux_source_directory(src/Bint BINT_SRC)
set(BINT_SRC ${BINT_SRC} src/Bint.cpp)
set(MATH_SRC src/Math.cpp)
add_library(shareobjects OBJECT ${BINT_SRC} ${MATH_SRC})

# libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_library(Bint SHARED ${BINT_SRC} ${MATH_SRC})
add_library(Bint_static STATIC $<TARGET_OBJECTS:shareobjects>)
set_target_properties(Bint_static PROPERTIES OUTPUT_NAME Bint)

# tests
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests")

add_executable(test-main-fast tests/main.cpp ${BINT_SRC} ${MATH_SRC})
set_target_properties(test-main-fast PROPERTIES COMPILE_FLAGS -Ofast)
add_test(NAME tst-main-fast COMMAND ./tests/test-main-fast)

aux_source_directory(tests TESTS)
foreach(tstfile ${TESTS})
	string(REGEX MATCH "\/(.*)\\.[^.]*$" dummy ${tstfile})
	add_executable(test-${CMAKE_MATCH_1} ${tstfile} $<TARGET_OBJECTS:shareobjects>)
	add_test(NAME tst-${CMAKE_MATCH_1} COMMAND ./tests/test-${CMAKE_MATCH_1})
endforeach()
