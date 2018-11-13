message(STATUS "Load OpenMPI Cmake")
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
        set(MPI_C_LIBRARIES
                /usr/local/lib/libmpi.so
                )
        set(MPI_CXX_LIBRARIES
                /usr/local/lib/libmpi.so
                )
        set(MPI_C_INCLUDE_PATH //usr/local/include/openmpi)
        set(MPI_CXX_INCLUDE_PATH //usr/local/include/openmpi)
    find_package(MPI REQUIRED)
    if ( MPI_FOUND )
		include_directories( ${MPI_INCLUDE_PATH} )
	endif( MPI_FOUND )
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
endif ()
