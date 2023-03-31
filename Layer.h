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
    Layer* prev_layer;

public:
    Layer(int num_neurons);
    ~Layer();
    void inputValues(double *inputs);
    void feedForwards();
    void setLoss(Loss_Function _loss_function);
    double* getLoss(bool change_neuron_vals=true, double* inputs=NULL, bool manual_input=false);
	void printWeights();
	double* getValues();
	int getNumNeurons();
	void setPreviousLayer(Layer* _prev_layer);
};

#endif
