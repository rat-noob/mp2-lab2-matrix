set(target sample)

file(GLOB srcs "*.cpp")

add_executable(${target} ${srcs})

#убрал из линклибрарис ${MP2_LIBRARY}

target_link_libraries(${target} )
target_include_directories(${target} PUBLIC ${MP2_INCLUDE})