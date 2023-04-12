#include "Network.h"
#include "Layer.cpp"
#include <stdexcept>
#include <algorithm>
#include <iterator>

//TODO:
//Add some comments here for clarity, so someone else can understand this code
//implement constructor with addition of layer insertion through list
//Change all Methods so they work for a list

//Network constructor function with no parameters
Network::Network(){
	std::list<Layer> layers;
}

//Network constructor function with starting vector of Layers
Network::Network(std::vector<Layer> new_layers){
    std::list<Layer> layers(new_layers.begin(), new_layers.end());
}

//Network constructor function with starting optimizer parameter
Network::Network(Optimizer* _optimizer){
	this->optimizer=_optimizer;
}

//Network constructor function with starting vector of layers and optimizer parameters
Network::Network(std::vector<Layer> new_layers, Optimizer* _optimizer){
	std::list<Layer> layers(new_layers.begin(), new_layers.end());
	this->optimizer=_optimizer;
}

//Network constructor function with starting array of Layers parameter
Network::Network(Layer* new_layers){
    long array_size = sizeof(new_layers) / sizeof(new_layers[0]);
    layers = std::list<Layer>(new_layers, new_layers + array_size);
}

//Network constructor function with starting array of layers and optimizer parameters
Network::Network(Layer* new_layers, Optimizer* _optimizer){
	long array_size = sizeof(new_layers) / sizeof(new_layers[0]);
    layers = std::list<Layer>(new_layers, new_layers + array_size);
    this->optimizer=_optimizer;
}

//Network constructor function with starting linked list parameter
Network::Network(std::list<Layer> new_layers){
	layers = new_layers;
}

//Network constructor function with starting linked list and oprimizer parameters
Network::Network(std::list<Layer> new_layers, Optimizer* _optimizer){
	this->layers = new_layers;
	this->optimizer=_optimizer;
}

//Network function for setting or changing the optimizer
void Network::setOptimizer(Optimizer* _optimizer){
	this->optimizer=_optimizer;
}

//Network getLayers() function for returning all layers present in a Network
std::vector<Layer> getLayers(){
	//TODO:
	//Fix bug here
	//return layers;
}

//Network append a single layer function
void Network::append(Layer new_layer){
	layers.push_back(new_layer);
}

//Network append vector of layers function
void Network::append(std::vector<Layer> new_layers){
    layers.insert(layers.end(), new_layers.begin(), new_layers.end());
}

//Network append list of layers function
void Network::append(std::list<Layer> new_layers){
	layers.insert(layers.end(), new_layers.begin(), new_layers.end());
}

//Network append an array of layers function
void Network::append(Layer* new_layers){
	long size_of_array = sizeof(new_layers) / sizeof(new_layers[0]);
    layers.insert(layers.end(), new_layers, new_layers+ size_of_array);
}

//Network append a network to the existing one
void Network::append(Network *new_network){
	//TODO: Fix bug here
	std::list<Layer> layers_to_add=new_network->getLayers();
	this->append(layers_to_add);
}

//Network insert layer into given position function
void Network::insert(Layer new_layer, long position){
	//Find insert position with respect to layers starting position
	std::list<Layer>::iterator it = layers.begin();
	std::advance(it, position);
    if (it != layers.end()){
        layers.insert(it, new_layer);
    } else {
    	//Error cuased by invalid insertion position
        throw std::out_of_range("Invalid position");
    }
}

//Network insert vector of layers into a given position function
void Network::insert(std::vector<Layer> new_layers, long position){
	//Find insert position with respect to layers starting position
	std::list<Layer>::iterator it = layers.begin();
	std::advance(it, position);
    if (it != layers.end()){
        layers.insert(it, new_layers.begin(),new_layers.end());
    } else {
    	//Error cuased by invalid insertion position
        throw std::out_of_range("Invalid position");
    }
}

//Network insert list of layers into a given position function
void Network::insert(std::list<Layer> new_layers, long position){
	//Find insert position with respect to layers starting position
	std::list<Layer>::iterator it = layers.begin();
	std::advance(it, position);
    if (it != layers.end()){
        layers.insert(it, new_layers.begin(),new_layers.end());
    } else {
    	//Error cuased by invalid insertion position
        throw std::out_of_range("Invalid position");
    }
}

//Network insert an array of layers into a given position function
void Network::insert(Layer* new_layers, long position){
	//Find insert position with respect to layers starting position
	std::list<Layer>::iterator it = layers.begin();
	std::advance(it, position);
    if (it != layers.end()){
        long size_of_array = sizeof(new_layers) / sizeof(new_layers[0]);
    	layers.insert(it, new_layers, new_layers+ size_of_array);
    } else {
    	//Error cuased by invalid insertion position
        throw std::out_of_range("Invalid position");
    }
}

//Network insert a network into a given position
void Network::insert(Network *new_network, long position){
	//TODO: Fix bug here
	std::list<Layer> layers_to_add=new_network->getLayers();
	this->insert(layers_to_add,position);
}

//Network function responsible for passing input_data array into the function, the function does not return anything but 
//automatically updates values of all neurons according to values dictated by getLoss() and activate()
//functions defined at layer level
void Network::predict(double* input_data){
	this->layers.front().inputValues(input_data);
    std::list<Layer>::iterator it = layers.begin();
	for(int i=1;this->layers.size()-2;i++){
		it->feedForwards();
		it++;
	}
	it++;
	it->getLoss(true);
}

//Network function responsible for passing input_data vector into the function, the function does not return anything but 
//automatically updates values of all neurons according to values dictated by getLoss() and activate()
//functions defined at layer level
void Network::predict(std::vector<double> input_data){
	double* input_array = new double(input_data.size());
	this->predict(input_array);
}

//Network function responsible for passing input_data array into the function and returning an array corresponding to output values present
//at the last layer of neural network, automatically updates values of all neurons according to values dictated by getLoss() and activate()
//functions defined at layer level
double* Network::returnPredict(double* input_data){
	this->layers.front().inputValues(input_data);
    std::list<Layer>::iterator it = layers.begin();
	for(int i=1;this->layers.size()-2;i++){
		it->feedForwards();
		it++;
	}
	it++;
	return it->getLoss(true);
}

//Network function responsible for passing input_data vector into the function and returning an array corresponding to output values present
//at the last layer of neural network, automatically updates values of all neurons according to values dictated by getLoss() and activate()
//functions defined at layer level
double* Network::returnPredict(std::vector<double> input_data){
	double* input_array = new double(input_data.size());
	return this->returnPredict(input_array);	
}

//Network function for getting the currently last saved values for the output layer of the neural network
double* Network::getOutput(){
	return this->layers.back().getValues();
}

//Network function for returning Layer-level weights from a Network
double* Network::getLayerWeights(int layer_num){
//TODO:fill
}

//Network function for getting all weights present in a Network
double** Network::getWeights(){
//TODO: Fill	
}
