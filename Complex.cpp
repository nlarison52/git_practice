#include <iostream>
#include <cmath>


class Complex{
    public: 
    double real;
    double im;
    double mag;
    double dir;

    Complex(double real, double im){
        this->real = real;
        this->im = im;
        this->dir = atan(im / real) * 180 / M_PI;
        this->mag = sqrt(pow(real, 2) + pow(im, 2));
    }
    void dispRect();

    void dispPolar();

    void add(Complex &x);
    void sub(Complex &x);
    void mult(Complex &x);
    void div(Complex &x);

    void updatePolar();
    void updateRect();


};

void Complex::dispRect(){
    std::cout << this->real << " + " << im << "j" << std::endl;
}

void Complex::dispPolar(){
    std::cout << this->mag << " < " << this->dir << std::endl;
}

void add(Complex &x, Complex &y);

void Complex::add(Complex &x){
    this->real += x.real;
    this->im += x.im;
    this->updatePolar();
}

void Complex::sub(Complex &x){
    this->real -= x.real;
    this->im -= x.im;
    this->updatePolar();

}

void Complex::mult(Complex &x){
    this->mag *= x.mag;
    this->dir *= x.dir;
    this->updatePolar();
}

void Complex::div(Complex &x){
    this->mag /= x.mag;
    this->dir -= x.dir;
    this->updatePolar();
}

void Complex::updatePolar(){
    if (this->real){
        this->dir = atan(this->im / this->real) * 180 / M_PI;
    }
    else{
        this->dir = 0;
    }
    this->mag = sqrt(pow(this->real, 2) + pow(this->im, 2));
}

void Complex::updateRect(){
    this->real = this->mag * cos(dir * M_PI / 180);
    this->im = this->mag * sin(dir * M_PI / 180);

}