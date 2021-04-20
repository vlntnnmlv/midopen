#pragma once
#ifndef IINSTRUCTION_HPP
# define IINSTRUCTION_HPP

# include "../Memory.hpp"
# include <vector>

class IInstruction
{

	int				_inclusion;

	public:
		virtual void	execute(Memory &mem,\
								std::vector<IInstruction*>::iterator &_instr_ptr) = 0;
		int				getInclusion() const {return (_inclusion);}
		void			setInclusion(int value) {_inclusion = value;}
};

#endif