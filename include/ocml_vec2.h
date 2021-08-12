#ifndef __OCML_VEC2_H__
#define __OCML_VEC2_H__

#include <inttypes.h>
#include <ocml_vec_defs.h>

#define VEC2_STRUCT_DECL(type,t)\
typedef struct\
{\
	type x, y;\
} vec2##t;

#define VEC2_DECL(type,t)\
VEC2_STRUCT_DECL(type,t)\
VEC_DECL(2,type,t)

VEC_DECL_TYPES(VEC2_DECL)

#endif
