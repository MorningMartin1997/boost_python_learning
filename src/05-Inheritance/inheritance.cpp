//
// Created by Martin Zeng on 2022/3/21.
//

#include <iostream>
#include <string>

class Base{
public:
    [[nodiscard]] virtual std::string name() const {return "Base";}
    virtual ~Base() = default;
};

class Derived : public Base{
public:
    [[nodiscard]] std::string name() const override {return "Derived";}
};

void fb(Base *b){
    std::cout << b->name() << std::endl;
}

void fd(Derived *d){
    std::cout << d->name() << std::endl;
}

Base* factory(){
    return new Derived;
}

#include "boost/python.hpp"

BOOST_PYTHON_MODULE(inheritance){
    using namespace boost::python;

    class_<Base, boost::noncopyable>("Base")
            .def("name", &Base::name);

    class_<Derived, bases<Base>>("Derived");

    def("fb", fb);
    def("fd", fd);
    def("factory", factory, return_value_policy<manage_new_object>());
}


