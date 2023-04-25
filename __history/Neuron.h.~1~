#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <vector>
# include "ActivationFunctions.h"
# include "ActivationFunctions.cpp"

//TODO:change later, see: Neuron class .cpp file
extern const int RANDOM_MAX;

typedef double (*Loss_Function)(double*, double, int);
typedef double (*Activation_Function)(double);

class Neuron {
private:
    int num_weights;
    double* weights;
    Activation_Function activation_function;
    double value;

public:
    Neuron(int _num_weights, Activation_Function _activation_function=linear);
    ~Neuron();
    void setWeights(double* new_weights);
    void setActivationFunction(Activation_Function _activation_function);
    double weightedSum(double *inputs);
    void activate(double *inputs);
    void assign_value(double _value);
    void printValues();
	void printWeights();
	double* getWeights();
	double getValue();
};

#endif
