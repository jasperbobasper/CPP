#include "RPN.hpp"

RPN::RPN(void)
{
}
RPN::~RPN(void)
{
}
void RPN::add()
{
    int i = _st.top();
    _st.pop();
    int j = _st.top();
    _st.pop();
    pushToStack(i + j);
}
void RPN::subtract()
{
    int i = _st.top();
    _st.pop();
    int j = _st.top();
    _st.pop();
    pushToStack(j - i);
}
void RPN::multiply()
{
    int i = _st.top();
    _st.pop();
    int j = _st.top();
    _st.pop();
    pushToStack(i * j);
}
void RPN::divide()
{
    int i = _st.top();
    _st.pop();
    int j = _st.top();
    _st.pop();
    pushToStack(j / i);
}
void RPN::pushToStack(int i)
{
    _st.push(i);
}
void RPN::printResult()
{
    int top = _st.top();
    _st.pop();
    if (_st.size() > 0)
        std::cerr << "Error" << std::endl;
    else
        std::cout << top << std::endl;
}