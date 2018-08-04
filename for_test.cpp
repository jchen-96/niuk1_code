#include<iostream>
#include<stack>
#include<cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    stack<int> test_stack;
    test_stack.push(1);
    cout<<test_stack.empty()<<endl;
    test_stack.pop();
    cout<<test_stack.empty()<<endl;    
    getchar();
    return 0;
}
