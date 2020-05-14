#ifndef CONFIGURATION_H

#define CONFIGURATION_H

/* select vector length */
#define VECTOR_SMALL    // 128 bits. SSE
//#define VECTOR_NORMAL // 256 bits. SSE2, AVX, AVX2
//#define VECTOR_LARGE  // 512 bits. AVX512

/* select precision */
#define P_SINGLE    // single
//#define P_DOUBLE    // double

#endif