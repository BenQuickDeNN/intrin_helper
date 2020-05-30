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

// #define __SSE__
// #define __AVX__
// #define __AVX512F__

#define __SINGLE__
// #define __DOUBLE__

/**
 * @suppress
 */
enum VEC_WIDTH
{
    VL0,
    VL64,
    VL128,
    VL256,
    VL512
};

/**
 * @brief check the max length of vector extension
 * @suppress
 */
VEC_WIDTH checkVectorWidth();

VEC_WIDTH checkVectorWidth()
{
    /* initialize instruction_checker */
    InstructionChecker ic;

    /* check AVX512F */
    if (ic.HW_AVX512F)
        return VEC_WIDTH::VL512;
    
    /* check AVX */
    if (ic.HW_AVX)
        return VEC_WIDTH::VL256;
    
    /* check SSE */
    if (ic.HW_SSE)
        return VEC_WIDTH::VL128;
    
    /* check MMX */
    //if (ic.HW_MMX)
    //    return VEC_LENGTH::VL64;
    /* MMX doesnot support floatpoint computation */

    /* default */
    return VEC_WIDTH::VL0;
}

// global vector width
/**
 * @suppress
 */
const VEC_WIDTH _vec_width = checkVectorWidth();

#endif