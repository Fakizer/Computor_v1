#ifndef VARIABLE_HPP
#define VARIABLE_HPP

class Variable
{
private:
    /* data */
public:

    int     degree;
    double  coefficient;
    bool    is_pos;
    bool    to_equ;

    Variable(int d, double c, bool to);
    Variable &  operator=(const Variable & v);
    Variable &  operator+(Variable & v);
    Variable &  operator-(Variable & v);
    Variable &  operator*(Variable & v);
    Variable &  operator/(Variable & v);

    bool        operator==(Variable & v);
    Variable &  operator+=(Variable & v);
    Variable &  operator-=(Variable & v);
    Variable &  operator*=(Variable & v);
    Variable &  operator/=(Variable & v);


    Variable() = default;
    ~Variable();
};



#endif
