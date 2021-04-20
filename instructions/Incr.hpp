#include "IInstruction.hpp"

class Incr : public IInstruction
{
	public:
		Incr() {};
		void	execute(Memory &mem,\
								std::vector<IInstruction*>::iterator &_instr_ptr)
								{
									++_instr_ptr;
									--_instr_ptr;
									mem.incMemory();
									return ;
								}
};