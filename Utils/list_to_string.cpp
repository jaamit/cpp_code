/*
* Convert a vector of strings to a single string
*/

#include <boost/algorithm/string/join.hpp>
#include <vector>
#include <iostream>

int main()
{
    std::vector<std::string> list;
    list.push_back("Hello");
    list.push_back("There!");

    std::string joined = boost::algorithm::join(list, ", ");
    std::cout << joined << std::endl;
}

// Output - "Hello, There!"
