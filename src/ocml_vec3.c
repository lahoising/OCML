#include <ocml_vec3.h>

#define VEC3_IMPL_OP(type,name,op)\
VEC_DECL_OP(type,name)\
{\
	return (type){a.x op b.x, a.y op b.y, a.z op b.z};\
}

#define VEC3_IMPL_DOT(type,t)\
VEC_DECL_DOT(type,t)\
{\
	type sum = type##_mul(a, b);\
	return sum.x + sum.y + sum.z;\
}

#define VEC3_IMPL_CROSS(type)\
VEC3_DECL_CROSS(type)\
{\
	return (type){\
		(a.y * b.z - b.y * a.z),\
	       	-(a.x * b.z - b.x * a.z),\
		(a.x * b.y - b.x * a.y)};\
}

#define VEC3_IMPL(type,t)\
VEC_IMPL(3,type,t)\
VEC3_IMPL_CROSS(vec3##t)

VEC_DECL_TYPES(VEC3_IMPL)
