#pragma once

#ifndef DIVISOR_H
#define DIVISOR_H

#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class Divisor: public ExpressionEvaluator, public IShuffle {
private:
    
public:
    Divisor();
    Divisor(int);

    double calculate() override;
    void logToScreen() override;
    void logToFile(const std::string& ) override;

    void shuffle() override;
    void lshuffle(size_t, size_t) override;
    ~Divisor() override;
};



#endif