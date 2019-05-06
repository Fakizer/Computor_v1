#include "Parser.hpp"

Parser::Parser(const char * av, Equation & e) : str(av), equation(e) {
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);

    std::cout << str << std::endl << std::endl;

    std::string::iterator last = str.begin();
    for (std::string::iterator i = str.begin(); i != str.end(); i++) {
        if (*last == '=') {
            equation.createVar(std::string(last, i));
            last++;
        }
        if (*i == '+' || *i == '-' || *i == '=') {
            if (i - last == 0)
                continue ;
            equation.createVar(std::string(last, i));
            last = i;
        } else if (i + 1 == str.end()) {
            if (*last == '=')
                last++;
            equation.createVar(std::string(last, str.end()));
        }
    }

    if (equation.getVarMdegree() > 3) {
        printf("%s\n", "max avaleble degree is 3!!");
    }

    for (auto v : equation.variebles) {
        // std::cout << v.coefficient << " | " << v.degree << std::endl;
    }
}


Parser::~Parser() {}
