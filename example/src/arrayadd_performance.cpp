/*************************************************
 * @author Bin Qu
 * @email benquickdenn@foxmail.com
*************************************************/

#include <cstdio>

#include "intrin_helper.h"
#include "configuration.h"
#include "public_functions.h"
#include "timming.h"

#ifdef P_DOUBLE
typedef double type;
#else
#ifdef P_SINGLE
typedef float type;
#endif
#endif

const unsigned long LEN = 8 * 1000;

type a[LEN], b[LEN], c[LEN];

int main()
{
    using namespace std;

    /* initialize data */
    fill<type>(a, 2.0, LEN);
    fill<type>(b, 3.0, LEN);
    
    /* compute */
#ifdef VECTOR_LARGE
#ifdef P_DOUBLE
    fprintf(stdout, "elapsed %f us\n", timming_us_arrayadd_dp(vadd8d, c, a, b, LEN));
#else
#ifdef P_SINGLE
    fprintf(stdout, "elapsed %f us\n", timming_us_arrayadd_sp(vadd16f, c, a, b, LEN));
#endif
#endif
#else
#ifdef VECTOR_NORMAL
#ifdef P_DOUBLE
    fprintf(stdout, "elapsed %f us\n", timming_us_arrayadd_dp(vadd4d, c, a, b, LEN));
#else
#ifdef P_SINGLE
   fprintf(stdout, "elapsed %f us\n", timming_us_arrayadd_sp(vadd8f, c, a, b, LEN));
#endif
#endif
#else
#ifdef VECTOR_SMALL
#ifdef P_DOUBLE
    fprintf(stdout, "elapsed %f us\n", timming_us_arrayadd_dp(vadd2d, c, a, b, LEN));
#else
#ifdef P_SINGLE
    fprintf(stdout, "elapsed %f us\n", timming_us_arrayadd_sp(vadd4f, c, a, b, LEN));
#endif
#endif
#endif
#endif
#endif

    return 0;
}