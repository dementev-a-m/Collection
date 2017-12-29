//
// Created by adementev on 21.12.2017.
//

#include <iostream>
#include "Queue.h"
template <typename T>
Queue<T>::Queue() {
    head = 0;
    tail = 0;
    n = 10;
    queue = new T(n);
}
template <typename T>
Queue<T>::~Queue() {
    head = 0;
    tail = 0;
    n = 0;
    delete [] queue;
}
template <typename T>
void Queue<T>::push(T item) {
    if(!tail < n){
        T _queue[n];
        for (int i = 0;i < n; i++){
            _queue[i] = *(queue + i);
        }
        queue = new T[n+10];
        for (int i = 0;i < n;i++){
            *(queue + i) = _queue[i];
        }
        n += 10;

    }
    tail++;
    *(queue+tail) = item;

}
template <typename T>
T Queue<T>::pop() {
    if(!empty()) {
        if (head == 10) {
            head = 0;
            tail = tail - 10;
            T _queue[n - 10];
            for (int i = 10; i < n; i++) {
                *(_queue + i - 10) = *(queue + i);
            }
            n -= 10;
            queue = new T[n];

            for (int i = 0; i < n; i++) {
                *(queue + i) = *(_queue+i);
            }

        }
        return *(queue + head++);
    } else
        std::cout<<"Queue empty "<<std::endl;
    return -1;
}
template <typename T>
int Queue<T>::size() {
    return tail - head;
}
template <typename T>
bool Queue<T>::empty() {
    return tail == head;
}