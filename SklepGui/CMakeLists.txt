cmake_minimum_required(VERSION 3.10)

# nazwa projektu
project(source_file_analyser)

SET(BUILD_GUI 1) # graficzny interfejs uzytkownika


# dodanie opcji graficznych zwiazanych z Qt

    SET(CMAKE_PREFIX_PATH "E:/Qt/5.9.9/msvc2017_64/lib/cmake/Qt5")

    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_AUTOUIC ON)


# utworzenie listy plikow kompilowanych w zaleznosci od typu projektu

    file(GLOB_RECURSE all_SRC "Main.cpp" "core/*.cpp" "gui/*.cpp" "gui/ui/*.ui")


# dodanie plikow wykonywalnych
add_executable(source_file_analyser ${all_SRC} )

include_directories(${PROJECT_SOURCE_DIR})

SET_PROPERTY(TARGET source_file_analyser PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
ADD_CUSTOM_TARGET(run COMMAND source_file_analyser WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/build)


# linkowanie bibliotek Qt oraz kopiowanie plikow dll
    target_link_libraries( source_file_analyser ${QT_LIBRARIES} )
    find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
    target_link_libraries(source_file_analyser Qt5::Core)
    target_link_libraries(source_file_analyser Qt5::Gui)
    target_link_libraries(source_file_analyser Qt5::Widgets)

    add_custom_command(TARGET source_file_analyser POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:source_file_analyser>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Gui> $<TARGET_FILE_DIR:source_file_analyser>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Widgets> $<TARGET_FILE_DIR:source_file_analyser>
    )


# specyfikacja standardu jezyka C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    
    FATAL_ERROR("BUILD_GUI and BUILD_TUI cannot be defined simultanously.")
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    TARGET_LINK_LIBRARIES(source_file_analyser stdc++fs)
endif()

