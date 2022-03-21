PYTHON_ADD_MODULE(member member.cpp)
target_link_libraries(member
        PRIVATE extern_boost_python)
file(COPY member.py DESTINATION .)
add_test(NAME 04-Constructors COMMAND ${Python_EXECUTABLE} member.py)