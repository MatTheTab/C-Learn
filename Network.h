#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <vector>
#include "Layer.h"
#include "Optimizer.h"
#include <list>

//TODO:
// Later add functionality so that you can add a single neuron to a chosen layer

class Network{
private:
	std::list<Layer> layers;
	Optimizer* optimizer;
public:
	Network();
	Network(std::vector<Layer> new_layers);
	Network(Optimizer* _optimizer);
	Network(std::vector<Layer> new_layers, Optimizer* _optimizer);
	Network(Layer* new_layers);
	Network(Layer* new_layers, Optimizer* _optimizer);
	Network(std::list<Layer> new_layers);
	Network(std::list<Layer> new_layers, Optimizer* _optimizer);
	void setOptimizer(Optimizer* _optimizer);
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
	double* returnPredict(double* input_data);
	double* returnPredict(std::vector<double> input_data);
	double* getOutput();
	double* getLayerWeights(int layer_num);
	double** getWeights();
};

#endif
