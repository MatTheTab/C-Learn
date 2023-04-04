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
	void append(Layer new_layer);
	void append(std::vector<Layer> new_layers);
	void append(Layer* new_layers, int num_new_layers);
	void add(Layer new_layer, int position);
	void add(std::vector<Layer> new_layers, int position);
	void add(Layer* new_layers; int position);
	void appendNetwork(Network new_network);
	void addNetwork(Network new_network, int position);
};

#endif
