#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <vector>
//#include "Optimizer.h"
#include <layer.h>
#include <list>

//TODO:
// Later add functionality so that you can add a single neuron to a chosen layer

class Network{
private:
	std::list<Layer> layers;
public:
	Network(void);
	Network(std::vector<Layer> new_layers);
	Network(Layer* new_layers);
	Network(std::list<Layer> new_layers);
	std::list<Layer> getLayers();
	void append(Layer new_layer);
	void append(std::vector<Layer> new_layers);
	void append(std::list<Layer> new_layers);
	void append(Layer* new_layers);
	void append(Network* new_network);
	void insert(Layer new_layer, long position);
	void insert(std::vector<Layer> new_layers, long position);
	void insert(std::list<Layer> new_layers, long position);
	void insert(Layer* new_layers, long position);
	void insert(Network* new_network, long position);
	void predict(double* input_data);
	void predict(std::vector<double> input_data);
	void createInputLayer(long num_neurons);
	void createLayer(long num_neurons, Activation_Function _activation_function);
	void createOutputLayer(long num_neurons, Activation_Function _activation_function, Loss_Function _loss_function);
	void createLayers(long* nums_neurons, Activation_Function* activation_functions);
	void createLayers(std::vector<long> nums_neurons, std::vector<Activation_Function> activation_functions);
	void createLayers(std::list<long> nums_neurons, std::list<Activation_Function> activation_functions);
	void createLayers(long* nums_neurons, Activation_Function* activation_functions, long position);
	void createLayers(std::vector<long> nums_neurons, std::vector<Activation_Function> activation_functions, long position);
	void createLayers(std::list<long> nums_neurons, std::list<Activation_Function> activation_functions, long position);
	double* returnPredict(double* input_data);
	double* returnPredict(std::vector<double> input_data);
	double* getOutput();
	double* getLayerWeights(int layer_num);
    long getNumOutputWeights();
	double** getWeights();
};

#endif
