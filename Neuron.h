#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <vector>

using namespace std;

extern const int RANDOM_MAX;

template <typename T>
class Neuron {
private:
    int num_weights;
    double* weights;

public:
    Neuron(int n);
    ~Neuron();
    double activate(double *inputs);
	void printWeights();
};

#endif
