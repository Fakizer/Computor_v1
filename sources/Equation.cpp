#include "Equation.hpp"

bool        Equation::is = true;

Equation::Equation() {}

void        Equation::createVar(std::string str) {
    std::cout << str << std::endl;

    int degree = 0;
    double coefficient = 0.0;
    bool to = is;

    if (str[0] == '=') {
        is = false;
        return ;
    }
    int  pos = str.find('X');
    if (pos > -1) {
        if (str[pos - 1] == '^')
            printf("%s\n", "Errrrrrrror");
        else if (str[pos + 1] == '^'){
            degree = std::isdigit(str[pos + 2]) ? 
                        std::atoi(str.c_str() + pos + 2) :
                        printf("%s\n", "Errrrrrrrrror");
        } else
            degree = 1;
        
        if (str[pos + 3] == '*')
            coefficient = std::atof(str.c_str() + pos + 4);
        else if (str[pos + 1] == '*')
            coefficient = std::atof(str.c_str() + pos + 2);
        else if (isdigit(str[pos + 1]))
            coefficient = std::atof(str.c_str() + pos + 1);
        else {
            coefficient = std::atof(str.c_str()) == 0 ? 1 : std::atof(str.c_str());
        }
        if (str[pos - 1] == '-')
                coefficient *= -1;
    } else {
        degree = 0;
        coefficient = std::atof(str.c_str());
    }
    // std::cout << (is ? "is: true" : "is: fasle") << std::endl;
    if (!is) {
        to = true;
        coefficient *= -1;
    }

    // std::cout << coefficient << " | " << degree << std::endl;
    // std::cout << (to ? "to: true" : "to: fasle") << std::endl;

    variebles.push_back(Variable(degree, coefficient, to));

}

void          Equation::removesDooble() {
    for (int i = 0; i < variebles.size(); i++) {
        for (int j = 0; j < variebles.size(); j++) {
            if (i == j)
                continue ;
            if (variebles[i].degree == variebles[j].degree) {
                variebles[i] += variebles[j];
                variebles.erase(variebles.begin() + j);
            }
        }
    }

    std::sort(variebles.begin(), variebles.end(), Equation::greater<Variable>());
}

void          Equation::resolver() {
    if (getVarMdegree() == 1)
        resolveDegree1();
}

void            Equation::resolveDegree1() {
    num_answer = 1;
    real.push_back((getVarieble(0).coefficient * -1) / getVarieble(1).coefficient);
}

Variable      Equation::getVarieble(int degree) {
    for (auto v : variebles) {
        if (v.degree == degree)
            return v;
    }
}

int           Equation::getVarMdegree() {
    int max = 0;
    for (auto v : variebles) {
        if (max < v.degree)
            max = v.degree;
    }
    return max;
}

void        Equation::printallvar() {
    for (auto v : variebles) {
        std::cout << v.coefficient << " | " << v.degree << std::endl;
        std::cout << (v.to_equ ? "to: true" : "to: fasle") << std::endl;
    }
    std::cout << std::endl;
}

void        Equation::printAnswer() {
    std::cout << "answer: " << std::endl;
    std::cout << "number resolve: " << num_answer << std::endl;
    std::cout << "korenb: " << real[0] << std::endl;
}

Equation::~Equation() {}
