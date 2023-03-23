#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <vector>

using namespace std;

//TODO:change later, see: Neuron class .cpp file
extern const int RANDOM_MAX;

template <typename T>
class Neuron {
private:
    int num_weights;
    double* weights;

public:
    Neuron(int n);
    ~Neuron();
    double weighted_sum(double *inputs);
    double activate(double *inputs);
	void printWeights();
};

#endif
