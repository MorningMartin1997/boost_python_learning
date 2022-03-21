set(LIBBOOST_PREFIX "${CMAKE_BINARY_DIR}/boost-prefix")

ExternalProject_Add(libboost
        URL https://boostorg.jfrog.io/artifactory/main/release/1.77.0/source/boost_1_77_0.tar.bz2
        PREFIX "${LIBBOOST_PREFIX}"
        CONFIGURE_COMMAND ${LIBBOOST_PREFIX}/src/libboost/bootstrap.sh --with-libraries=python --prefix=${LIBBOOST_PREFIX}
        BUILD_COMMAND ""
        BINARY_DIR "${LIBBOOST_PREFIX}/src/libboost"
        INSTALL_COMMAND ${LIBBOOST_PREFIX}/src/libboost/b2 install
        )

add_library(extern_boost_python SHARED IMPORTED)
set_target_properties(extern_boost_python PROPERTIES
        IMPORTED_LOCATION ${LIBBOOST_PREFIX}/lib/libboost_python38.so)
add_dependencies(extern_boost_python libboost)

include_directories(BEFORE SYSTEM ${LIBBOOST_PREFIX}/include)