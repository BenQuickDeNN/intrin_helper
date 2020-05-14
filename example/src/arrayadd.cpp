/*************************************************
 * @author Bin Qu
 * @email benquickdenn@foxmail.com
*************************************************/

#include <omp.h>
#include <cstdio>

#include "intrin_helper.h"
#include "vector_instruction_level.h"

typedef float type;

const unsigned long LEN = 20;

type a[LEN], b[LEN], c[LEN];

/**
 * @brief fill array arr with value val
 * @param arr array
 * @param val value
 * @param len length of arr
 */
void fill(type* arr, const type& val, const unsigned long& len);

/**
 * @brief print the elements of array arr
 * @param arr array
 * @param len length of arr
 */
void disparr(const type* arr, const unsigned long& len);

int main()
{
    /* initialize data */
    fill(a, 2.0, LEN);
    fill(b, 3.0, LEN);

    /* compute */
#ifdef VECTOR_LARGE
    vadd16f(c, a, b, LEN);
#else
#ifdef VECTOR_NORMAL
    vadd8f(c, a, b, LEN);
#else
#ifdef VECTOR_SMALL
    vadd4f(c, a, b, LEN);
#endif
#endif
#endif

    /* display */
    disparr(c, LEN);

    return 0;
}

void fill(type* arr, const type& val, const unsigned long& len)
{
    #pragma omp parallel for
    for (unsigned long i = 0; i < len; i++)
        arr[i] = val;
}

void disparr(const type* arr, const unsigned long& len)
{
    using namespace std;
    fprintf(stdout, "[");
    for (unsigned long i = 0; i < len - 1; i++)
        fprintf(stdout, "%.1f ", arr[i]);
    fprintf(stdout, "%.1f]\n", arr[len - 1]);
}