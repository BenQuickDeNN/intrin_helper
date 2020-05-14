/*************************************************
 * @author Bin Qu
 * @email benquickdenn@foxmail.com
*************************************************/

#include <omp.h>
#include <cstdio>

#include "intrin_helper.h"
#include "configuration.h"
#include "public_functions.h"

#ifdef P_DOUBLE
typedef double type;
#else
typedef float type;
#endif

const unsigned long LEN = 20;

type a[LEN], b[LEN], c[LEN];

int main()
{
    /* initialize data */
    fill<type>(a, 2.0, LEN);
    fill<type>(b, 3.0, LEN);

    /* compute */
#ifdef VECTOR_LARGE
#ifdef P_DOUBLE
    vadd8d(c, a, b, LEN);
#else
    vadd16f(c, a, b, LEN);
#endif
#else
#ifdef VECTOR_NORMAL
#ifdef P_DOUBLE
    vadd4d(c, a, b, LEN);
#else
    vadd8f(c, a, b, LEN);
#endif
#else
#ifdef VECTOR_SMALL
#ifdef P_DOUBLE
    vadd2d(c, a, b, LEN);
#else
    vadd4f(c, a, b, LEN);
#endif
#endif
#endif
#endif

    /* display */
    disparr<type>(c, LEN);

    return 0;
}

