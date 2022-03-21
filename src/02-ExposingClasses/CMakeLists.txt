PYTHON_ADD_MODULE(classes classes.cpp)
target_link_libraries(classes
        PRIVATE extern_boost_python)
file(COPY classes.py DESTINATION .)
add_test(NAME 02-ExposingClasses COMMAND ${Python_EXECUTABLE} classes.py)