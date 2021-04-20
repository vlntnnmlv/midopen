#include "IInstruction.hpp"
#include <iostream>

class LEnd : public IInstruction
{
	const static char	_sym = ']';
	public:
		LEnd() {};
		void	execute(Memory &mem,\
								std::vector<IInstruction*>::iterator &_instr_ptr)
								{
									++_instr_ptr;
									--_instr_ptr;
									if (mem.getMemory() == 0)
										_instr_ptr++;
									else
									{
										
									}
									return ;
								}
		char	getSym() const {return (_sym);}
};