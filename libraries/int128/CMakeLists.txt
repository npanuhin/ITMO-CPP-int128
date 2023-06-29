project(Expression)

add_library(${PROJECT_NAME}
        include/int128/Int128.hpp src/Int128.cpp
        include/expression/Expression.hpp src/Expression.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

find_package(Catch2 3 REQUIRED)
add_executable(tests tests/test_int128.cpp tests/test_expression.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain ${PROJECT_NAME}::${PROJECT_NAME})

if (COMPILE_OPTS)
    target_compile_options(${PROJECT_NAME} PUBLIC ${COMPILE_OPTS})
    target_link_options(${PROJECT_NAME} PUBLIC ${LINK_OPTS})

    target_compile_options(tests PUBLIC ${COMPILE_OPTS})
    target_link_options(tests PUBLIC ${LINK_OPTS})
endif ()
