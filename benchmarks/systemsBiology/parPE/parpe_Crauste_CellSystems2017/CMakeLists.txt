cmake_minimum_required(VERSION 3.15)
cmake_policy(VERSION 3.15...3.30)

set(default_build_type "RelWithDebInfo")

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

set(MODEL_NAME Boehm_JProteomeRes2014)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# call project to select language and required by some modules
project(${MODEL_NAME}) # for IDE

find_package(ParPE REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -Wall -Wno-unused-function -fopenmp")

execute_process(
    COMMAND sh -c "cd ${CMAKE_CURRENT_SOURCE_DIR} && git describe --abbrev=4 --dirty=-dirty --always --tags  | tr -d '\n'"
    OUTPUT_VARIABLE GIT_VERSION
)
message(STATUS "Building version ${GIT_VERSION}")
add_definitions(-DGIT_VERSION="${GIT_VERSION}")

include_directories(${ParPE_INCLUDE_DIRS})


################################################
# AMICI model
################################################

add_subdirectory(model)

project(${MODEL_NAME}) # for IDE, will use last project as label
