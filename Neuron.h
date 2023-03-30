#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <vector>

//TODO:change later, see: Neuron class .cpp file
extern const int RANDOM_MAX;

class Neuron {
private:
    int num_weights;
    double* weights;
    double (*activation_function)(double);
    double value;

public:
    Neuron(int _num_weights);
    ~Neuron();
    void setWeights(double* new_weights);
    void setActivationFunction(double (*_activation_function)(double));
    double weightedSum(double *inputs);
    void activate(double *inputs);
    void assign_value(double _value);
	void printWeights();
};

#endif
