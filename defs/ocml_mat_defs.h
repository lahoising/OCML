#ifndef __OCML_MAT_DEFS_H__
#define __OCML_MAT_DEFS_H__

#define MAT_TYPE(_row,_col,t) mat##t##_rowx##_col

#define MAT_DECL(_row,_col,type,t)\
typedef type MAT_TYPE(_row,_col,t)[_col*_row];\
type *MAT_TYPE(_row,_col,t)_ite(MAT_TYPE(_row,_col,t) mat, uint32_t row, uint32_t col){ return &mat[col*_row + row]; }

#endif
