#ifndef _INDEXEXCPTION__
#define _INDEXEXCPTION__

struct IndexException {
	uint index;
	uint maxIndex;
	IndexException(int ind, int max) : index(ind), maxIndex(max) {}
};

#endif // !_INDEXEXCPTION__
