//
// Created by adementev on 12.12.2017.
//

#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H

#include <iostream>

template <typename T>
class Array{

    int size;
    T* arr;
    int index;
public:
    Array(){
        index = 0;
        this->size = 10;
        arr = new T[size];
    }

    Array(int size){
        index = 0;
        this->size = size;
        arr = new int [size];
    }

    Array(Array<T> & array){
        this -> index = array.index;
        this -> size = array.size;
        arr = new T[size];
        for(int i = 0; i < this-> index;i++)
            *(arr + i)= *(array.arr+i);
    }
    ~Array(){
        delete [] arr;
    }

    T get(int index){
        if (index >= 0 && index < size)
            return *(arr + index);
        else
            std::cout<< "Index goes beyond the array"<<std::endl;
        return -1;
    }

    void set(T item, int index){
        if (index >= 0 && index < this -> index)
            *(arr + index) = item;
        else
            std::cout<< "Index goes beyond the array"<<std::endl;
    }
    void put(T item){
        if ((index + 1) == size){
            T _arr[size];
            for (register int i = 0;i<size;i++){
                _arr[i] = *(arr + i);
            }
            arr = new int[size+10];
            for (int i = 0;i < size;i++){
                *(arr + i) = _arr[i];
            }
            size +=10;
        }
        *(arr + index) = item;
        index++;
    }
    void remove(int index){
        if (index >= 0 && index < this -> index) {
            for (index; index < this -> index; index++)
                *(arr + index-1) = *(arr + index);
            this -> index--;
            if((size - this -> index)>10){
                int _arr[this -> index];
                for (int i = 0;i<this -> index;i++){
                    _arr[i] = *(arr + i);
                }
                arr = new T[size-10];
                for (int i = 0;i < this -> index;i++){
                    *(arr + i) = _arr[i];
                }
                size -=10;
            }
        }
        else
            std::cout<< "Index goes beyond the array"<<std::endl;
    }
    void print(){
        for(int i = 0; i<index;i++)
            std::cout<<*(arr+i)<<' ';
        std::cout<<std::endl;
    }
    void sort(){
        T temp;
        for (int  i = 0; i < (index);i++){
            int min = i;
            for (int j = i;j < (index); j++){
                if (*(arr + min) > *(arr + j)){
                    min = j;
                }
            }
            temp = *(arr + i);
            *(arr + i) = *(arr + min);
            *(arr + min) = temp;
        }
    }

    void insertionSort(){

        register int j, i;
        for (j = 2; j < index; j++){
            T temp = *(arr + j);
            i = j - 1;
            while (i > 0 && *(arr + i) > temp){
                *(arr + i + 1) = *(arr + i);
                -- i;
            }
            *(arr + i + 1) = temp;
        }
    }
    void shellSort(){
        int step = index / 2;
        register int i,j;
        while(step>0){
            for(i = 0; i<(index - step);i++){
                j = i;
                while (j > 0 && *(arr + j) > *(arr + j + step)){
                    T temp = *(arr + j);
                    *(arr+j) = *(arr + j + step);
                    *(arr + j + step) = temp;
                    j--;
                }
            }
            step/=2;
        }
    }

};

#endif //ARRAY_ARRAY_H
