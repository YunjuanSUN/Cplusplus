#include <iostream>
using namespace std;

int main(){
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
}


/*
Use double for floating-point computations
Use the return value to initialize variable

2.2 Variables
自定义类名用大写字母开头：Sales_item
赋值语句永远改变的是左侧的对象
We can provide an initializer on a variable defined as extern. 
extern int i;
An extern that has an initializer is a definition
extern double pi = 3.1416;


2.3 Compound Types
a reference is just another name for an already existing object.
a reference may be bound only to an object, not to a literal
int &refVal = ival;//a reference must be initialized

int ival = 42;
int *p = &ival; // p holds the address of ival; p is a pointer to ival
double *pd2 = pd; // ok: initializer is a pointer to double
the type of the pointer is used to infer the type of the object to which the pointer points.
int *p = &ival; // p holds the address of ival; p is a pointer to ival
cout << *p; // * yields the object to which p points
*p = 0; // * yields the object; we assign a new value to ival through p
cout << *p; // prints 0
Dereferencing a pointer yields the object to which the pointer points. 
We can assign to that object by assigning to the result of the dereference:

p = &i; // & is used in an expression as the address-of operator
*p = i; // * is used in an expression as the dereference operator
int &r2 = *p; // & is part of the declaration; * is the dereference operator

#References to Pointers
int i = 42;
int *p; // p is a pointer to int
int *&r = p; // r is a reference to the pointer p
r = &i; // r refers to a pointer; assigning &i to r makes p point to i
*r = 0; // dereferencing r yields i, the object to which p points; changes i to 0

#const pointer：指针本身是常量，也就是说指针固定指向该对象
We may store the address of a const object only in a pointer to const:
const double pi = 3.14; 
const double *cptr = &pi;

# Type Aliases
typedef double wages; // wages is a synonym for double
using SI = Sales_item;// SI is a synonym for Sales_item

#The auto Type Specifier
auto item = val1 + val2; // item initialized to the result of val1 + val2

#The decltype Type Specifier
decltype(f()) sum = x; // sum has whatever type f returns
const int ci = 0, &cz = ci;
decltype(cj) y = x; // y has type const int& and is bound to x
decltype(cj) z; // error: z is a reference and must be initialized

*/

