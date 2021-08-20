#ifndef __OCML_MAT_DEFS_H__
#define __OCML_MAT_DEFS_H__

#include <inttypes.h>

#define MAT_TYPE(_row,_col,t) mat##t##_row##x##_col

#define MAT_IDENTITY(count,t)\
MAT_TYPE(count,count,t) mat##t##count##x##count##_identity()\
{\
	MAT_TYPE(count,count,t) ret = {0};\
	for(int i = 0; i < count; i++)\
	{\
		ret.values[i][i] = (typeof(ret.values[0][0]))1;\
	}\
	return ret;\
}

#define MAT_MULT(_row,_col,type,t)\
MAT_TYPE(_row,_col,t) mat##t##_row##x##_col##_mult(type *lhs, type *rhs)\
{\
	MAT_TYPE(_row,_col,t) mat = {0};\
	for(int c = 0; c < _col; c++)\
	{\
		for(int r = 0; r < _row; r++)\
		{\
			for(int cc = 0; cc < _col; cc++)\
			{\
				float left  = *(lhs + cc*_row + r);\
				float right = *(rhs + c*_row + cc);\
				mat.values[c][r] += left * right;\
			}\
		}\
	}\
	return mat;\
}

#define MAT_DECL(_row,_col,type,t)\
typedef struct\
{\
	type values[_col][_row];\
} mat##t##_row##x##_col;

#endif
