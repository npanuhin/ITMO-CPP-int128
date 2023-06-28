project(int128)

add_library(${PROJECT_NAME}
    include/int128/Int128.hpp  src/Int128.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

add_library(int128::int128 ALIAS ${PROJECT_NAME})

find_package(Catch2 3 REQUIRED)
add_executable(tests tests/test_int128.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain int128::int128)

if(COMPILE_OPTS)
    target_compile_options(${PROJECT_NAME} PUBLIC ${COMPILE_OPTS})
    target_link_options(${PROJECT_NAME} PUBLIC ${LINK_OPTS})

    target_compile_options(tests PUBLIC ${COMPILE_OPTS})
    target_link_options(tests PUBLIC ${LINK_OPTS})
endif()
