cmake_minimum_required(VERSION 3.12)

project(ConsolePicture)

find_package(OpenCV 4 REQUIRED)

aux_source_directory(src sc_project_source)
add_executable(ConsolePicture ${sc_project_source})
target_include_directories(ConsolePicture BEFORE PUBLIC include)
target_link_libraries(ConsolePicture PUBLIC ${OpenCV_LIBS})
set_target_properties(ConsolePicture PROPERTIES CXX_STANDARD 20)

