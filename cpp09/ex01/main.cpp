#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

int is_operator(char ex)
{
    if (ex == '+' || ex == '-'|| ex == '*' || ex == '/')
        return (1);
    return (0);
    
}

int is_valid_rpn(std::string exp)
{
    int count = 0;
    for(size_t i = 0; i < exp.length(); i++)
    {
        if (isblank(exp[i]))
            continue ;
        else if (isdigit(exp[i]))
        {
            count++;
            continue ;
        }
        else if (is_operator(exp[i]))
        {
            if (count < 2)
                return (0);
            count--;
        }
        else
            return (0);
    }
    if (count == 1)
        return (1);
    return (0);
}

int calcul_rpn(std::string exp)
{
    std::stack<int> stack;
    int num1, num2;
    for (size_t i = 0; i < exp.length(); i++) {
        if (isdigit(exp[i]))
        {
            stack.push(exp[i] - '0');
        }
        else if (is_operator(exp[i])) 
        {
            num2 = stack.top();
            stack.pop();
            num1 = stack.top();
            stack.pop();

            switch (exp[i])
            {
                case '+':
                {
                    stack.push(num1 + num2);
                    break;
                }
                case '-':
                {
                    stack.push(num1 - num2);
                    break;
                }
                case '*':
                {
                    stack.push(num1 * num2);
                    break;
                }
                case '/':
                {
                    stack.push(num1 / num2);
                    break; 
                }
            }
        }
    }
    return stack.top();
}

int main(int ac, char **av) 
{
    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " <inverted Polish mathematical exp>" << std::endl;
        return (1);
    }
    if (!is_valid_rpn(av[1]))
    {
        std::cout << av[1] << " : THIS IS NOT A VALID RPN" << std::endl;
        return 0;
    }
    int result = calcul_rpn(av[1]);
    std::cout << result << std::endl;
    return 0;
}