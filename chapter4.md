# Expressions
## Fundamentals
### Order of Evaluation
+ **For operators that do not specify evaluation order, it is an error for an expression to refer to and change the same object**
+ **the << operator makes no guarantees about when or how its operands are evaluated.**
```C++
// note s as a reference to const; the elements aren't copied and can't be changed
for (const auto &s : text) { // for each element in text
    cout << s; // print the current element
// blank lines and those that end with a period get a newline
if (s.empty() || s[s.size() - 1] == '.')
    cout << endl;
else
    cout << " "; // otherwise just separate with a space
}
//we declared s as a reference to const. Because the elements in text are strings, and might be large. 
//By making s a reference, we avoid copying the elements. Because we don’t need to write to the elements.
```
## Increment and Decrement Operators
```C++
int i = 0, j;
j = ++i; // j = 1, i = 1: prefix yields the incremented value

auto pbeg = v.begin();
// print elements up to the first negative value
while (pbeg != v.end() && *beg >= 0)
    cout << *pbeg++ << endl; 
    // print the current value and advance pbeg
    // the statement prints the element to which pbeg originally pointed and increments pbeg.
    // *pbeg++ is equivalent to *(pbeg++)
```
+ **There are two forms of these operators: prefix and postfix**
  + The prefix operators increments (or decrements) its operand and yields the changed object as its result.
  + The postfix operators increment (or decrement) the operand but yield a copy of the original unchanged value as its result
  + The prefix version avoids unnecessary work. The postfix operator must store the original value so that it can return the unincremented value as its result.
  + The cases where it does matter are when one subexpression changes the value of an operand that is used in another subexpression: *beg = toupper(*beg++)
## The Member Access Operators
```C++
string s1 = "a string", *p = &s1;
auto n = s1.size(); // run the size member of the string s1
n = (*p).size(); // run size on the object to which p points
n = p->size(); // equivalent to (*p).size()

假设iter的类型是vector::iterator
*iter++; 返回迭代器所指向的元素，然后迭代器递增。
(*iter)++;不合法。因为vector元素类型是string，没有++操作。
*iter.empty();不合法。这里应该加括号。
iter++->empty();判断迭代器当前元素是否为空，然后迭代器递增。
```
+ **The arrow operator requires a pointer operand and yields an lvalue.**

## The Conditional Operator
```C++
cond ? expr1 : expr2;

finalgrade = (grade > 90) ? "high pass"
: (grade < 60) ? "fail" : "pass";
//we usually must parenthesize the conditional subexpression
```
## Comma Operator
```C++
vector<int>::size_type cnt = ivec.size();
// assign values from size... 1 to the elements in ivec
for(vector<int>::size_type ix = 0;
    ix != ivec.size(); ++ix, --cnt)
    ivec[ix] = cnt;

//这个循环在遍历数组ia，指针ptr和整型ix都是起到一个循环计数的功能
constexpr int size = 5;
int ia[size] = {1,2,3,4,5};
for (int *ptr = ia, ix = 0; ix != size && ptr != ia+size; ++ix, ++ptr) 
{ /* ... */ }
```

