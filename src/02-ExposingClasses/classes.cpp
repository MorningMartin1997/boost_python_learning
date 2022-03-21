//
// Created by Martin Zeng on 2022/3/21.
//

#include "boost/python.hpp"
#include "boost/python/list.hpp"
#include "boost/python/extract.hpp"
#include <string>
#include <sstream>
#include <vector>

class World{
public:
    void set(std::string msg){
        msg_ = std::move(msg);
    }

    void many(boost::python::list msgs){
        long l = len(msgs);
        std::stringstream ss;
        for (long i = 0; i<l; ++i) {
            if (i>0) ss << ", ";
            std::string s = boost::python::extract<std::string>(msgs[i]);
            ss << s;
        }
        msg_ = ss.str();
    };

    std::string greet() {return msg_;}

private:
    std::string msg_;
};

BOOST_PYTHON_MODULE(classes){
    using namespace boost::python;
    class_<World>("World")
            .def("greet", &World::greet)
            .def("set", &World::set)
            .def("many", &World::many);
}