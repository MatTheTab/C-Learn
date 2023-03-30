#ifndef LAYER_H
#define LAYER_H

#include <iostream>
#include <vector>
#include "Neuron.h"

typedef double (*Loss_Function)(double*, double, int);

//TODO:implement connections between layers (could be at neuron level)
class Layer{
private:
	int num_neurons;
    Neuron* neurons;
	Loss_Function loss_function;
    Layer* next_layer;

public:
    Layer(int num_neurons);
    ~Layer();
    double feedForwards(double *inputs);
    void setLoss(Loss_Function _loss_function);
    double* getLoss(double* inputs, bool change_neuron_vals=true);
	void printWeights();
};

#endif
