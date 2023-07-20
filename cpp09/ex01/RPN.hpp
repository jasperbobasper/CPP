#include <stack>
#include <iostream>

class RPN
{
    public:
        RPN(void);
        ~RPN(void);
        void add();
        void subtract();
        void multiply();
        void divide();
        void pushToStack(int i);
        void printResult();
    private:
        std::stack<int> _st;
        RPN(RPN const &src);
        RPN &operator=(RPN const &rhs);
};