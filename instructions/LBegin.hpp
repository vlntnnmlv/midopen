#include "IInstruction.hpp"
#include <iostream>

class LBegin : public IInstruction
{
	const static char	_sym = '[';
	public:
		LBegin() {};
		void	execute(Memory &mem,\
								std::vector<IInstruction*>::iterator &_instr_ptr)
								{
									++_instr_ptr;
									--_instr_ptr;
									if (mem.getMemory() > 0)
										_instr_ptr++;
									else
									{
										std::vector<IInstruction*>::iterator it = _instr_ptr;
									}
									return ;
								}
		char	getSym() const {return (_sym);}
};