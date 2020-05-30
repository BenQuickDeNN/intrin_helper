/*************************************************
 * @brief include headers shared by multiple files
 * @author Bin Qu
 * @email benquickdenn@foxmail.com
*************************************************/

#ifndef CONFIGURE_HPP

#define CONFIGURE_HPP

#include "instruction_check.hpp"

#if defined(_WIN32)

#include <intrin.h>

#elif defined(__linux__)

#include <x86intrin.h>

#endif

#include <omp.h>

/* Number of OpenMP Threads */
// const int OMP_NUM_THREADs = 4;

enum VEC_LENGTH
{
    VL0,
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
    InstructionChecker ic;

    /* check AVX512F */
    if (ic.HW_AVX512F)
        return VEC_LENGTH::VL512;
    
    /* check AVX */
    if (ic.HW_AVX)
        return VEC_LENGTH::VL256;
    
    /* check SSE */
    if (ic.HW_SSE)
        return VEC_LENGTH::VL512;
    
    /* check MMX */
    //if (ic.HW_MMX)
    //    return VEC_LENGTH::VL64;
    /* MMX doesnot support floatpoint computation */

    /* default */
    return VEC_LENGTH::VL0;
}

#endif