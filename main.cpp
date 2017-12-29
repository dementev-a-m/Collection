#include <iostream>
#include <ctime>
#include "Array.h"
#include "Queue.h"

using namespace std;
int main() {


    Array<int> array (10);
    for (int i = 0; i<30;i++)
        array.put(rand());
    int start = clock();

    array.print();
    array.shellSort();


    Array<int> array1 (array);
    array1.print();

//    Queue <int> queue;
//
//    for (int i = 0; i<100;i++)
//        queue.push(i);
//    cout <<" EMPTY "<< queue.empty()<<endl;
//    for (int i = 0; i<99;i++)
//         queue.pop();
//    cout << queue.pop()<<' ';
//    cout << queue.pop()<<' ';
//    cout <<"\n EMPTY "<< queue.empty()<<endl;

    int end = clock();

    cout<<"Time: "<<end - start<<endl;
    return 0;
}