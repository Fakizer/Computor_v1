#ifndef PARSER_HPP
#define PARSER_HPP

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "Equation.hpp"

class Parser
{
private:
   
public:

    Equation & equation;

    std::vector<float> x_N;
    std::vector<std::string> asd;
    std::string str;

    Parser(const char * av, Equation & e);
    ~Parser();
};




#endif
