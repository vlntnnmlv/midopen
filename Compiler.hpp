#pragma once
#ifndef COMPILER_HPP
# define COMPILER_HPP

# include "Memory.hpp"
# include "instructions/IInstruction.hpp"
# include "instructions/Decr.hpp"
# include "instructions/Incr.hpp"
# include "instructions/LBegin.hpp"
# include "instructions/LEnd.hpp"
# include "instructions/Read.hpp"
# include "instructions/Write.hpp"
# include "instructions/SLeft.hpp"
# include "instructions/SRight.hpp"
# include <vector>
# include <exception>

class Compiler
{
	public:
		typedef	IInstruction* (Compiler::*InstrCreator)();
		Compiler(std::string file);
		Compiler(const Compiler &other);
		~Compiler();

		void	compile();
		Memory	getMemory() const;
		Compiler	&operator=(const Compiler &other);

	private:
		Compiler();
		IInstruction	*_newDecr();
		IInstruction	*_newIncr();
		IInstruction	*_newLBegin();
		IInstruction	*_newLEnd();
		IInstruction	*_newRead();
		IInstruction	*_newWrite();
		IInstruction	*_newSLeft();
		IInstruction	*_newSRight();

		Memory									_mem;
		std::vector<IInstruction*>				_instructions;
		std::vector<IInstruction*>::iterator	_instr_ptr;
		const static std::string				_dict;
		InstrCreator							_instructions_av[8];

		class	WrongLoopSequenceException : public std::exception
		{
			const char	*what() const throw();
		};

};

#endif