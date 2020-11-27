cmake_minimum_required (VERSION 3.10)

project (Bint
	VERSION "0.1.0"
	DESCRIPTION "Bint is an arbitrary-precision arithmetic library."
	LANGUAGES CXX
)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -pedantic)

set(BINT_SRC Bint.cpp Bint.h)
set(MATH_SRC Math.cpp Math.h)
add_library(shareobjects OBJECT ${BINT_SRC} ${MATH_SRC})

add_executable(main main.cpp $<TARGET_OBJECTS:shareobjects>)
add_executable(main-fast main.cpp ${BINT_SRC} ${MATH_SRC})
set_target_properties(main-fast PROPERTIES COMPILE_FLAGS -Ofast)

aux_source_directory(tests TESTS)
foreach(tstfile ${TESTS})
	string(REGEX MATCH "\/(.*)\\.[^.]*$" dummy ${tstfile})
	add_executable(test-${CMAKE_MATCH_1} ${tstfile} $<TARGET_OBJECTS:shareobjects>)
	add_test(NAME tst-${CMAKE_MATCH_1} COMMAND ./test-${CMAKE_MATCH_1})
endforeach()

