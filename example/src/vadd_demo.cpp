#include "intrin_helper.hpp"

#include <cstdio>

#if defined(__SINGLE__)

typedef float type;

#elif defined(__DOUBLE__)

typedef double type;

#endif

const unsigned long LEN = 16;

type c[LEN], a[LEN], b[LEN];

int main()
{
    using namespace std;

    for (unsigned long i = 0; i < LEN; i++)
    {
        a[i] = 2.0;
        b[i] = 3.0;
    }

    vadd<type>(c, a, b, LEN);

    printf("vadd result is:\n");
    for (const type& ele : c)
        printf("%.1f\t", ele);
    printf("\n");

    return 0;
}