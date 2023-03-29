# include "Layer.h"
# include "Neuron.cpp"

//Layer constructor function
Layer::Layer(int _num_neurons){
	// Initializing the Layer with set number of neurons
	this->num_neurons=_num_neurons;
	neurons = new Neuron[_num_neurons];
}

//Layer destructor function
Layer::~Layer(){
	//Deleting neurons
    delete[] neurons;
}

//Setting layer loss function
void setLoss(double (*_loss_function)(double)){
	loss_function=_loss_function;
}

//Layer feedForwards() function
//TODO: change later
double Layer::feedForwards(double *inputs){
	for(int i=0;i<num_neurons;i++){
		neurons[i].activate(inputs[i])
	}
}

//Calculating loss
double* getLoss(double *inputs, bool change_neuron_vals){
	double activation_values[num_neurons];
	for(int i=0;i<num_neurons;i++){
		activation_values[i]=neurons[i]->activate();
	}
	double output[num_neurons];
	for(int j=0;j<num_neurons;j++){
		output[j]=loss_function(activation_values,activation_functions[j],num_neurons)
	}
	if(change_neuron_vals){
		for(int k; k<num_neurons;k++){
			//here change the value of neuron
		}
	}
	return output
}

//Layer printing weights function
void Neuron::printWeights(){
	std::cout<<"Printing Weights at Layer: "<<std::endl;
	for(int i=0;i<num_neurons;i++){
		//Printing Individual neuron weights
		neurons[i].printWeights();
	}
}
