#include "mu_test.h"
#include "../BitSet/BitSet.h"
#include "../BitRef/BitRef.h"


UNIT(Default_CTOR_ThenSet)

	BitSet<32, unsigned int> bs1;

	

	ASSERT_THAT(strcmp(createdString_t.cp(), "") == 0);



END_UNIT
