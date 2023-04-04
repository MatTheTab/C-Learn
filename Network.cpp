# include "Network.h"
# include "Layer.cpp"

//Network constructor function with no parameters
Network::Network(){
	
}

//Network constructor function with starting vector of Layers
Network::Network(std::vector<Layer> new_layers){
	
}

//Network constructor function with starting array of Layers
Network::Network(Layer* new_layers, int num_new_layers){
	
}

//Network append a single layer function
void Network::append(Layer new_layer){
	
}

//Network append vector of layers function
void Network::append(std::vector<Layer> new_layers){
	
}

//Network append an array of layers function
void Network::append(Layer* new_layers, int num_new_layers){
	
}

//Network insert layer into given position function
void Network::insert(Layer new_layer, int position){
	
}

//Network insert vector of layers into a given position function
void Network::insert(std::vector<Layer> new_layers, int position){
	
}

//Network insert an array of layers into a given position function
void Network::insert(Layer* new_layers; int position){
	
}

//Network append a network to the existing one
void Network::appendNetwork(Network new_network){
	
}

//Network insert a network into a given position
void Network::insertNetwork(Network new_network, int position){
	
}
