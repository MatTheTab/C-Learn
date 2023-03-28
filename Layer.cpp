# include "Layer.h"
# include "Neuron.cpp"

//Layer constructor function
Layer::Layer(int _num_neurons){
	// Initializing the Layer with set number of neurons
	this->num_neurons=_num_neurons;
	neurons = new neuron[_num_neurons];
}

//Layer destructor function
Layer::~Layer(){
	//Deleting neurons
    delete[] neurons;
}

//Setting layer loss function
void setLoss(double (*_loss_function)(double)){
	this->loss_function=_loss_function;
}

//Layer feedForwards() function
//TODO: change later
double Layer::feedForwards(double *inputs){
	for(int i=0;i<num_neurons;i++){
		neurons[i].activate(inputs[i])
	}
	return 1.0
}

//Calculating loss
//TODO: change this, because I do not know what to do with inputs yet
double getLoss(double value){
	double activation_values[num_neurons];
	for(int i=0;i<num_neurons;i++){
		activation_values[i]=neurons[i]->activate();
	}
	getLoss(value, activation_values);
}

//Layer printing weights function
void Neuron::printWeights(){
	std::cout<<"Printing Weights at Layer: "<<std::endl;
	for(int i=0;i<num_neurons;i++){
		//Printing Individual neuron weights
		neurons[i].printWeights();
	}
}
