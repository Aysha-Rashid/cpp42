#include "RPN.hpp"

RPN::RPN(std::string values)
{
	parseInput(values);
}

RPN::RPN(RPN &copy)
{
    while (!copy.RPN_Stack.empty()) {
		this->RPN_Stack.push(copy.RPN_Stack.top());
		copy.RPN_Stack.pop();
	}
}
RPN &RPN::operator=(RPN &copy)
{
    while (!copy.RPN_Stack.empty()) {
		this->RPN_Stack.push(copy.RPN_Stack.top());
		copy.RPN_Stack.pop();
	}
	return (*this);
}

RPN::~RPN(){}

void RPN::parseInput(std::string argv)
{
	std::string allowed = "0123456789+-*/ ";
	if (argv.find_first_not_of(allowed) != std::string::npos)
		throw std::runtime_error("Invalid input");
	std::stringstream ss(argv);
	std::string i;
	while(ss >> i)
	{
		if (isdigit(i[0]))
		{
			int num = std::stoi(i);
			if (num > 10)
				throw std::runtime_error("digits more than 10");
			RPN_Stack.push(i);
		}
		else if (i.size() == 1 && (i == "+" || i == "-" || i == "*" || i == "/"))
			RPN_Stack.push(i);
	}
}

void RPN::RPN_calculation()
{
	std::stack<int> calculationStack;
	std::stack<std::string> reverseStack;
	while (!RPN_Stack.empty()) {
		reverseStack.push(RPN_Stack.top());
		RPN_Stack.pop();
	}
	while (!reverseStack.empty())
	{
		std::string token = reverseStack.top();
		reverseStack.pop();
		if (isdigit(token[0]))
			calculationStack.push(std::stoi(token));
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (calculationStack.size() < 2)
				throw std::runtime_error("Insufficient operands for operation");
			int operand2 = calculationStack.top();
			calculationStack.pop();
			int operand1 = calculationStack.top();
			calculationStack.pop();

			int result = 0;
			if (token == "+")
				result = operand1 + operand2;
			else if (token == "-")
				result = operand1 - operand2;
			else if (token == "*")
				result = operand1 * operand2;
			else if (token == "/")
			{
				if (operand2 == 0)
					throw std::runtime_error("Division by zero");
				result = operand1 / operand2;
			}
			calculationStack.push(result);
		}
	}
	if (calculationStack.size() != 1)
		throw std::runtime_error("Invalid RPN expression");
	std::cout << "Final result: " << calculationStack.top() << std::endl;
}
