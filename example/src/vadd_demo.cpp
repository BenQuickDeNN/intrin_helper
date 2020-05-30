#include "intrin_helper.hpp"

#include <cstdio>

typedef float type;

const unsigned long LEN = 16;

type c[LEN], a[LEN], b[LEN];

int main()
{
    using namespace std;

    for (int i = 0; i < LEN; i++)
    {
        a[i] = 2.0;
        b[i] = 3.0;
    }

    vadd<type>(c, a, b, LEN);

    printf("vadd result is:\n");
    for (const ele : c)
        printf("%.1f\t");
    printf("\n");

    return 0;
}