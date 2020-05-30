/*************************************************
 * @brief include headers shared by multiple files
 * @author Bin Qu
 * @email benquickdenn@foxmail.com
*************************************************/

#ifndef CONFIGURE_HPP

#define CONFIGURE_HPP

#include <intrin.h>
#include <omp.h>

/* Number of OpenMP Threads */
// const int OMP_NUM_THREADs = 4;

enum VEC_LENGTH
{
    VL64,
    VL128,
    VL256,
    VL512
};

/**
 * @brief check the max length of vector extension
 */
VEC_LENGTH checkVectorWidth();

VEC_LENGTH checkVectorWidth()
{
    
    /* 检测AVX512F */
    /* 检测AVX */
    /* 检测SSE */
    /* 检测MMX */
}

#endif