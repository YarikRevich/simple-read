if(BUILD_TESTING)
    if (WIN32) 
        include_directories(${CMAKE_SOURCE_DIR}/include/windows)
        link_directories(${CMAKE_SOURCE_DIR}/lib/windows)
    endif()

    if (APPLE)
        include_directories(${CMAKE_SOURCE_DIR}/include/darwin)
        link_directories(${CMAKE_SOURCE_DIR}/lib/darwin)
    endif()

    if (UNIX AND NOT APPLE)
        include_directories(${CMAKE_SOURCE_DIR}/include/linux)
        link_directories(${CMAKE_SOURCE_DIR}/lib/linux)
    endif()

    # add_executable(test1 buf_test.cpp)
    
    # target_link_libraries(
    #     test1 

	# 	${CMAKE_SOURCE_DIR}/lib/gtest/libgtest_main.a
	# 	${CMAKE_SOURCE_DIR}/lib/gtest/libgtest.a
    # )

    # add_test(NAME buf_test COMMAND test1)
endif()
