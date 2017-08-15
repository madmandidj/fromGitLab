#include "b.h"

int max(int _a, int _b)
{
	return _a > _b ? add(_a, _b) : sub(_a, _b);
}

int min(int _a, int _b)
{
	return _a < _b ? add(_a, _b) : sub(_a, _b);
}

