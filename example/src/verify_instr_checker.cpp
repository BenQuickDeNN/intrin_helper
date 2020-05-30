#include "intrin_helper.hpp"

#include <iostream>

int main()
{
    using namespace std;

    cout << "the maximum vector width is ";
    switch (_vec_width)
    {
    case VEC_WIDTH::VL512:
        cout << "512";
        break;
    case VEC_WIDTH::VL256:
        cout << "256";
        break;
    case VEC_WIDTH::VL128:
        cout << "128";
        break;
    default:
        cout << "0";
        break;
    }
    cout << " bits."<<endl;
    return 0;
}