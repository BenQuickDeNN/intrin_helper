#ifndef PUBLIC_FUNCTIONS_H

#define PUBLIC_FUNCTIONS_H

#include <omp.h>

template<class T> 
/**
 * @brief fill array arr with value val
 * @param arr array
 * @param val value
 * @param len length of arr
 */
void fill(T* arr, const T& val, const unsigned long& len);

template<class T> 
/**
 * @brief print the elements of array arr
 * @param arr array
 * @param len length of arr
 */
void disparr(const T* arr, const unsigned long& len);

template<class T> 
void fill(T* arr, const T& val, const unsigned long& len)
{
    #pragma omp parallel for
    for (unsigned long i = 0; i < len; i++)
        arr[i] = val;
}

template<class T> 
void disparr(const T* arr, const unsigned long& len)
{
    using namespace std;
    fprintf(stdout, "[");
    for (unsigned long i = 0; i < len - 1; i++)
        fprintf(stdout, "%.1f ", arr[i]);
    fprintf(stdout, "%.1f]\n", arr[len - 1]);
}

#endif