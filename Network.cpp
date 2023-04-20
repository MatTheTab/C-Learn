#include "Network.h"
#include "Layer.cpp"
#include <stdexcept>
#include <algorithm>
#include <iterator>

//TODO:
//Add some comments here for clarity, so someone else can understand this code
//implement constructor with addition of layer insertion through list
//Make it easier to create a network for the user
//Fix unexpected bug

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
std::list<Layer> Network::getLayers(){
	return layers;
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

//Network function responsible for creating and adding an input layer of specified size to the Network
void Network::createInputLayer(long num_neurons){
	Layer* input_layer = new Layer(num_neurons,linear,false, NULL);
	this->append(input_layer);
}

//Network function responsible for creating and adding a layer with specified activation function and number of neurons
void Network::createLayer(long num_neurons, Activation_Function _activation_function){
	Layer* new_layer = new Layer(num_neurons, _activation_function, true, &(this->layers.back()));
	this->append(new_layer);
}

//Network function responsible for creating and adding an output layer with specified number of neurons,
//activation and loss functions
void Network::createOutputLayer(long num_neurons, Activation_Function _activation_function, Loss_Function _loss_function){
	Layer* output_layer = new Layer(num_neurons, _activation_function, true, &(this->layers.back()));
	output_layer->setLoss(_loss_function);
	this->append(output_layer);
}

//Network function responsible for creating and adding multiple layers based on arrays of specified 
//numbers of neurons and activation functions
void Network::createLayers(long* nums_neurons, Activation_Function* activation_functions){
	long num_layers=sizeof(nums_neurons) / sizeof(nums_neurons[0]);
	if(num_layers==0){
		throw std::runtime_error("Empty array passed as argument.");
	}
	if (num_layers != sizeof(activation_functions) / sizeof(activation_functions[0])) {
        throw std::runtime_error("Number of elements in nums_neurons and activation_functions arrays are not the same.");
    }
	for(int i=0;i<num_layers;i++) {
		Layer* new_layer = new Layer(nums_neurons[i], activation_functions[i], true, this->layers.end());
		this->append(new_layer);
	}
}

//Network function responsible for creating and adding multiple layers based on vectors of specified 
//numbers of neurons and activation functions
void Network::createLayers(std::vector<long> nums_neurons, std::vector<Activation_Function> activation_functions){
	if(nums_neurons.size()==0){
		throw std::runtime_error("Empty vector passed as argument.");
	}
	if(nums_neurons.size()!=activation_functions.size()){
		throw std::runtime_error("Number of elements in nums_neurons and activation_functions vectors are not the same.");
	}
	for(int i=0;i<nums_neurons.size();i++){
		Layer* new_layer = Layer(nums_neurons.get(i), activation_functions.get(i),true,this->layers.end());
		this->append(new_layer);
	}
}

//Network function responsible for creating and adding multiple layers based on lists of specified 
//numbers of neurons and activation functions
void Network::createLayers(std::list<long> nums_neurons, std::list<Activation_Function> activation_functions){
	if(nums_neurons.size()==0){
		throw std::runtime_error("Empty list passed as argument.");
	}
	if(nums_neurons.size()!=activation_functions.size()){
		throw std::runtime_error("Number of elements in nums_neurons and activation_functions lists are not the same.");
	}
	std::list<Activation_Function>::iterator it_2=activation_functions.end();
	for (std::list<long>::iterator it = nums_neurons.begin(); it != nums_neurons.end(); ++it){
    	Layer* new_layer = Layer(it, it_2,true,this->layers.end());
    	this->append(new_layer);
    	it_2++;
	}
}

//Network function responsible for creating and adding multiple layers based on arrays of specified 
//numbers of neurons and activation functions and inserting them into specified position
void Network::createLayers(long* nums_neurons, Activation_Function* activation_functions, long position){
	long num_layers=sizeof(nums_neurons) / sizeof(nums_neurons[0]);
	if(num_layers==0){
		throw std::runtime_error("Empty array passed as argument.");
	}
	if (num_layers != sizeof(activation_functions) / sizeof(activation_functions[0])) {
        throw std::runtime_error("Number of elements in nums_neurons and activation_functions arrays are not the same.");
    }
    if (position<0 || position>=this->layers.size()){
    	throw std::out_of_range("Invalid position");
	}
	//get insertion layer
	std::list<Layer>::iterator it;
	for (it = this->layers.begin(); it != this->position; ++it){}
	//insert first layer
	Layer* new_layer = new Layer(nums_neurons[0], activation_functions[0], true, it);
	this->insert(new_layer,position);
	it++;
	//insert remaining layers
	for(int i=1;i<num_layers;i++) {
		Layer* new_layer = new Layer(nums_neurons[i], activation_functions[i], true, it);
		this->insert(new_layer,position);
		it++;
	}
}

//Network function responsible for creating and adding multiple layers based on vectors of specified 
//numbers of neurons and activation functions and inserting them into specified position
void Network::createLayers(std::vector<long> nums_neurons, std::vector<Activation_Function> activation_functions, long position){
	if(nums_neurons.size()==0){
		throw std::runtime_error("Empty vector passed as argument.");
	}
	if(nums_neurons.size()!=activation_functions.size()){
		throw std::runtime_error("Number of elements in nums_neurons and activation_functions vectors are not the same.");
	}
    if (position<0 || position>=this->layers.size()){
    	throw std::out_of_range("Invalid position");
	}
	//get insertion layer
	std::list<Layer>::iterator it;
	for (it = this->layers.begin(); it != this->position; ++it){}
	//insert first layer
	Layer* new_layer = new Layer(nums_neurons.get_allocator(0), activation_functions.get(0), true, it);
	this->insert(new_layer,position);
	it++;
	//insert remaining layers
	for(int i=1;i<nums_neurons.size();i++){
		Layer* new_layer = Layer(nums_neurons.get(i), activation_functions.get(i),true,it);
		this->insert(new_layer, position);
		it++;
	}
}

//Network function responsible for creating and adding multiple layers based on lists of specified 
//numbers of neurons and activation functions and inserting them into specified position
void Network::createLayers(std::vector<long> nums_neurons, std::vector<Activation_Function> activation_functions, long position){
	if(nums_neurons.size()==0){
		throw std::runtime_error("Empty list passed as argument.");
	}
	if(nums_neurons.size()!=activation_functions.size()){
		throw std::runtime_error("Number of elements in nums_neurons and activation_functions lists are not the same.");
	}
    if (position<0 || position>=this->layers.size()){
    	throw std::out_of_range("Invalid position");
	}
	//get insertion layer
	std::list<Layer>::iterator it;
	for (it = this->layers.begin(); it != this->position; ++it){}
	//insert first layer
	std::list<long>::iterator it_neurons=nums_neurons.begin();
	std::list<Activation_Function>::iterator it_functions=activation_functions.begin();
	Layer* new_layer = new Layer(it_neurons, it_functions, true, it);
	this->insert(new_layer,position);
	it++;
	it_neurons++;
	it_functions++;
	//insert remaining layers
	for(int i=1;i<nums_neurons.size();i++){
		Layer* new_layer = Layer(it_neurons, it_functions,true,it);
		this->insert(new_layer, position);
		it++;
		it_neurons++;
		it_functions++;
	}
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
