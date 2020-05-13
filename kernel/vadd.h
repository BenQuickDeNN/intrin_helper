/**********************************************
 * @brief vector add implementation
 * @author Bin Qu
 * @email benquickdenn@foxmail.com
**********************************************/

#include "shared_headers.h"

/**
 * @brief vector add for 128 bits float
 * @param c array to store
 * @param a,b arrays to read
 * @param len length of array
 */
inline void vadd4f(float* c, const float* a, const float* b, const int& len);

/**
 * @brief vector add for 256 bits float
 * @param c array to store
 * @param a,b arrays to read
 * @param len length of array
 */
inline void vadd8f(float* c, const float* a, const float* b, const int& len);

/**
 * @brief vector add for 512 bits float
 * @param c array to store
 * @param a,b arrays to read
 * @param len length of array
 */
inline void vadd16f(float* c, const float* a, const float* b, const int& len);