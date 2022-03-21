//
// Created by Martin Zeng on 2022/3/21.
//

#include <boost/python.hpp>

const char* greet(){
    return "hello world!";
}

BOOST_PYTHON_MODULE(hello)
{
        using namespace boost::python;
        def("greet", greet);
}