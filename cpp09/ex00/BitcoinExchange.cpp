#include "BitcoinExchange.hpp"

Btc::Btc(std::string data)
{
	loadDatabase(data);
}

Btc &Btc::operator=(Btc &copy)
{
	this->dataset.clear();
	for (std::map<std::string, std::string>::iterator it = copy.dataset.begin(); it != copy.dataset.end(); ++it)
    {
        this->dataset.insert(*it);
    }
	return (*this);
}

Btc::Btc(Btc &copy)
{
	this->dataset.clear();
	for (std::map<std::string, std::string>::iterator it = copy.dataset.begin(); it != copy.dataset.end(); ++it)
    {
        this->dataset.insert(*it);
    }
}

Btc::~Btc()
{   
}

void formatSyntax(std::string line)
{
	std::string allowed = "0123456789|-. ";
	if (line.find_first_not_of(allowed) != std::string::npos)
        throw std::runtime_error("Invalid input");
}

bool isValidDate(int year, int month, int day) {
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int tempYear = year;
	int numDigits = 0;

	if (month < 1 || month > 12)
		return false;
	for (; tempYear > 0; numDigits++)
		tempYear /= 10;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1] || numDigits != 4)
		return false;
	return true;
}

void trim(std::string& str) {
	str.erase(0, str.find_first_not_of(' '));
	str.erase(str.find_last_not_of(' ') + 1);
}

void Btc::loadDatabase(std::string data)
{
	std::string line;
	std::ifstream newFile(("data.csv"));
	if (!newFile)
		throw std::runtime_error("Failed to open the input file");
	newFile.is_open();
	while (std::getline(newFile, line))
	{
		if (line == "date,exchange_rate")
			continue;
		std::stringstream ss(line);
		std::string date, valueStr;
		if (!getline(ss, date, ',') || !getline(ss, valueStr))
			throw std::runtime_error("Invalid line format");
		trim(date);
		trim(valueStr);
		dataset.insert(std::pair<std::string, std::string>(date, valueStr));     
		std::stringstream check(date);
		int year = 0, month = 0, day = 0;
		char dash1 = '\0', dash2 = '\0';
		check >> year >> dash1 >> month >> dash2 >> day;
		if (check.fail() || dash1 != '-' || dash2 != '-' || !month || !day || !year || !isValidDate(year, month, day))
			throw std::runtime_error("Invalid date format.");
	}
}

void Btc::SearchDataSet(std::string date, std::string value)
{
	char *end;
	float temp;
	std::map<std::string, std::string>::iterator it = dataset.find(date);
	if (it != dataset.end())
		temp = (strtof(value.c_str(), &end)) * (strtof(it->second.c_str(), &end));
	else
	{
		std::map<std::string, std::string>::iterator it = dataset.lower_bound(date);
		if (it == dataset.begin())
			throw std::runtime_error("The given date are far from the dataset");
		if (it != dataset.begin() && it->first != date)
			--it;
		if (it != dataset.end())
			temp = (strtof(value.c_str(), &end)) * (strtof(it->second.c_str(), &end));
	}
	std::cout << date <<  " => " << std::fixed << std::setprecision(1)  << value << " = " << temp << std::endl;
}
 
void Btc::syntaxCheck(std::string line)
{
	formatSyntax(line);
	size_t delimiterPos = line.find('|');
	if (delimiterPos == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}
	std::string date = line.substr(0, delimiterPos);
	std::string valueStr = line.substr(delimiterPos + 1);
	trim(date);
	trim(valueStr);

	double value = std::stod(valueStr);
	if (value < 0 || value > INT_MAX)
		throw std::runtime_error(value < 0 ? "Not a positive number." : "too large a number.");

	std::stringstream ss(date);
	int year = 0, month = 0, day = 0, other = 0;
	char dash1 = '\0', dash2 = '\0';
	ss >> year >> dash1 >> month >> dash2 >> day;
	if (ss.fail() || dash1 != '-' || dash2 != '-' || !month || !day || !year || !isValidDate(year, month, day))
		throw std::runtime_error("Invalid date format.");
	SearchDataSet(date, valueStr);
}

void Btc::takeFile(std::string file)
{
	std::ifstream infile((file).c_str());
	if (!infile)
		throw std::runtime_error("Failed to open the input file");
	infile.is_open();
	std::string line;

	while (std::getline(infile, line))
	{
		try
		{
			if (line == "date | value")
				continue;
			syntaxCheck(line);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
}
