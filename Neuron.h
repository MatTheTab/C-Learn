#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Neuron {
private:
    int n;
    double* weights;

public:
    Neuron(int n);
    ~Neuron();
    double activate(double *inputs);
	void printWeights();
};

#endif
