cmake_minimum_required(VERSION 3.29)
project(helloworld)

set(CMAKE_CXX_STANDARD 20)

find_package(LLVM 19 REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS} SYSTEM)
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

add_executable(gen gen.cpp)

llvm_map_components_to_libnames(llvm_libs
        ${LLVM_TARGETS_TO_BUILD}
        core
        # Add other LLVM library components here
        )
target_link_libraries(gen ${llvm_libs})
