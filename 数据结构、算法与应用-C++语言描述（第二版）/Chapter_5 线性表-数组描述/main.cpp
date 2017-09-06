#include "arrayList.h"
#include "vectorList.h"
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    // linearList<int> *x = (linearList<int>)new arrayList<int>(100);
    arrayList<double> y(100);

    arrayList<char> z;

    arrayList<double> w(y);

    cout << y.capacity() << "\t" << z.capacity() << "\t" << w.capacity() << endl;

    vectorList<int> vecl(20);
    return 0;
}