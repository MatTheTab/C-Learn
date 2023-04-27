# include "Neuron.h"

//TODO: Later change the RANDOM_MAX to implement common random initialization practices
const int RANDOM_MAX=10;

//Neuron constructor function
Neuron::Neuron(int _num_weights, Activation_Function _activation_function){
	// Initializing the Neuron with a set number of weights
	this->num_weights=_num_weights;
	//TODO: possibly change this later
	this->activation_function=_activation_function;
	weights = new double[num_weights];
    bias=0;
        // Initializing weights randomly
        for (int i = 0; i < num_weights; i++) {
        	//TODO: Later change this to implement common random initialization practices
			weights[i] = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        }
}

//Neuron destructor function
Neuron::~Neuron(){
	//Deleting weights
    delete[] weights;
}

//Neuron setWeights function
void Neuron::setWeights(double* new_weights){
	for(int i=0;i<num_weights;i++){
		weights[i]=new_weights[i];
	}
}

//Neuron setActivationFunction method
void Neuron::setActivationFunction(Activation_Function _activation_function){
	this->activation_function=_activation_function;
}

//Neuron weighted sum function
double Neuron::weightedSum(double *inputs){
	double weighted_sum;
	for(int i=0;i<num_weights;i++){
		weighted_sum+=inputs[i]*weights[i];
	}
	return weighted_sum;
}

//Neuron activation function, uses weighted_sum()
//TODO: review function pointer, possibly subject to change 
void Neuron::activate(double *inputs){
	double weighted_sum=this->weightedSum(inputs);
	this->value=activation_function(weighted_sum);
}

//Neuron printing weights function
void Neuron::printWeights(){
	for(int i=0;i<num_weights;i++){
		std::cout << "Weight " << i << ": " << weights[i] << std::endl;
	}
}

//Neuron printing values function
void Neuron::printValues(){
	std::cout<<"Value= "<<this->value<<std::endl;
}

double* Neuron::getWeights(){
	return weights;
}

//Neuron getValue() function
double Neuron::getValue(){
	return value;
}

//Neuron assign value function
void Neuron::assign_value(double _value){
	this->value=_value;
}
