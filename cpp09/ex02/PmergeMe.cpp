#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe &copy) {
	this->deqNumbers = copy.deqNumbers;
	this->vecNumbers = copy.vecNumbers;
}
PmergeMe &PmergeMe::operator=(PmergeMe &copy) {
	this->deqNumbers = copy.deqNumbers;
	this->vecNumbers = copy.vecNumbers;
	return (*this);
}

void PmergeMe::AddNumbers(int num)
{
	if (std::find(vecNumbers.begin(), vecNumbers.end(), num) != vecNumbers.end())
		throw std::runtime_error("Duplicates found");
	vecNumbers.push_back(num);
	deqNumbers.push_back(num);
}

void PmergeMe::displayNumbers(std::vector<int> search)
{
	for (std::vector<int>::iterator it = search.begin(); it != search.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::displayNumbers(std::deque<int> search)
{
	for (std::deque<int>::iterator it = search.begin(); it != search.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::parseInput(char **argv, int argc)
{
	char *end;
	for (int j = 1; j < argc; j++)
	{
		int arg = strtol(argv[j], &end, 10);
		if (*end != '\0' || !(isdigit(argv[j][0])))
			throw std::runtime_error("Invalid Numeric Input");
		this->AddNumbers(arg);
	}
	std::cout << "Before: ";
	this->displayNumbers(vecNumbers);
}

void PmergeMe::clearNumbers()
{
	vecNumbers.clear();
}
void PmergeMe::fordJohnson(std::vector<int>& numbers)
{
	if (numbers.size() < 2) return;
	std::vector<int> large, small;

	for (size_t i = 0; i < numbers.size() - 1; i += 2)
	{
		if (numbers[i] < numbers[i + 1])
			std::swap(numbers[i], numbers[i + 1]);
		large.push_back(numbers[i]);
		small.push_back(numbers[i + 1]);
	}
	if (numbers.size() % 2 == 1) 
		large.push_back(numbers.back());
	fordJohnson(large);
	fordJohnson(small);

	std::vector<int> merged;
	size_t i = 0, j = 0;
	while (i < large.size() && j < small.size())
	{
		if (large[i] < small[j])
			merged.push_back(large[i++]);
		else
			merged.push_back(small[j++]);
	}
	while (i < large.size())
		merged.push_back(large[i++]);

	while (j < small.size())
		merged.push_back(small[j++]);
	numbers = merged;
}
void PmergeMe::fordJohnson(std::deque<int>& numbers)
{
	if (numbers.size() < 2) return;
	std::deque<int> large, small;

	for (size_t i = 0; i < numbers.size() - 1; i += 2)
	{
		if (numbers[i] < numbers[i + 1])
			std::swap(numbers[i], numbers[i + 1]);
		large.push_back(numbers[i]);
		small.push_back(numbers[i + 1]);
	}

	if (numbers.size() % 2 == 1) 
		large.push_back(numbers.back());
	fordJohnson(large);
	fordJohnson(small);
	std::deque<int> merged;
	size_t i = 0, j = 0;
	while (i < large.size() && j < small.size())
	{
		if (large[i] < small[j])
			merged.push_back(large[i++]);
		else
			merged.push_back(small[j++]);
	}
	while (i < large.size())
		merged.push_back(large[i++]);

	while (j < small.size())
		merged.push_back(small[j++]);
	numbers = merged;
}

void PmergeMe::MergeAndSort()
{
	struct timeval startVec, endVec;
    gettimeofday(&startVec, NULL);

	fordJohnson(vecNumbers);

	gettimeofday(&endVec, NULL);
	double vectorSortTime = (endVec.tv_sec - startVec.tv_sec) * 1000000.0 + (endVec.tv_usec - startVec.tv_usec);

	std::cout << "After (vector): ";
	displayNumbers(vecNumbers);
	std::cout << "Time to process a range of: "  << deqNumbers.size() << " elements with std::deque : " << std::fixed << std::setprecision(4) << vectorSortTime << " us" << std::endl;

	struct timeval startDeq, endDeq;
    gettimeofday(&startDeq, NULL);

	fordJohnson(deqNumbers);

	gettimeofday(&endDeq, NULL);
	double DeqSortTime = (endDeq.tv_sec - startDeq.tv_sec) * 1000000.0 + (endDeq.tv_usec - startDeq.tv_usec);
	std::cout << "After (deque): ";
	displayNumbers(deqNumbers);
	std::cout << "Time to process a range of: "  << deqNumbers.size() << " elements with std::deque : " << std::fixed << std::setprecision(4) << DeqSortTime << " us" << std::endl;
}
