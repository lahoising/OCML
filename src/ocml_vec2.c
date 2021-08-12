#include <ocml_vec_defs.h>
#include <ocml_vec2.h>

#define VEC2_IMPL_OP(type,name,op)\
VEC_DECL_OP(type,name)\
{\
	return (type){a.x op b.x, a.y op b.y};\
}

#define VEC2_IMPL_DOT(type,t)\
VEC_DECL_DOT(type,t)\
{\
	type sum = type##_mul(a,b);\
	return sum.x + sum.y;\
}

VEC_IMPL_TYPES(2,VEC_IMPL)
