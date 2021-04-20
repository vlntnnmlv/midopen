#include <iostream>

// Brainfuck compiler.
// Brainfuck has 8 instructions:
// - '+' -	increment current mem_ptr value
// - '-' -	decerment current mem_ptr value
// - '<' -	move mem_ptr to left by one
// - '>' -	move mem_ptr to right by one
// - '[' -	begin if the cycle, if current mem_ptr value > 0,
// 			then move instruction_ptr to the right by one,
// 			else goto the paired '[' instruction
// - ']' -	end of cycle, if current mem_ptr value == 0,
// 			then go move instruction_ptr to the right by one,
// 			else go to the paired '[' instruction
// - '.'	write current mem_ptr value to stdin as ASCII chararcter.
// - ','	read from stdin to current mem_ptr value
// This program will be able to take in Brainfuck code in a file,
// and create an executable which will preform the actions described in a file,
// respectivly to their defintions above.

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