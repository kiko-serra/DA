cmake_minimum_required(VERSION 3.17)
project(AD_TP_Classes)

# Build the Google tests
set(GOOGLETEST_PATH lib/googletest-master)
#add_subdirectory(${GOOGLETEST_PATH})

# Add the source files of each TP class
file(GLOB TP1_FILES CONFIGURE_DEPENDS "TP1/*.cpp")
file(GLOB TP2a_FILES CONFIGURE_DEPENDS "TP2/TP2a/*.cpp")
file(GLOB TP2b_FILES CONFIGURE_DEPENDS "TP2/TP2b/*.cpp")
file(GLOB TP3a_FILES CONFIGURE_DEPENDS "TP3/TP3a/*.cpp")
file(GLOB TP3b_FILES CONFIGURE_DEPENDS "TP3/TP3b/*.cpp")
#...

#add_executable(TP1 main.cpp ${TP1_FILES})
#add_executable(TP2a main.cpp ${TP2a_FILES})
#add_executable(TP2b main.cpp ${TP2b_FILES})
#add_executable(TP3a main.cpp ${TP3a_FILES})
#add_executable(TP3b main.cpp ${TP3b_FILES})
add_executable(TP9 TP9/ex1.cpp)

#...

#target_link_libraries(TP1 gtest_main gmock_main)
#target_link_libraries(TP2a gtest_main gmock_main)
#target_link_libraries(TP2b gtest_main gmock_main)
#target_link_libraries(TP3a gtest_main gmock_main)
#target_link_libraries(TP3b gtest_main gmock_main)

#...
