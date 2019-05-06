#include "Variable.hpp"

Variable::Variable(int d, double c, bool to) : 
        degree(d), coefficient(c), to_equ(to) {}

Variable &      Variable::operator=(const Variable & v) {
    degree = v.degree;
    coefficient = v.coefficient;
    return *this;
}

Variable &      Variable::operator+(Variable & v) {
    coefficient += v.coefficient;
    return *this;
}

Variable &      Variable::operator-(Variable & v) {
    coefficient -= v.coefficient;
    return *this;
}

Variable &      Variable::operator*(Variable & v) {
    coefficient *= v.coefficient;
    return *this;
}

Variable &      Variable::operator/(Variable & v) {
    coefficient /= v.coefficient;
    return *this;
}

bool      Variable::operator==(Variable & v) {
    return (degree == v.degree && coefficient == v.coefficient);
}

Variable &      Variable::operator+=(Variable & v) {
    coefficient += v.coefficient;
    return *this;
}

Variable &      Variable::operator-=(Variable & v) {
    coefficient -= v.coefficient;
    return *this;
}

Variable &      Variable::operator*=(Variable & v) {
    coefficient *= v.coefficient;
    return *this;
}

Variable &      Variable::operator/=(Variable & v) {
    coefficient /= v.coefficient;
    return *this;
}

Variable::~Variable() {}
