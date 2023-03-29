#ifndef LAYER_H
#define LAYER_H

#include <iostream>
#include <vector>
#include "Neuron.h"

//TODO:implement connections between layers (could be at neuron level)
class Layer{
private:
	int num_neurons;
    Neuron* neurons;
    double (*loss_function)(double*, double, int);
    Layer* next_layer;

public:
    Layer(int num_neurons);
    ~Layer();
    double feedForwards(double *inputs);
    void setLoss(double (*_loss_function)(double));
    double* getLoss(double value, bool change_neuron_vals=true);
	void printWeights();
};

#endif
