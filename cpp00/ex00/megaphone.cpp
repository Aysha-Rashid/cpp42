#include <iostream>

// forbidden namespace and friend keyword

void ft_change(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (islower(str[i]))
			std::cout << (char)toupper(str[i]);
		else
			std::cout << str[i];
		i++;
	}
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (argv[i])
	{
		ft_change(argv[i]);
		i++;
	}
	std::cout << std::endl;
	return 0;
}
