#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <vector>
#include "Layer.h"

//TODO:
// Later add functionality so that you can add a single neuron to a chosen layer

class Network{
private:
	std::vector<Layer> layers;
public:
	Network();
	Network(std::vector<Layer> new_layers);
	Network(Layer* new_layers);
	std::vector<Layer> getLayers();
	void append(Layer new_layer);
	void append(std::vector<Layer> new_layers);
	void append(Layer* new_layers, long num_new_layers);
	void insert(Layer new_layer, long position);
	void insert(std::vector<Layer> new_layers, long position);
	void insert(Layer* new_layers, long position);
	void appendNetwork(Network new_network);
	void insertNetwork(Network new_network, long position);
	void predict(double* input_data);
	void predict(std::vector<double> input_data);
	double* returnPredict(double* input_data);
	double* returnPredict(std::vector<double> input_data);
	double* getOutput();
	double* getLayerWeights();
	double** getWeights();
};

#endif
