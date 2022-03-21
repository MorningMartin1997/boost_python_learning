//
// Created by Martin Zeng on 2022/3/21.
//

#include <string>

class SomeClass{
public:
    explicit SomeClass(std::string name) :
    name(std::move(name)),
    number_(0.0)
    {}

    [[nodiscard]] double getNumber() const {
        return number_;
    }

    void setNumber(double n){
        if(n > 3){
            number_ = n;
        } else {
            number_ = -1;
        }
    }

    std::string name;
private:
    double number_;
};

#include "boost/python.hpp"

BOOST_PYTHON_MODULE(member){
    using namespace boost::python;
    class_<SomeClass>("SomeClass", init<std::string>())
            .def_readwrite("name", &SomeClass::name)
            .add_property("number", &SomeClass::getNumber, &SomeClass::setNumber);
}