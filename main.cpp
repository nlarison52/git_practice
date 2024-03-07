#include <iostream>

using namespace std;
int primes[] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

int fib(int iterations); //returns the fibonacci number for the given index

void primeFactorization(int number, vector<int> &result);


int main(){
    vector<int> factorPowers;
    int num = 9;

    primeFactorization(num, factorPowers);

    int len = sizeof(factorPowers) / sizeof(factorPowers[0]);

    for (int i = 0; i < 11; i++){
        cout << factorPowers[i] << " : " << primes[i] << endl;
    }

    

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


void primeFactorization(int number, vector<int> &result){
    
    int primeSize = sizeof(primes) / sizeof(primes[0]);
    result.push_back(1);

    int powerCount;
    while (number != 1){
        for (int i = 1; i < primeSize; i++){
            powerCount = 0;
            while (!(number % primes[i])){
                    powerCount ++;
                    number /= primes[i];
            }
            result.push_back(powerCount);
        }
    }
}

