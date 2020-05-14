/*************************************************
 * @author Bin Qu
 * @email benquickdenn@foxmail.com
*************************************************/

#ifndef TIMING_H

#define TIMING_H

#define A_MILLION 1000000.0

#if defined(_WIN32) || defined(_WIN64)   // 当前操作系统为Windows

#include <windows.h>

#else
#if defined(__linux) || defined(__linux__)  // 当前操作系统为Linux

#endif
#endif

/**
 * @brief 执行数组加单精度内核并计时
 * @param kernel 内核函数指针
 * @return 运行时间(us)
 */
inline float timming_us_arrayadd_sp(void (*kernel)(float*, const float*, const float*, const unsigned long&),
    float* c, const float* a, const float* b, const unsigned long& len);

/**
 * @brief 执行数组加双精度内核并计时
 * @param kernel 内核函数指针
 * @return 运行时间(us)
 */
inline float timming_us_arrayadd_dp(void (*kernel)(double*, const double*, const double*, const unsigned long&),
    double* c, const double* a, const double* b, const unsigned long& len);

inline float timming_us_arrayadd_sp(void (*kernel)(float*, const float*, const float*, const unsigned long&),
    float* c, const float* a, const float* b, const unsigned long& len)
{
#if defined(_WIN32) || defined(_WIN64)   // 当前操作系统为Windows

    /* 定义计时器 */
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency); // 获取硬件时钟频率

    /* 执行内核并计时 */
    QueryPerformanceCounter(&start);
    kernel(c, a, b, len);
    QueryPerformanceCounter(&end);
    return (float)((end.QuadPart - start.QuadPart) / (frequency.QuadPart / A_MILLION));

#else
#if defined(__linux) || defined(__linux__)  // 当前操作系统为Linux

#endif
#endif
    return 0.0;
}

inline float timming_us_arrayadd_dp(void (*kernel)(double*, const double*, const double*, const unsigned long&),
    double* c, const double* a, const double* b, const unsigned long& len)
{
#if defined(_WIN32) || defined(_WIN64)   // 当前操作系统为Windows

    /* 定义计时器 */
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency); // 获取硬件时钟频率

    /* 执行内核并计时 */
    QueryPerformanceCounter(&start);
    kernel(c, a, b, len);
    QueryPerformanceCounter(&end);
    return (float)((end.QuadPart - start.QuadPart) / (frequency.QuadPart / A_MILLION));

#else
#if defined(__linux) || defined(__linux__)  // 当前操作系统为Linux

#endif
#endif
    return 0.0;
}

#endif