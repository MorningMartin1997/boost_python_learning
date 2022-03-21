PYTHON_ADD_MODULE(ctor ctor.cpp)
target_link_libraries(ctor
        PRIVATE extern_boost_python)
file(COPY ctor.py DESTINATION .)
add_test(NAME 02-Constructors COMMAND ${Python_EXECUTABLE} ctor.py)