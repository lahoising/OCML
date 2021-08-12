#ifndef __OCML_VEC_DEFS_H__
#define __OCML_VEC_DEFS_H__

#include <inttypes.h>

#define VEC_DECL_OP(type,name)\
type type##_##name(type a, type b)

#define VEC_DECL_DOT(type,t)\
t type##_dot(type a, type b)

#define VEC_DECL(count,type,t)\
VEC_DECL_OP(vec##count##t,add);\
VEC_DECL_OP(vec##count##t,sub);\
VEC_DECL_OP(vec##count##t,mul);\
VEC_DECL_OP(vec##count##t,div);\
VEC_DECL_DOT(vec##count##t,type);\

#define VEC_IMPL(count,type,t)\
VEC##count##_IMPL_OP(vec##count##t,add,+)\
VEC##count##_IMPL_OP(vec##count##t,sub,-)\
VEC##count##_IMPL_OP(vec##count##t,mul,*)\
VEC##count##_IMPL_OP(vec##count##t,div,/)\
VEC##count##_IMPL_DOT(vec##count##t,type)

#define VEC_DECL_TYPES(definition)\
definition(float,f)\
definition(int,i)\
definition(double,d)\
definition(uint32_t,u32)

#define VEC_IMPL_TYPES(count,definition)\
definition(count,float,f)\
definition(count,int,i)\
definition(count,double,d)\
definition(count,uint32_t,u32)

#endif
