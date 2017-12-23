/*#include <stddef.h>*/
/*#include <stdio.h>*/

/*unsigned int binary_array_to_numbers(const unsigned *bits, size_t count)*/
/*{*/
/*	unsigned int sum = 0;*/
/*	unsigned int index;*/
/*	unsigned int mask = 0;*/
/*	if (NULL == bits || 0 == count)*/
/*	{*/
/*		return 0;*/
/*	}*/
/*	for(index = count; index > 0; --index)*/
/*	{*/
/*		if (0 == bits[index-1])*/
/*		{*/
/*			continue;*/
/*		}*/
/*		mask = 1;*/
/*		sum += (mask <<= count - index);*/
/*	}*/
/*	return sum;*/
/*}*/

/* Online solution*/
#include <stddef.h>

unsigned binary_array_to_numbers(const unsigned *bits, size_t count) {
  unsigned res = 0;
  for (size_t i = 0; i < count; i++)
    res = res << 1 | bits[i];
  return res;
}


int main()
{
	const unsigned int bits[4] = {1,1,0,1};
	const unsigned int count = 4;
	printf ("%u\n", binary_array_to_numbers(bits, count));
	return 0;
}
