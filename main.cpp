#include <iostream>
#include "Compiler.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			std::string	arg(av[1]);
			Compiler	c(arg);
			c.compile();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
