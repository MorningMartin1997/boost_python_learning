//
// Created by Martin Zeng on 2022/3/21.
//

#include <string>
#include <sstream>

class Ctor{
public:
    explicit Ctor(std::string msg) : msg_(std::move(msg)){};

    Ctor(double x, double y){
        std::stringstream os;
        os << x << ":" << y;
        set(os.str());
    }

    std::string greet() {return msg_;}

private:

    void set(std::string msg){msg_ = msg;}
    std::string msg_;
};

#include "boost/python.hpp"

BOOST_PYTHON_MODULE(ctor){
    using namespace boost::python;

    class_<Ctor>("Ctor", init<std::string>())
            .def(init<double, double>())
            .def("greet", &Ctor::greet);
}