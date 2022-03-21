PYTHON_ADD_MODULE(inheritance inheritance.cpp)
target_link_libraries(inheritance
        PRIVATE extern_boost_python)
file(COPY inheritance.py DESTINATION .)
add_test(NAME 05-Inheritance COMMAND ${Python_EXECUTABLE} inheritance.py)