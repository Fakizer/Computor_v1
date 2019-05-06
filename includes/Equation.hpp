#ifndef EQUATION_HPP
#define EQUATION_HPP

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "Variable.hpp"

class Equation
{
private:
    /* data */
public:
    
    int num_answer;
    std::vector<double> real;
    std::vector<double> imagine;

    std::vector<Variable> variebles;
    static bool     is;

    void         createVar(std::string str);
    void         removesDooble();
    Variable     getVarieble(int degree);
    int          getVarMdegree();

    void        printallvar();
    void        printAnswer();

    void        resolver();
    void        resolveDegree1();


    template<typename _Tp>
    struct greater
    {
      _GLIBCXX14_CONSTEXPR
      bool
      operator()(const Variable& __x, const Variable& __y) const
      { return __x.degree > __y.degree; }
    };

    Equation();
    ~Equation();
};




#endif