# include "Neuron.h"

//TODO: Later change the RANDOM_MAX to implement common random initialization practices
const int RANDOM_MAX=10;

//Neuron constructor function
Neuron::Neuron(int _num_weights){
	// Initializing the Neuron with a set number of weights
	this->num_weights=_num_weights
	weights = new double[n];
        // Initializing weights randomly
        for (int i = 0; i < n; i++) {
        	//TODO: Later change this to implement common random initialization practices
            weights[i] = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        }
}

//Neuron destructor function
Neuron::~Neuron(){
	//Deleting weights
    delete[] weights;
}

//Neuron weighted sum function
double Neuron::weighted_sum(double *inputs){
	double weighted_sum;
	for(int i=0;i<n;i++){
		weighted_sum+=inputs[i]*weights[i]
	}
	return weighted_sum
}

//Neuron activation function, uses weighted_sum()
//TODO: review function pointer, possibly subject to change 
double Neuron::activate(double *inputs, double (*activation_function)(double)){
	double weighted_sum=Neuron.weighted_sum()
	return activation_function(weighted_sum)
}

//Neuron printing weights function
void Neuron::printWeights(){
	for(int i=0;i<n;i++){
		std::cout << "Weight " << i << ": " << weights[i] << std::endl;
	}
}
