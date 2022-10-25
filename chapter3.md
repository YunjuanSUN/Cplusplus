## String
#### Define and initialization of string
```c++
string s1; // default initialization
s1 is the empty string
string s2 = s1 | string s2 (s1); // s2 is a copy of s1
string s3 = "hiya" | string s3 ("hiya"); // s3 is a copy of the string literal
string s4(10, 'c'); // s4 is cccccccccc
```
+ **拷贝初始化（copy initialization）：使用等号=将一个已有的对象拷贝到正在创建的对象。**
+ **直接初始化（direct initialization）：通过括号给对象赋值。**
#### Using getline to read an entire line
```C++
int main(){
    string line;
          while(getline(cin,line)){ //read input a line at a time until end-of-file
        cout<<line<<endl;
    }
}
```
#### Processing Every Character
```C++
string s("Hello World!!!");
for (auto &c : s)// for every char in s (note: c is a reference){
    c = toupper(c); // c is a reference, so the assignment changes the char in s} 
cout << s << endl;
```
#### Processing Only Some Characters
```C++
string s("some string");
if(!s.empty())
    s[0]=toupper(s[0]);
```
#### Dealing with the Characters in a string
```c++
toupper(c);
tolower(c);
//pay attention that c should be a char rather than string 
```

## vector
#### Header
```C++
#include <vector>
using std::vector;
```
#### Defining and Initializing vectors
```C++
vector<string> svec; // default initialization; svec has no elements
vector<int> ivec2(ivec); // copy elements of ivec into ivec2
vector<int> ivec3 = ivec; // copy elements of ivec into ivec3
vector<string> articles = {"a", "an", "the"};//List Initializing a vector
vector<string> svec(10, "hi!"); //Creating a Specified Number of Elements, ten strings; each element is "hi!"
vector<int> ivec(10); // Value Initialization, each initialized to 0
vector<string> v7{10}; // v7 has ten default-initialized elements
vector<string> v8{10, "hi"}; // v8 has ten elements with value "hi"
```
+ When we use parentheses, we are saying that the values we supply are to be used to construct the object
+ When we use curly braces, {...}, we’re saying that, if possible, we want to list initialize the object.**
#### Adding Elements to a vector
```C++
string word;
vector<string> text; // empty vector
while (cin >> word) {
text.push_back(word); // append word to text
}
```
#### Other vector Operations
```C++
v.empty()
v.size()
v.push_back()
v[n]
v1 = v2
v1 = {a,b,c...}
v1 == v2
v1 != v2
```
#### Access the elements of a vector 
```C++
vector<int> v{1,2,3,4,5,6,7,8,9};
for (auto &i : v) // for each element in v (note: i is a reference)
i *= i; // square the element value
for (auto i : v) // for each element in v
cout << i << " "; // print the element
cout << endl;
```
#### Computing a vector Index
```C++
// count the number of grades by clusters of ten: 0--9, 10--19, . .. 90--99, 100
vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
unsigned grade;
while (cin >> grade) { // read the grades
if (grade <= 100) // handle only valid grades
++scores[grade/10]; // increment the counter for the current cluster
}
```
+ The subscript operator on vector (and string) fetches an existing
element; it does not add an element.
```C++
Read a sequence of words from cin and store the values a vector.
After you’ve read all the words, process the vector and change each word to uppercase. 
Print the transformed elements, eight words to a line.

int main(){
 vector<string> words;
 string word;
 while(cin >> word){
     words.push_back(text);
 }
 for(auto &str:words){
     for(auto &c:str){
         c=toupper(c);
     }
 }
 for(auto i:words){
     cout << i << endl;
 }
 return 0;
}
```
### Iterators
#### Using Iterators
```C++
auto b = v.begin(), e = v.end();
```
#### Iterator Operations
```C++
string s("some string");
if (s.begin() != s.end()) { // make sure s is not empty
auto it = s.begin(); // it denotes the first character in s
*it = toupper(*it); // make that character uppercase
}
```
+ we can dereference an iterator to obtain the element denoted by an iterator
#### Moving Iterators from One Element to Another
```c++
for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
*it = toupper(*it);//we execute ++it to advance the iterator to access the next character in s.
```
+ Iterators use the increment (++) operator to move from one element
to the next.
+ *iter returns a reference to the element denoted by the iterator iter
+ Only a few library types, vector and string being among them, have the subscript operator
+ By routinely using iterators and !=, we don’t have to worry about the precise type of container we’re processing
#### The begin and end Operations
```C++
vector<int> v;
const vector<int> cv;
auto it1 = v.begin(); // it1 has type vector<int>::iterator
auto it2 = cv.begin(); // it2 has type vector<int>::const_iterator
auto it3 = v.cbegin(); // it3 has type vector<int>::const_iterator
```
#### Combining Dereference and Member Access

