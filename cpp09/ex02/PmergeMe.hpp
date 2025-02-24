#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iterator>
#include <iomanip>
#include <sys/time.h>

class PmergeMe
{
	private:
		std::vector<int> vecNumbers;
		std::deque<int> deqNumbers;
		void fordJohnson(std::vector<int> &numbers);
		void fordJohnson(std::deque<int> &numbers);
	public:
		PmergeMe();
		PmergeMe(PmergeMe &copy);
		PmergeMe &operator=(PmergeMe &copy);
		~PmergeMe();
		void clearNumbers();
		void AddNumbers(int num);
		void parseInput(char **argv, int argc);
		void displayNumbers(std::vector<int> search);
		void displayNumbers(std::deque<int> search);
		void MergeAndSort(void);
};
