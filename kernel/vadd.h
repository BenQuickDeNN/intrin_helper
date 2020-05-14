/**********************************************
 * @brief vector add implementation
 * @author Bin Qu
 * @email benquickdenn@foxmail.com
**********************************************/

#ifndef VADD_H

#define VADD_H

#include "configuration.h"

/**
 * @brief vector add for 128 bits float
 * @param c array to store
 * @param a,b arrays to read
 * @param len length of array
 */
inline void vadd4f(float* c, const float* a, const float* b, const unsigned long& len);

/**
 * @brief vector add for 256 bits float
 * @param c array to store
 * @param a,b arrays to read
 * @param len length of array
 */
inline void vadd8f(float* c, const float* a, const float* b, const unsigned long& len);

/**
 * @brief vector add for 512 bits float
 * @param c array to store
 * @param a,b arrays to read
 * @param len length of array
 */
inline void vadd16f(float* c, const float* a, const float* b, const unsigned long& len);

/**
 * @brief vector add for 128 bits double
 * @param c array to store
 * @param a,b arrays to read
 * @param len length of array
 */
inline void vadd2d(double* c, const double* a, const double* b, const unsigned long& len);

/**
 * @brief vector add for 256 bits double
 * @param c array to store
 * @param a,b arrays to read
 * @param len length of array
 */
inline void vadd4d(double* c, const double* a, const double* b, const unsigned long& len);

/**
 * @brief vector add for 512 bits double
 * @param c array to store
 * @param a,b arrays to read
 * @param len length of array
 */
inline void vadd8d(double* c, const double* a, const double* b, const unsigned long& len);

inline void vadd4f(float* c, const float* a, const float* b, const unsigned long& len)
{
    const unsigned long len1 = (len / 4) * 4; // length of aligned elements
    const unsigned long len2 = len % 4;       // length of unaligned elements
    __m128 xmm_a, xmm_b;
    #pragma omp parallel for num_threads(OMP_NUM_THREADs) private(xmm_a, xmm_b)
    for (unsigned long i = 0; i < len1; i += 4)
    {
        xmm_a = _mm_load_ps(a + i);
        xmm_b = _mm_load_ps(b + i);
        xmm_a = _mm_add_ps(xmm_a, xmm_b);
        _mm_store_ps(c + i, xmm_a);
    }
    for (unsigned int i = len1; i < len2; i++)
        c[i] = a[i] + b[i];
}

inline void vadd8f(float* c, const float* a, const float* b, const unsigned long& len)
{
    const unsigned long len1 = (len / 8) * 8; // length of aligned elements
    const unsigned long len2 = len % 8;       // length of unaligned elements
    __m256 xmm_a, xmm_b;
    #pragma omp parallel for num_threads(OMP_NUM_THREADs) private(xmm_a, xmm_b)
    for (unsigned long i = 0; i < len1; i += 8)
    {
        xmm_a = _mm256_load_ps(a + i);
        xmm_b = _mm256_load_ps(b + i);
        xmm_a = _mm256_add_ps(xmm_a, xmm_b);
        _mm256_store_ps(c + i, xmm_a);
    }
    for (unsigned int i = len1; i < len2; i++)
        c[i] = a[i] + b[i];
}

inline void vadd16f(float* c, const float* a, const float* b, const unsigned long& len)
{
    const unsigned long len1 = (len / 16) * 16; // length of aligned elements
    const unsigned long len2 = len % 16;       // length of unaligned elements
    __m512 xmm_a, xmm_b;
    #pragma omp parallel for num_threads(OMP_NUM_THREADs) private(xmm_a, xmm_b)
    for (unsigned long i = 0; i < len1; i += 16)
    {
        xmm_a = _mm512_load_ps(a + i);
        xmm_b = _mm512_load_ps(b + i);
        xmm_a = _mm512_add_ps(xmm_a, xmm_b);
        _mm512_store_ps(c + i, xmm_a);
    }
    for (unsigned int i = len1; i < len2; i++)
        c[i] = a[i] + b[i];
}

inline void vadd2d(double* c, const double* a, const double* b, const unsigned long& len)
{
    const unsigned long len1 = (len / 2) * 2; // length of aligned elements
    const unsigned long len2 = len % 2;       // length of unaligned elements
    __m128d xmm_a, xmm_b;
    #pragma omp parallel for num_threads(OMP_NUM_THREADs) private(xmm_a, xmm_b)
    for (unsigned long i = 0; i < len1; i += 2)
    {
        xmm_a = _mm_load_pd(a + i);
        xmm_b = _mm_load_pd(b + i);
        xmm_a = _mm_add_pd(xmm_a, xmm_b);
        _mm_store_pd(c + i, xmm_a);
    }
    for (unsigned int i = len1; i < len2; i++)
        c[i] = a[i] + b[i];
}

inline void vadd4d(double* c, const double* a, const double* b, const unsigned long& len)
{
    const unsigned long len1 = (len / 4) * 4; // length of aligned elements
    const unsigned long len2 = len % 4;       // length of unaligned elements
    __m256d xmm_a, xmm_b;
    #pragma omp parallel for num_threads(OMP_NUM_THREADs) private(xmm_a, xmm_b)
    for (unsigned long i = 0; i < len1; i += 4)
    {
        xmm_a = _mm256_load_pd(a + i);
        xmm_b = _mm256_load_pd(b + i);
        xmm_a = _mm256_add_pd(xmm_a, xmm_b);
        _mm256_store_pd(c + i, xmm_a);
    }
    for (unsigned int i = len1; i < len2; i++)
        c[i] = a[i] + b[i];
}

inline void vadd8d(double* c, const double* a, const double* b, const unsigned long& len)
{
    const unsigned long len1 = (len / 8) * 8; // length of aligned elements
    const unsigned long len2 = len % 8;       // length of unaligned elements
    __m512d xmm_a, xmm_b;
    #pragma omp parallel for num_threads(OMP_NUM_THREADs) private(xmm_a, xmm_b)
    for (unsigned long i = 0; i < len1; i += 8)
    {
        xmm_a = _mm512_load_pd(a + i);
        xmm_b = _mm512_load_pd(b + i);
        xmm_a = _mm512_add_pd(xmm_a, xmm_b);
        _mm512_store_pd(c + i, xmm_a);
    }
    for (unsigned int i = len1; i < len2; i++)
        c[i] = a[i] + b[i];
}

#endif