+ it->mem is a synonym for (* it).mem 
```C++
// print each line in text up to the first blank line
vector<string> text;
for (auto it = text.cbegin();
it != text.cend() && !it->empty(); ++it)
cout << *it << endl;
```
#### Iterator Arithmetic
```c++
//binary search using iterators as follows:
// text must be sorted
// beg and end will denote the range we're searching
auto beg = text.begin(), end = text.end();
auto mid = text.begin() + (end - beg)/2; // original midpoint
// while there are still elements to look at and we haven't yet found sought
while (mid != end && *mid != sought) {
    if (sought < *mid) // is the element we want in the first half?
        end = mid; // if so, adjust the range to ignore the second half
    else // the element we want is in the second half
        beg = mid + 1; // start looking with the element just after mid
    mid = beg + (end - beg)/2; // new midpoint
}
```
### Arrays
#### Defining and Initializing Built-in Arrays
+ Like a vector, an array is a container of unnamed objects of a single type that we access by position.
+ Unlike a vector, arrays have fixed size; we cannot add elements to an array.
+ String literals end with a null character. That null character is copied into the array along with the characters in the literal:
```C++
int arr[10]; // array of ten ints
string a4[3] = {"hi", "bye"}; // same as a4[] = {"hi", "bye", ""}
char a3[] = "C++"; // null terminator added automatically
const char a4[6] = "Daniel"; // error: no space for the null!

int *ptrs[10]; // ptrs is an array of ten pointers to int

int arr[10]; // array of ten ints
int (*Parray)[10] = &arr; // Parray points to an array of ten ints
int (&arrRef)[10] = arr; // arrRef refers to an array of ten ints
int *(&arry)[10] = ptrs; // arry is a reference to an array of ten pointers
```
+ it can be easier to read array declarations from the inside out rather than from right to left.
+ Reading from the inside out makes it much easier to understand the type
#### Accessing the Elements of an Array
+ As in the case of string or vector, it is best to use a range for when we want to traverse the entire array.
+ Using a range for means that we don’t have to manage the traversal ourselves.
```C++
// count the number of grades by clusters of ten: 0--9, 10--19, ... 90--99, 100
unsigned scores[11] = {}; // 11 buckets, all value initialized to 0
unsigned grade;
while (cin >> grade) {
    if (grade <= 100)
        ++scores[grade/10]; // increment the counter for the current cluster
}

for (auto i : scores) // for each counter in scores
cout << i << " "; // print the value of that counter
cout << endl;
```
#### Pointers and Arrays
```C++
string nums[] = {"one", "two", "three"}; // array of strings
string *p = &nums[0]; // p points to the first element in nums
string *p2 = nums; // equivalent to p2 = &nums[0]

int ia[] = {0,1,2,3,4,5,6,7,8,9}; // ia is an array of ten ints
auto ia2(ia); // ia2 is an int* that points to the first element in ia

decltype(ia) ia3 = {0,1,2,3,4,5,6,7,8,9};
ia3[4] = i; // ok: assigns the value of i to an element in ia3
```
+ One such implication is that when we use an array as an initializer for a variable defined using auto (§ 2.5.2, p. 68), the deduced type is a pointer, not an array:
+ It is worth noting that this conversion does not happen when we use decltype
```C++
int arr[] = {0,1,2,3,4,5,6,7,8,9};
int *p = arr; // p points to the first element in arr
++p; // p points to arr[1]

int *e = &arr[10]; // pointer just past the last element in arr
for (int *b = arr; b != e; ++b)
    cout << *b << endl; // print the elements in arr
```
+ **Pointers Are Iterators**
  + pointers to array elements support the same operations as iterators on vectors or strings.
  + Like an off-the-end iterator, an off-the-end pointer does not point to an element.
```C++
int ia[] = {0,1,2,3,4,5,6,7,8,9}; // ia is an array of ten ints
int *beg = begin(ia); // pointer to the first element in ia
int *last = end(ia); // pointer one past the last element in ia
// pbeg points to the first and pend points just past the last element in arr
int *pbeg = begin(arr), *pend = end(arr);
// find the first negative element, stopping if we've seen all the elements
while (pbeg != pend && *pbeg >= 0)
    ++pbeg;
```
+ **The Library begin and end Functions**
  + arrays are not class types, so these functions are not member functions. Instead, they take an argument that is an array:
  + may not dereference or increment an off-the-end pointer.
```C++
constexpr size_t sz = 5;
int arr[sz] = {1,2,3,4,5};
int *ip = arr; // equivalent to int *ip = &arr[0]
int *ip2 = ip + 4; // ip2 points to arr[4], the last element in arr

auto n = end(arr) - begin(arr);//The result of subtracting two pointers is a library type named ptrdiff_t. Like size_t
int *b = arr, *e = arr + sz;
while (b < e) {
// use *b
    ++b;
}
```
+ **Pointer Arithmetic**
  + Pointers that address array elements can use all the iterator operations
  + dereference, increment, comparisons, addition of an integral value, subtraction of two pointers
