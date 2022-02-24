# Statements
## Simple Statements
```C++
// read until we hit end-of-file or find an input equal to sought
while (cin >> s && s != sought)
; // null statement

//Compound Statements (Blocks):
Compound statements are used when the language requires a single statement but
the logic of our program needs more than one.A compound statement, usually referred to as a block
```
## Statement Scope
 
```C++
// find the first negative element
auto beg = v.begin();
while (beg != v.end() && *beg >= 0)
++beg;
if (beg == v.end())
// we know that all elements in v are greater than or equal to zero
```
+ Variables defined in the control structure are visible only within that statement and are out of scope after the statement ends.
+ The value of an object defined in a control structure is used by that structure. Therefore, such variables must be initialized.

## Conditional Statements
+ Each else is matched with the closest preceding unmatched if.
+ Controlling the Execution Path with Braces

```C++
//switch example
unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
char ch;
while (cin >> ch) {
// if ch is a vowel, increment the appropriate counter
switch (ch) {
    case 'a':
        ++aCnt;
        break;
    case 'e':
        ++eCnt;
        break;
    case 'i':
        ++iCnt;
        break;
    case 'o':
        ++oCnt;
        break;
    case 'u':
        ++uCnt;
        break;
    }
}
cout << "Number of vowel a: \t" << aCnt << '\n'
<< "Number of vowel e: \t" << eCnt << '\n'
<< "Number of vowel i: \t" << iCnt << '\n'
<< "Number of vowel o: \t" << oCnt << '\n'
<< "Number of vowel u: \t" << uCnt << endl;

//Control Flow within a switch
unsigned vowelCnt = 0;
// ...
switch (ch)
    {// any occurrence of a, e, i, o, or u increments vowelCnt
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        ++vowelCnt;
        break;
    }

//default label within a switch
switch (ch) {
    case 'a': case 'e': case 'i': case 'o': case 'u':
        ++vowelCnt;
        break;
    default:
        ++otherCnt;
        break;
    }
// if ch is a vowel, increment the appropriate counter
// if a switch ends with a default case that has no work to do
// Then the default label must be followed by a null statement or an empty block
```
+ **case labels must be integral constant expressions**
+ **Omitting a break at the end of a case happens rarely**

## Iterative Statements
```C++
//The while Statement
vector<int> v;
int i;
// read until end-of-file or other input failure
while (cin >> i)
    v.push_back(i);
// find the first negative element
auto beg = v.begin();
while (beg != v.end() && *beg >= 0)
    ++beg;
if (beg == v.end())
// we know that all elements in v are greater than or equal to zero


// The for Statement
for (decltype(s.size()) index = 0;
index != s.size() && !isspace(s[index]); ++index)
    s[index] = toupper(s[index]);


//Multiple Definitions in the for Header
for (decltype(v.size()) i = 0, sz = v.size(); i != sz; ++i)
v.push_back(v[i]);
//In this loop we define both the index, i, and the loop control, sz, in init-statement.


//Range for Statement
vector<int> v = {0,1,2,3,4,5,6,7,8,9};
for (auto &r : v) // for each element in v
    r *= 2; // double the value of each element in v


//Do-while loop
string rsp; // used in the condition; can't be defined inside the do
do {
    cout << "please enter two values: ";
    int val1 = 0, val2 = 0;
    cin >> val1 >> val2;
    cout << "The sum of " << val1 << " and " << val2
        << " = " << val1 + val2 << "\n\n"
        << "More? Enter yes or no: ";
    cin >> rsp;
} while (!rsp.empty() && rsp[0] != 'n');
```

+ **A while loop is generally used when we want to iterate indefinitely, such as when we read input.**
+ **A while is also useful when we want access to the value of the loop control variable after the loop finishes.**
+ **A for header can omit any (or all) of init-statement, condition, or expression.**
+ **In range for loop, expression must represent a sequence, such as a braced initializer list, an array, or an object of a type such as vector or string that has begin and end members that return iterators. use the auto type specifier in declaration. If we want to write to the elements in the sequence, the loop variable must be a reference type.**
+ **We cannot use a range for to add elements to a vector (or
other container), because in a range for, the value of end() is cached.**
## Jump Statements
```C++
//The goto Statement
    goto end;
    int ix = 10; // error: goto bypasses an initialized variable definition
    end:
// error: code here could use ix but the goto bypassed its declaration
        ix = 42;
// backward jump over an initialized variable definition is okay
    begin:
        int sz = get_size();
        if (sz <= 0) {
            goto begin;
        }
```
+ **break/continue/goto/return**
+ **A break statement terminates the nearest enclosing while, do while, for, or switch statement**
+ **A continue statement terminates the current iteration of the nearest enclosing loop and immediately begins the next iteration.**

## Try Blocks and Exception Handling
```C++
//A throw expression
if (item1.isbn() != item2.isbn())
    throw runtime_error("Data must refer to same ISBN");
// if we're still here, the ISBNs are the same
cout << item1 + item2 << endl;


//The try Block
try {
program-statements
} catch (exception-declaration) {
handler-statements
} catch (exception-declaration) {
handler-statements
}

//Writing a Handler
while (cin >> item1 >> item2) {
    try {
        // execute code that will add the two Sales_items
        // if the addition fails, the code throws a runtime_error exception
    }catch (runtime_error err) {
        // remind the user that the ISBNs must match and prompt for another pair
        cout << err.what()
            << "\nTry Again? Enter y or n" << endl;
        char c;
        cin >> c;
        f (!cin || c == 'n')
            break; // break out of the while loop
    }
}
```
+ **The type runtime_error is one of the standard library exception types and is defined in the stdexcept header.** We must initialize a runtime_error by giving it a string or a Cstyle character string. That string provides additional information about the problem.
+ **Standard Exceptions**
  + **The exception header defines the most general kind of exception class named exception.**
  + **The stdexcept header defines several general-purpose exception classes.**
    + exception
    + runtime_error
    + range_error
    + overflow_error
    + underflow_error
    + logic_error
    + domain_error
    + invalid_argument
    + length_error
    + out_of_range
  + **We can only default initialize exception, bad_alloc, and bad_cast objects;** it is not possible to provide an initializer for objects of these exception types.
  + **We can initialize those objects from either a string or a C-style string, but we cannot default initialize them.** When we create objects of any of these other exception types, we must supply an initializer. That initializer is used to provide additional information about the error that occurred.
  + **The exception types define only a single operation named what**.That function takes no arguments and returns a const char that points to a C-style character string
  + The new header defines the **bad_alloc** exception type
  + The type_info header defines the **bad_cast** exception type

## chapter summary
+ while, for, and do while statements, which provide iterative execution
+ if and switch, which provide conditional execution.
+ continue, which stops the current iteration of a loop.
+ break, which exits a loop or switch statement.
+ try and catch, which define a try block enclosing a sequence of statements that might throw an exception. The catch clause(s) are intended to handle the exception(s) that the enclosed code might throw.
+ throw expression statements, which exit a block of code, transferring control to an associated catch clause.
+ return, which stops execution of a function.