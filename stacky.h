#ifndef STACKY_H_
#define STACKY_H_

#include <stdint.h>

void stacky_print(const void *stack_ptr)
{
	/* only interested in aligned addresses on the stack */
	const uint64_t *p = (uint64_t *)(((uintptr_t)stack_ptr) & ~(0x7));

	/* the stack grows down, so we walk it up in word steps */
	int count = 0;
	for (;count < 80; ++count, ++p)
	{
		const uint64_t value = *p;
		fprintf(stderr, "%016x @ %016x\n", value, p);

		if (value >= 0x400000 && value <= 0x410000)
		{
			fprintf(stderr, "%016x\n", value);
		}
	}
}


#endif /* STACKY_H_ */
