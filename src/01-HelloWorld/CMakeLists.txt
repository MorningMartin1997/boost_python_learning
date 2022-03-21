# set this variable to build static
# fix: fail to statically link the c++ built python module
# set(PYTHON_MODULE_hello_BUILD_SHARED FALSE)

PYTHON_ADD_MODULE(hello hello.cpp)
target_link_libraries(hello
        PRIVATE extern_boost_python)
file(COPY hello.py DESTINATION .)
add_test(NAME 01-HelloWorld COMMAND ${Python_EXECUTABLE} hello.py)