 
#include <iostream>
using namespace std;
int main (){
int a = 5, *p;
a = *p * a;
if (a == *p)
cout << "a es igual a *p" << endl;
else
cout << "a es diferente a *p" << endl;
}
