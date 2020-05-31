/*************************************************
 * @brief include headers shared by multiple files
 * @author Bin Qu
 * @email benquickdenn@foxmail.com
*************************************************/

#ifndef CONFIGURE_HPP

#define CONFIGURE_HPP

#if defined(_WIN32)

#include <intrin.h>

#elif defined(__linux__)

#include <x86intrin.h>

#endif

#include <omp.h>

/* Number of OpenMP Threads */
// const int OMP_NUM_THREADs = 4;

#define __SINGLE__
// #define __DOUBLE__

#if defined(__SINGLE__)

typedef float type;

#elif defined(__DOUBLE__)

typedef double type;

#endif

#endif