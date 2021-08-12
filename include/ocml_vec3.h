#ifndef __OCML_VEC3_H__ 
#define __OCML_VEC3_H__

#include <inttypes.h>
#include <ocml_vec_defs.h>

#define VEC3_STRUCT_DECL(type,t)\
typedef struct\
{\
	type x, y, z;\
} vec3##t;

#define VEC3_DECL_CROSS(type)\
type type##_cross(type a, type b)

#define VEC3_DECL(type,t)\
VEC3_STRUCT_DECL(type,t)\
VEC_DECL(3,type,t)\
VEC3_DECL_CROSS(vec3##t);

VEC_DECL_TYPES(VEC3_DECL)

#endif
