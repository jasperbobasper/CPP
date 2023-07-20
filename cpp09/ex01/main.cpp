#include "RPN.hpp"
#include <ctype.h>

int main(int argc, char *argv[])
{
    RPN st;

    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return -1;
    }
    for (int i = 0; argv[1][i]; i++)
    {
        if (isdigit(int(argv[1][i])))
        {
            if (argv[1][i + 1] != ' ') {
                std::cerr << "Error" << std::endl;
                return -1;
            }
            else
                st.pushToStack(int(argv[1][i]) - 48);
        }
        else if (argv[1][i] == '+')
            st.add();
        else if (argv[1][i] == '-')
            st.subtract();
        else if (argv[1][i] == '*')
            st.multiply();
        else if (argv[1][i] == '/')
            st.divide();
        else if (argv[1][i] != ' ') {
            std::cerr << "Error" << std::endl;
            return -1;
        }
    }
    st.printResult();
    return 0;
}