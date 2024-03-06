#include <iostream>

using namespace std;

int fib(int iterations); //returns the fibonacci number for the given index

int main(){


    

    return 0;
}


int fib(int iterations){
    int x = 0;
    int y = 1; 
    int temp;

    for (int i = 0; i < iterations; i++){
        temp = x;
        x += y; 
        y = temp;
    }
    return x;
}