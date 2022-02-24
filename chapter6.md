# Functions
## 6.1 Function Basics
```C++
//Calling a Function
int fact(int val)
    {
        int ret = 1; // local variable to hold the result as we calculate it
        while (val > 1){
            ret *= val--;
        } // assign ret * val to ret and decrement val
        return ret; // return the result
    }
int main()
    {
    int j = fact(5);
    cout<< "5! is " << j <<endl;
    return 0;
    }
```
## 6.2 Argument Passing
**Using References to Avoid Copies**
```C++
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
```
**Array Parameters**
```C++
//Using a Marker to Specify the Extent of an Array
void print(const char *cp)
{
    if (cp) // if cp is not a null pointer
        while (*cp) // so long as the character it points to is not a null
character
        cout << *cp++; // print the character and advance the pointer
}

//Using the Standard Library Conventions
void print(const int *beg, const int *end)
{
    // print every element starting at beg up to but not including end
    while (beg != end)
        cout << *beg++ << endl; // print the current element
                                // and advance the pointer
}
int j[2] = {0, 1};
// j is converted to a pointer to the first element in j
// the second argument is a pointer to one past the end of j
print(begin(j), end(j)); // begin and end functions

//Explicitly Passing a Size Parameter
// const int ia[] is equivalent to const int* ia
// size is passed explicitly and used to control access to elements of ia
void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i) {
        cout << ia[i] << endl;
    }
}
int j[] = { 0, 1 }; // int array of size 2
print(j, end(j) - begin(j));

//Array Reference Parameters
// ok: parameter is a reference to an array; the dimension is part of the type
void print(int (&arr)[10])
{
    for (auto elem : arr)
        cout << elem << endl;
}

// matrix points to the first element in an array whose elements are arrays of ten ints
void print(int (*matrix)[10], int rowSize) { /* . . . */ }

int *matrix[10]; // array of ten pointers
int (*matrix)[10]; // pointer to an array of ten ints
```
+ **Array Parameters**
  + Using a Marker to Specify the Extent of an Array
  + Using the Standard Library Conventions
  + Explicitly Passing a Size Parameter
  + Array Parameters and const
  + Array Reference Parameters
  + Passing a Multidimensional Array
+ **We cannot copy an array and when we use an array it is (usually) converted to a pointer.**
+ **when we pass an array to a function, we are actually passing a pointer to the array’s
first element**
+ **When a function does not need write access to the array elements, the array parameter should be a pointer to const.**
+ **we can define a parameter that is a reference to an array.**

## 6.3 Return Types and the return Statement
**6.3.2. Functions That Return a Value**
```C++
// incorrect return values, this code will not compile
bool str_subrange(const string &str1, const string &str2)
{
    // same sizes: return normal equality test
    if (str1.size() == str2.size())
        return str1 == str2; // ok: == returns bool
    // find the size of the smaller string; conditional operator, see § 4.7 (p. 151)
    auto size = (str1.size() < str2.size())
                ? str1.size() : str2.size();
    // look at each element up to the size of the smaller string
    for (decltype(size) i = 0; i != size; ++i) {
        if (str1[i] != str2[i])
            return; // error #1: no return value; compiler should detect this error
    }
    // error #2: control might flow off the end of the function without a return
    // the compiler might not detect this error
}

//Recursion
//calculate val!, which is 1 * 2 * 3 . . . * val
int factorial(int val)
{
    if (val > 1)
        return factorial(val-1) * val;
    return 1;
}
```
**6.3.3. Returning a Pointer to an Array**
+ **Use a type alias**
+ **Using a Trailing Return Type**
+ **Using decltype**
```C++
//Use a type alias
typedef int arrT[10]; // arrT is a synonym for the type array of ten ints
using arrtT = int[10]; // equivalent declaration of arrT; see § 2.5.1 (p. 68)
arrT* func(int i); // func returns a pointer to an array of five ints

//Declaring a Function That Returns a Pointer to an Array
int arr[10]; // arr is an array of ten ints
int *p1[10]; // p1 is an array of ten pointers
int (*p2)[10] = &arr; // p2 points to an array of ten ints

//The form of a function that returns a pointer to an array is:
Type (*function(parameter_list))[dimension]
//As a concrete example, the following declares func without using a type alias:
int (*func(int i))[10];

//Using a Trailing Return Type
auto func(int i) -> int(*)[10];

//Using decltype
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
// returns a pointer to an array of five int elements
decltype(odd) *arrPtr(int i)
{
    return (i % 2) ? &odd : &even; // returns a pointer to the array
}
```
## Features for Specialized Uses
**6.5.1. Default Arguments**
```C++
```
**6.5.2. Inline and constexpr Functions**
```C++
```
**6.5.3 Aids for Debugging**
```C++
```
+ ****
+ ****
+ ****
## Function Matching
```C++
```
+ ****
+ ****
+ ****
+ ****
+ ****
## Pointers to Functions
```C++
// pf points to a function returning bool that takes two const string references
bool (*pf)(const string &, const string &); // uninitialized

//Using Function Pointers
pf = lengthCompare; // pf now points to the function named lengthCompare
pf = &lengthCompare; // equivalent assignment: address-of operator is optional

//Use a pointer to a function to call the function
bool b1 = pf("hello", "goodbye"); // calls lengthCompare
bool b2 = (*pf)("hello", "goodbye"); // equivalent call
bool b3 = lengthCompare("hello", "goodbye"); // equivalent call

//Pointers to Overloaded Functions
//The type of the pointer must match one of the overloaded functions exactly:
void ff(int*);
void (*pf1)(unsigned int) = ff;

//Function Pointer Parameters
// third parameter is a function type and is automatically treated as a pointer to function
void useBigger(const string &s1, const string &s2,
bool pf(const string &, const string &));
// equivalent declaration: explicitly define the parameter as a pointer to function
void useBigger(const string &s1, const string &s2,
bool (*pf)(const string &, const string &));
// automatically converts the function lengthCompare to a pointer to function
useBigger(s1, s2, lengthCompare);


```
+ ****
+ ****
+ ****
+ ****
+ ****
## Chapter Summary
```C++
```
+ ****
+ ****
+ ****
+ ****
+ ****