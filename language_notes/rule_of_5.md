## C++ Rule of 5

Each class should explicitly define exactly one of the following set of special member functions:

* None
* Destructor, copy constructor, copy assignment operator
In addition, each class that explicitly defines a destructor may explicitly define a move constructor and/or a move assignment operator.

Usually, one of the following sets of special member functions is sensible:

* None (for many simple classes where the implicitly generated special member functions are correct and fast)
* Destructor, copy constructor, copy assignment operator (in this case the class will not be movable)
* Destructor, move constructor, move assignment operator (in this case the class will not be copyable, useful for resource-managing classes where the underlying resource is not copyable)
* Destructor, copy constructor, copy assignment operator, move constructor, move assignment operator





[1] https://stackoverflow.com/questions/4782757/rule-of-three-becomes-rule-of-five-with-c11
