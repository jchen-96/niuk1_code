// 栈和队列的相互转化

#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>


//用两个栈实现队列
class twoStackQueue
{
  private:
    stack<int> data;
    stack<int> help;

  public:
    twoStackQueue()
    {
        data();
        help();
    }

    void push(int ele){
        data.push(ele);
    }

    void pop(){
        if(help.empty()){
            while(!data.empty()){
                help.push(data.top());
                data.pop();
            }
        }
        help.pop();
    }
};

//用两个队列实现栈
class twoQueueStack{
    private:
    queue<int> data;
    queue<int> help;

    public:
    twoQueueStack(){
        data();
        help();
    }
    void push(int ele){
        data.
    }
};