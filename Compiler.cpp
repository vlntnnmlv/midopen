#include "Compiler.hpp"
#include <fstream>
#include <iostream>

const std::string Compiler::_dict = "+-<>[].,";

Compiler::Compiler(std::string f):
_mem()
{
	_instructions_av[0] = &Compiler::_newIncr;
	_instructions_av[1] = &Compiler::_newDecr;
	_instructions_av[2] = &Compiler::_newSLeft;
	_instructions_av[3] = &Compiler::_newSRight;
	_instructions_av[4] = &Compiler::_newLBegin;
	_instructions_av[5] = &Compiler::_newLEnd;
	_instructions_av[6] = &Compiler::_newWrite;
	_instructions_av[7] = &Compiler::_newRead;

	std::ifstream	file(f);
	int				inclusion = 0;

	if (file.is_open())
	{
		char	c;
		int		index;
		while (file.get(c))
		{
			if ((index = _dict.find(c)) != -1)
			{
				if (index == 4)
					++inclusion;
				if (inclusion < 0)
					throw WrongLoopSequenceException();
				IInstruction *push = (this->*_instructions_av[index])();
				push->setInclusion(inclusion);
				_instructions.push_back(push);
				if (index == 5)
					--inclusion;
			}
		}
	}
	return ;
}

Compiler::Compiler(const Compiler &other):
_mem(other._mem),
_instructions(other._instructions)
{
	return ;
}

Compiler::~Compiler()
{
	return ;
}

void	Compiler::compile()
{
	unsigned int i = 0;
	while (i < _instructions.size())
	{
		_instructions[i]->execute(_mem, _instr_ptr);
		++i;
	}
}

Memory	Compiler::getMemory() const
{
	return (_mem);
}

Compiler	&Compiler::operator=(const Compiler &other)
{
	if (this != &other)
	{
		_mem = other._mem;
		_instructions = other._instructions;
	}
	return (*this);
}

IInstruction	*Compiler::_newDecr()
{
	IInstruction	*res = new Decr();
	return (res);
}

IInstruction	*Compiler::_newIncr()
{
	IInstruction	*res = new Incr();
	return (res);
}

IInstruction	*Compiler::_newLBegin()
{
	IInstruction	*res = new LBegin();
	return (res);
}

IInstruction	*Compiler::_newLEnd()
{
	IInstruction	*res = new LEnd();
	return (res);
}

IInstruction	*Compiler::_newRead()
{
	IInstruction	*res = new Read();
	return (res);
}

IInstruction	*Compiler::_newWrite()
{
	IInstruction	*res = new Write();
	return (res);
}

IInstruction	*Compiler::_newSLeft()
{
	IInstruction	*res = new SLeft();
	return (res);
}

IInstruction	*Compiler::_newSRight()
{
	IInstruction	*res = new SRight();
	return (res);
}

const char	*Compiler::WrongLoopSequenceException::what() const throw()
{
	return ("Exception: wrong loop operator sequence");
}