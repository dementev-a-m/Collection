//
// Created by adementev on 21.12.2017.
//

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

template <typename T>
class Queue  {
    T *queue;
    int head;
    int tail;
    int n;
public:
    Queue();

    ~Queue();

    void push(T item);
    T pop();
    int size();

    bool empty();


};


#endif //ARRAY_QUEUE_H
