#include "../../intrin_helper.hpp"

#include <iostream>

int main()
{
    using namespace std;

    cout << "the maximum vector length is ";
    VEC_LENGTH vl = checkVectorWidth();
    switch (vl)
    {
    case VEC_LENGTH::VL512:
        cout << "512";
        break;
    case VEC_LENGTH::VL256:
        cout << "256";
        break;
    case VEC_LENGTH::VL128:
        cout << "128";
        break;
    case VEC_LENGTH::VL64:
        cout << "64";
        break;
    default:
        cout << "XX";
        break;
    }
    cout << " bits."<<endl;
    return 0;
}