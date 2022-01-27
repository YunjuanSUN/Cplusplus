#include <iostream>
using namespace std;
/*
int main()
{
    int sum = 0;
    for (int value = 0; std::cin >> value; )
        sum += value;
    std::cout << sum << std::endl;
    return 0;
}
//when we use an istream as a condition, the effect is to test the state of the stream
//error type: syntax error/type error/declaration error


int main()
{
    // 统计输入中每个值连续出现了多少次
    int currVal = 0, val = 0;
    if (cin >> currVal){
        int cnt = 1;
        while (cin >> val){
            if (val == currVal)
                cnt++;
            else {
                cout << currVal << " occurs "
                          << cnt << " times " << endl;
                currVal = val;
                cnt = 1;
            }
        }
        cout << currVal << " occurs "
                  << cnt << " times " << endl;
    }
    return 0;
}

//Headers from the standard library are enclosed in angle brackets (< >). 
//Those that are not part of the library are enclosed in double quotes (" ")

//exercise1.24
int main(){
    Sales_item previous;
    if(cin>>previous){
        Sales_item later;
        while(cin>>later){
            if(previous.isbn()=later.isbn){
                previous += later;
            }
            else{
                cout<<previous<<endl;
                later = previous;
            }
        }
        cout<<previous<<endl;
    }
    else{
        cerr<<"no data! please input valid data"<<endl;
        return -1
    }
    return 0
}

*/