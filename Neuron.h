#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <vector>
# include "ActivationFunctions.h"
# include "ActivationFunctions.cpp"

//TODO:change later, see: Neuron class .cpp file
extern const int RANDOM_MAX;

class Neuron {
private:
    int num_weights;
    double* weights;
    double (*activation_function)(double);
    double value;

public:
    Neuron(int _num_weights, double (*_activation_function)(double)=linear);
    ~Neuron();
    void setWeights(double* new_weights);
    void setActivationFunction(double (*_activation_function)(double));
    double weightedSum(double *inputs);
    void activate(double *inputs);
    void assign_value(double _value);
    void printValues();
	void printWeights();
	double getValue();
};

#endif
