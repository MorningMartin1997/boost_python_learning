import inheritance

b = inheritance.Base()
d = inheritance.Derived()

inheritance.fb(b)
inheritance.fb(d)

# it is not possible to run following command
# inheritance.fd(b)

inheritance.fd(d)

x = inheritance.factory()
inheritance.fb(x)
