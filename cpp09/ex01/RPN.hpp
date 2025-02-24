#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <deque>
#include <stack>

class RPN
{
	private:
		std::stack<std::string> RPN_Stack;
	public:
		RPN(std::string values);
		RPN(RPN &copy);
		RPN &operator=(RPN &copy);
		~RPN();
		void parseInput(std::string argv);
		void RPN_calculation(void);
};
