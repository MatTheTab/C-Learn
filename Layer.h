#ifndef LAYER_H
#define LAYER_H

#include <iostream>
#include <vector>
#include "Neuron.h"

class Layer{
private:
	int num_neurons;
    Neuron* neurons;
	Loss_Function loss_function;
    Layer* prev_layer;

public:
    Layer(long num_neurons, Activation_Function _activation_function=linear, bool add_prev_layer=false, Layer* _prev_layer=NULL);
    ~Layer();
    void inputValues(double *inputs);
    void feedForwards();
    void setLoss(Loss_Function _loss_function);
    double* getLoss(bool change_neuron_vals=true, double* inputs=NULL, bool manual_input=false);
	void printWeights();
	double* getValues();
	double* getWeights();
	int getNumNeurons();
	void setPreviousLayer(Layer* _prev_layer);
	void setWeights(double** new_weights);
};

#endif
