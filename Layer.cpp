# include "Layer.h"
# include "Neuron.cpp"

//Layer constructor function
Layer::Layer(int _num_neurons){
	// Initializing the Layer with set number of neurons
	this->num_neurons=_num_neurons;
	Neuron* neurons = (Neuron*)malloc(sizeof(Neuron)*_num_neurons);
    // calling constructor
    for (int i = 0; i < _num_neurons; i++) {
        neurons[i] = Neuron(1);
    }
}


//Layer destructor function
Layer::~Layer(){
	//Deleting neurons
    delete[] neurons;
}

//Setting layer loss function
void Layer::setLoss(Loss_Function _loss_function){
	loss_function=_loss_function;
}

//Layer feedForwards() function
//TODO: change later
double Layer::feedForwards(double *inputs){
	for(int i=0;i<num_neurons;i++){
		neurons[i].activate(&inputs[i]);
	}
}

//Calculating loss
double* Layer::getLoss(double *inputs, bool change_neuron_vals){
	double* activation_values= new double[num_neurons];
	for(int i=0;i<num_neurons;i++){
		//TODO: placeholder value change once you know how to deal with neuron's outputs
		activation_values[i]=neurons[i].activate(inputs);
	}
	double output[num_neurons];
	for(int j=0;j<num_neurons;j++){
		//TODO: placeholder values, change once you know what to do with neuron's outputs
		output[j]=loss_function(activation_values,10,num_neurons);
	}
	if(change_neuron_vals){
		for(int k; k<num_neurons;k++){
			neurons[k].assign_value(output[k]);
		}
	}
	return output;
}

//Layer printing weights function
void Layer::printWeights(){
	std::cout<<"Printing Weights at Layer: "<<std::endl;
	for(int i=0;i<num_neurons;i++){
		//Printing Individual neuron weights
		neurons[i].printWeights();
	}
}
