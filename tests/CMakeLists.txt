include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.1
)
FetchContent_MakeAvailable(Catch2)

add_executable(eqp_tests
    test_vector.cpp
)

target_link_libraries(eqp_tests PRIVATE
    eqp_core
    Catch2::Catch2WithMain
)

add_test(NAME eqp_tests COMMAND eqp_tests)