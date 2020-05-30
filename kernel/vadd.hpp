/**********************************************
 * @brief vector add implementation
 * @author Bin Qu
 * @email benquickdenn@foxmail.com
**********************************************/

#ifndef VADD_HPP

#define VADD_HPP

#include "../utilities/configure.hpp"

#include <cstdlib>
#include <iostream>

/**
 * @brief vector add
 * @param c array to store
 * @param a,b arrays to read
 * @param len length of array
 */
template<class T> inline void vadd(T* c, const T* a, const T* b, const unsigned long& len);

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

template<class T> inline void vadd(T* c, const T* a, const T* b, const unsigned long& len)
{
    using namespace std;

    /* check precision */
    if (sizeof(T) == sizeof(float))
    {
        // single precision
        switch(_vec_width)
        {
            case VEC_WIDTH::VL512:
                vadd16f(c, a, b, len);
                break;
            case VEC_WIDTH::VL256:
                vadd8f(c, a, b, len);
                break;
            case VEC_WIDTH::VL128:
                vadd4f(c, a, b, len);
                break;
            default:
                cerr << "vadd error: vector extension is not supported!" << endl;
                break;
        }
    }
    else if (sizeof(T) == sizeof(double))
    {
        // double precision
        switch(_vec_width)
        {
            case VEC_WIDTH::VL512:
                vadd8d(c, a, b, len);
                break;
            case VEC_WIDTH::VL256:
                vadd4d(c, a, b, len);
                break;
            case VEC_WIDTH::VL128:
                vadd2d(c, a, b, len);
                break;
            default:
                cerr << "vadd error: vector extension is not supported!" << endl;
                break;
        }
    }
    else
        cerr << "vadd error: unknown precision!" << endl;
}

inline void vadd4f(float* c, const float* a, const float* b, const unsigned long& len)
{
    const unsigned long len1 = (len / 4) * 4; // length of aligned elements
    const unsigned long len2 = len % 4;       // length of unaligned elements
    __m128 xmm_a, xmm_b;
    #pragma omp parallel for private(xmm_a, xmm_b)
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
    #pragma omp parallel for private(xmm_a, xmm_b)
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
    #pragma omp parallel for private(xmm_a, xmm_b)
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
    #pragma omp parallel for private(xmm_a, xmm_b)
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
    #pragma omp parallel for private(xmm_a, xmm_b)
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
    #pragma omp parallel for private(xmm_a, xmm_b)
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