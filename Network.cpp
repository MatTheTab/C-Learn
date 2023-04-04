# include "Network.h"
# include "Layer.cpp"
#include <stdexcept>

//TODO:
//Add some comments here for clarity, so someone else can understand this code

//Network constructor function with no parameters
Network::Network(){
	std::vector<Layer> layers();
}

//Network constructor function with starting vector of Layers
Network::Network(std::vector<Layer> new_layers){
    std::vector<Layer> layers(new_layers.begin(), new_layers.end());
}

//Network constructor function with starting array of Layers
Network::Network(Layer* new_layers){
    long array_size = sizeof(new_layers) / sizeof(new_layers[0]);
    layers = std::vector<Layer>(new_layers, new_layers + array_size);
}

//Network append a single layer function
void Network::append(Layer new_layer){
	layers.push_back(new_layer);
}

//Network append vector of layers function
void Network::append(std::vector<Layer> new_layers){
    layers.insert(layers.end(), new_layers.begin(), new_layers.end());
}

//Network append an array of layers function
void Network::append(Layer* new_layers, long num_new_layers){
	long size_of_array = sizeof(new_layers) / sizeof(new_layers[0]);
    layers.insert(layers.end(), new_layers, new_layers+ size_of_array);
}

//Network insert layer into given position function
void Network::insert(Layer new_layer, long position){
	std::vector<Layer>::iterator insert_position = layers.begin() + position;
    if (insert_position >= layers.begin() && insert_position <= layers.end()){
        layers.insert(insert_position, new_layer);
    } else {
        throw std::out_of_range("Invalid position");
    }
}

//Network insert vector of layers into a given position function
void Network::insert(std::vector<Layer> new_layers, long position){
	std::vector<Layer>::iterator insert_position = layers.begin() + position;
    if (insert_position >= layers.begin() && insert_position <= layers.end()){
        layers.insert(insert_position, new_layers.begin(), new_layers.end());
    } else {
        throw std::out_of_range("Invalid position");
    }
}

//Network insert an array of layers into a given position function
void Network::insert(Layer* new_layers, long position){
		std::vector<Layer>::iterator insert_position = layers.begin() + position;
    if (insert_position >= layers.begin() && insert_position <= layers.end()){
    	long size_of_array = sizeof(new_layers) / sizeof(new_layers[0]);
        layers.insert(insert_position, new_layers, new_layers+size_of_array);
    } else {
        throw std::out_of_range("Invalid position");
    }
}

//Network append a network to the existing one
void Network::appendNetwork(Network new_network){
	
}

//Network insert a network into a given position
void Network::insertNetwork(Network new_network, long position){
	
}
