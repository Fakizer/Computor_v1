#include "Computor_v1.hpp"

int main(const int ac, const char **av) {
    Equation e;
    Parser p(av[1], e);

    std::cout << std::endl;
    e.removesDooble();
    e.printallvar();

    e.resolver();

    e.printAnswer();

    return 0;
}