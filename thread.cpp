#include <thread>
#include <iostream>
#include <stdlib.h>
#include <mutex>

using namespace std;
std:: mutex mu;

void function1(int id, int num)
{
     int random=rand()%10000;

     while(random!=num)
     {
        random=rand()%10000;   
      }
}

     mu.lock();
     std::cout <<"Thread "<< id <<" Completed"<< std::endl;
     mu.unlock();

int main(int argc,char* argv[])
{
    int num;
    num = atoi(argv[1]);
    for(int i=0; i<10; i++)
    {
    thread thr[i] = thread(function1,i,num);

    for(int j=0; j<10; j++)
    {
        thr[j].join();
    }
    }
    cout<<"All Threads have finished executing" << endl;
}

