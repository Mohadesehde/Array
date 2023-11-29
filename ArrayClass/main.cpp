//
//  main.cpp
//  ArrayClass
//
//  Created by Mohadeseh Delavarian on 11/28/20.
//  Copyright © 2020 Mohadeseh Delavarian. All rights reserved.
//

#include <iostream>
using namespace std;

class Array{
    public:
        Array(int x=100);
    
        ~Array(){
            delete [] arr;
        }
    
        void read();
        void print();
        void swap(int , int);
        void reverse();
        int min();
        int max();
        int sum();
        int avg();
        int len();
        bool isfull();
        bool isempty();
        bool search(int);
        bool add(int);
        bool addtosortedA(int);
        void remove(int);
    void insertionsort();
    bool binarysearch(int);
    bool isequall(Array);
    bool isequall(int * , int);
    
    private:
        int *arr,maxsize,size;
};

Array::Array(int x){
    if(x<=0){
        maxsize = 0;
        size = 0;
        arr = NULL;
    }
    else{
        arr = new int[x];
        if(!arr)
            maxsize = 0;
        else
            maxsize = x;
        size = 0;
    }
}

void Array::read(){
    cin>>size;
    for(int i=0;i<size;i++)
        cin>>arr[i];
}

void Array::print(){
    for(int i=0;i<size;i++)
        cout<<arr[i]<<endl;
}

void Array::swap(int a,int b){
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

bool Array::add(int a){
    if(isfull())
        return false;
    arr[size++] = a;
    return true;
}

bool Array::addtosortedA(int a){
    if(isfull())
        return false;
    if(arr[size-1] < a){
        add(a);
        return true;
    }
    for(int i=0;i<size;i++)
        if(arr[i] >= a){
            for(int j=size-1;j>=i;j--)
                arr[j+1] = arr[j];
            arr[i] = a;
            size++;
            break;
        }
    return true;
}

void Array::remove(int a){
    for(int i=0;i<size;i++)
        if(arr[i] == a){
            for(int j=i;j<size-1;j++)
                arr[j] = arr[j+1];
            size--;
        }
}

void Array::reverse(){
    int t;
    for(int i=0;i<size/2;i++){
        t = arr[i];
        arr[i]=arr[size-1-i];
        arr[size-1-i] = t;
    }
}

int Array::min(){
    int mn = arr[0];
    for(int i=0;i<size;i++)
        if(mn > arr[i])
            mn = arr[i];
    return mn;
}

int Array::max(){
    int mx = arr[0];
    for(int i=0;i<size;i++)
        if(mx < arr[i])
            mx = arr[i];
    return mx;
}

int Array::sum(){
    int sm = 0;
    for(int i=0;i<size;i++)
        sm += arr[i];
    return sm;
}

int Array::avg(){
    return sum()/size;
}

int Array::len(){
    return size;
}

bool Array::isfull(){
    if(size == maxsize)
        return true;
    return false;
}

bool Array::isempty(){
    if(size == 0)
        return true;
    return false;
}

bool Array::search(int x){
    for(int i=0;i<size;i++)
        if(arr[i] == x)
            return true;
    return false;
}

void Array::insertionsort()
{
    int key,i;
    for (int j=1;j<size;j++)
    {
        key=arr[j];
        i=j-1;
        while(i>=0 && arr[i]>key)
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
    }
}

bool Array :: binarysearch(int x)
{
    bool f=false;
    int mid,first=0, last=size-1;
    while(first<=last && !f)
    {
        mid=(last+first)/2;
        if (arr[mid]==x)
            f=true;
        else
            if (x<arr[mid])
                last=mid-1;
        else
            if (x>arr[mid])
                first=mid+1;
    }
    return f;
}

bool Array::isequall(Array a)
{
    if(size!= a.size)
        return false;
    for (int i=0;i<size;i++)
     if (arr[i]!= a.arr[i])
         return false;
    return true;
}

bool Array::isequall(int * a, int n)
{
    if(size!= n)
        return false;
    for (int i=0;i<size;i++)
     if (arr[i]!= a[i])
         return false;
    return true;
}
int main()
{
    Array a(20), b(40), c(50);
    
    // Codes
    
    return 0;
}
