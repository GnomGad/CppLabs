#include <iostream>
#include<ctime>
#include"ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator():ExpressionEvaluator(20){
    std::cout<<"Default length = 20"<<std::endl;
}

ExpressionEvaluator::ExpressionEvaluator(int len){
    length = len;
    setNullOperands();
    std::cout<<"Array has been created, length = "<<len<<std::endl;
}
void ExpressionEvaluator::setNullOperands(){
    operands = new double[length];
    for(int i=0;i<length;i++)
        operands[i]=0;
}
 ExpressionEvaluator::~ExpressionEvaluator(){
    delete[] operands;
    std::cout<<"ExpressionEvaluator has been deleted"<<std::endl;
} 

void ExpressionEvaluator::setOperand(size_t pos,double x){
    if(pos<length){
        operands[pos] = x;
        std::cout<<"Operand "<<x<<" has been set in pos "<<pos<<std::endl;
    }
    else
         std::cout<<"Wrong index"<<std::endl;
}

void ExpressionEvaluator::setOperands(double op[], size_t len){
    delete[] operands;
    length = len;
    operands = new double[length];
    for(int i =0;i<length;i++){
        operands[i] = op[i];
    }
    std::cout<<"Operands has been set, new length  "<<len<<std::endl;
}

void ExpressionEvaluator::setRandomOperands(){
    srand(time(0));
    for(int i=0;i<length;i++)
        operands[i] = rand()%9+1;
}

int ExpressionEvaluator::getLenght(){
    return length;
}

std::string ExpressionEvaluator::getString(char x){
    
    std::string s ="";

    for(int i =0;i<length;i++)
        s+= "Op"+std::to_string(i+1)+" ";
    s+=" : ";
    
    for(int i=0;i<length;i++){
        if(operands[i]<0)
            s+="(";
        s+= std::to_string(operands[i]);
        if(operands[i]<0)
            s+=")";
        s+=" ";
        if(i+1<length)
            s+=x;
        s+=" ";
    }
    s+="-> "+std::to_string(calculate());
    return s;
}

std::string ExpressionEvaluator::getString(char x,char y){
    bool flag = true;
    int ii =1;

    std::string s ="";
    for(int i =0;i<length;i++)
        s+= "Op"+std::to_string(i+1)+" ";
    s+=" : ";

    for(int i=0;i<length;i++){
        if(operands[i]<0)
            s+="(";
        s+=std::to_string(operands[i]);
        s+="/";
        s+=std::to_string(ii++);
        if(operands[i]<0)
            s+=")";
        s+=" ";
        if(i+1<length){
                s+= flag?x:y;
                flag=!flag;
        }   
        s+=" ";
    }
    s+="-> "+std::to_string(calculate());
    return s;
}