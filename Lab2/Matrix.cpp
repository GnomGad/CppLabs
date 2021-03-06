#include "Matrix.h"

#include <iostream>
#include <iomanip>

Matrix::Matrix():Matrix(5){
}
Matrix::Matrix(int size_){
    size = size_;
    std::cout<<"Size of array has seted: "<<size_<<std::endl;
    mass = new int*[size];
    for (int i = 0; i < size; i++)
        mass[i] = new int[size];
    std::cout<<"Empty array has created"<<std::endl;
}

Matrix::Matrix(int** mass_,int size_,int* mass1D_){
    this->size = size_;
    this->mass = new int*[size_];
    this->mass1D = nullptr;
    for (int i = 0; i < size_; i++) {
        this->mass[i] = new int[size_];
        for (int j = 0; j < size_; j++) {
            this->mass[i][j] = mass_[i][j];
            }
        }
        
}
Matrix::Matrix(const Matrix& matrix) : Matrix(matrix.mass, matrix.size, matrix.mass1D) {
}

Matrix::Matrix(const Matrix&& matrix) : mass(matrix.mass), size(matrix.size), mass1D(matrix.mass1D) {
}
void Matrix::ArrayInitialization(){
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            mass[i][j] = factorial(i)+factorial(j);

    std::cout<<"Array has initialized"<<std::endl;
}

void Matrix::GetArray(){
for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++)
            std::cout<<std::setw(8)<<mass[i][j];
        std::cout<<std::endl;
    } 
}


int Matrix::factorial(int fact){
    if (fact == 0) 
        return 1;
    else 
        return fact * factorial(fact - 1);
}

int* Matrix::Transformation()
{
     mass1D = new int[10];
    int val =0;
    for (int i = 1; i < size; i+=2)
        for (int j = 0; j < size; j++)
        mass1D[val++] = mass[i][j];
    std::cout<<"Array has Transformated"<<std::endl;

   return mass1D;
}

int Matrix::At(int i, int j) const{
    return mass[i][j];
}

void Matrix::SetAt(int i,int j,int n){
    mass[i][j] = n;
}

Matrix& Matrix::operator++(){
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            mass[i][j]++;
    return *this;
}

Matrix& Matrix::operator--(){
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            mass[i][j]--;
    return *this;
}

Matrix& Matrix::operator++(int a) {
    Matrix tmp{ mass, size,mass1D };
    ++*this;
    return tmp;
}
Matrix& Matrix::operator--(int a){
    Matrix tmp(*this);
    --*this;
    return tmp;
}
Matrix::~Matrix(){
    std::cout << " Matix has been removed" << std::endl;
    delete[] mass1D;
    mass1D = nullptr;

    for (int i = 0; i < size; i++)
        delete[] mass[i];
        
    delete[] mass;
    mass = nullptr;
}