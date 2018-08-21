#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    *b = *a + *b;
    *a = *b - *a;
    *b = *b - *a;
    cout << "a = " << *a << endl << "b = " << *b << endl;
}
int main()
{
    int a = 1;
    int b = 2;
    swap(&a, &b);
    return 0;
}