```C++
int i = ia[2]; // ia is converted to a pointer to the first element in ia
// ia[2] fetches the element to which (ia + 2) points
int *p = ia; // p points to the first element in ia
i = *(p + 2); // equivalent to i = ia[2]

int *p = &ia[2]; // p points to the element indexed by 2
int j = p[1]; // p[1] is equivalent to *(p + 1),
// p[1] is the same element as ia[3]
int k = p[-2]; // p[-2] is the same element as ia[0]
```
+ **Interaction between Dereference and Pointer Arithmetic**
  + We can use the subscript operator on any pointer, as long as that pointer points to an element (or one past the last element) in an array.
  + Remember that when we use an array, we are really using a pointer to the first element in the array.
```C++
const char ca1[] = "A string example";
const char ca2[] = "A different string";
if (strcmp(ca1, ca2) < 0)

string s1 = "A string example";
string s2 = "A different string";
string largeStr = s1 + " " + s2;
```
#### Interfacing to Older Code
+ **Using an Array to Initialize a vector**
  + Modern C++ programs should use vectors and iterators instead of built-in arrays and pointers
  + Use strings rather than C-style array-based character strings
```C++
int int_arr[] = {0, 1, 2, 3, 4, 5};
vector<int> ivec(begin(int_arr), end(int_arr));
```
### Multidimensional Arrays

+ **multidimensional arrays are actually arrays of arrays**
+ **we can more easily understand these definitions by reading them from the inside out.**
+ **In a two-dimensional array, the first dimension is usually referred to as the row and the second as the column.**
#### Initializing the Elements of a Multidimensional Array
```C++
int arr[10][20][30] = {0};

int ia[3][4] = { // three elements; each element is an array of size 4
{0, 1, 2, 3}, // initializers for the row indexed by 0
{4, 5, 6, 7}, // initializers for the row indexed by 1
{8, 9, 10, 11} // initializers for the row indexed by 2

int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
int ia[3][4] = {{ 0 }, { 4 }, { 8 }};
int ix[3][4] = {0, 3, 6, 9};
};
```
#### Subscripting a Multidimensional Array
```C++
// assigns the first element of arr to the last element in the last row of ia
ia[2][3] = arr[0][0][0];
int (&row)[4] = ia[1]; // binds row to the second four-element array in ia

constexpr size_t rowCnt = 3, colCnt = 4;
int ia[rowCnt][colCnt]; // 12 uninitialized elements
// for each row
for (size_t i = 0; i != rowCnt; ++i) {
// for each column within the row
    for (size_t j = 0; j != colCnt; ++j) {
    // assign the element's positional index as its value
    ia[i][j] = i * colCnt + j;
    }
}//it is common to use a pair of nested for loops to process the elements in a multidimensional array:
```
+ **If an expression provides as many subscripts as there are dimensions, we get an element with the specified type.**
+ **If we supply fewer subscripts than there are dimensions, then the result is the inner-array element at the specified index:**
#### Using a Range for with Multidimensional Arrays
```C++
size_t cnt = 0;
for (auto &row : ia) // for every element in the outer array
    for (auto &col : row) { // for every element in the inner array
        col = cnt; // give this element the next value
        ++cnt; // increment cnt
    }
```
+ **To use a multidimensional array in a range for, the loop control variable for
all but the innermost array must be references.**
#### Pointers and Multidimensional Arrays
```C++
int ia[3][4]; // array of size 3; each element is an array of ints of size 4
int (*p)[4] = ia; // p points to an array of four ints
p = &ia[2]; // p now points to the last element in ia

// print the value of each element in ia, with each inner array on its own line
// p points to an array of four ints
for (auto p = ia; p != ia + 3; ++p) {
// q points to the first element of an array of four ints; that is, q points to an int
    for (auto q = *p; q != *p + 4; ++q)
        cout << *q << ' ';
    cout << endl;
}

// p points to the first array in ia
for (auto p = begin(ia); p != end(ia); ++p) {
// q points to the first element in an inner array
    for (auto q = begin(*p); q != end(*p); ++q)
        cout << *q << ' '; // prints the int value to which q points
    cout << endl;
}
```
+ **Because a multidimensional array is really an array of arrays, the pointer type to which the array converts is a pointer to the first inner array.**
####  Type Aliases Simplify Pointers to Multidimensional Arrays
```C++
using int_array = int[4]; // new style type alias declaration;
typedef int int_array[4]; // equivalent typedef declaration; 
// print the value of each element in ia, with each inner array on its own line
for (int_array *p = ia; p != ia + 3; ++p) {
    for (int *q = *p; q != *p + 4; ++q)
        cout << *q << ' ';
    cout << endl;
}
```
+ **We start by defining int_array as a name for the type “array of four ints.**
