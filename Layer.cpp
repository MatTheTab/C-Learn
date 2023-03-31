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

//Layer function for manual value input(required for first layer of a network)
void Layer::inputValues(double* inputs){
		for(int i=0;i<num_neurons;i++){
		neurons[i].activate(inputs);
	}
}

//Layer feedForwards() function
void Layer::feedForwards(){
	double* prev_layer_output=prev_layer->getValues();
	for(int i=0;i<num_neurons;i++){
		neurons[i].activate(prev_layer_output);
	}
}

//Calculating loss
double* Layer::getLoss(bool change_neuron_vals, double* inputs, bool manual_input){
	double* activation_values= new double[num_neurons];
	double* prev_layer_output=prev_layer->getValues();
	if(manual_input){
		for(int i=0;i<num_neurons;i++){
			//TODO: Fix bug here
			activation_values[i]=neurons[i].activate(inputs);
		}
	}
	else{
		for(int i=0;i<num_neurons;i++){
			//TODO: Fix bug here
			activation_values[i]=neurons[i].activate(prev_layer_output);
		}
	}
	double output[num_neurons];
	for(int j=0;j<num_neurons;j++){
		output[j]=loss_function(activation_values,neurons[j].getValue(),num_neurons);
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

//Layer function for getting values of neurons
double* Layer::getValues(){
	double* neuron_values= new double[num_neurons];
	for(int i=0;i<num_neurons;i++){
		neuron_values[i]=neurons[i].getValue();
	}
	return neuron_values;
}

//Layer function for getting number of neurons
int Layer::getNumNeurons(){
	return num_neurons;
}

//Layer function for setting the previous layer
void Layer::setPreviousLayer(Layer* _prev_layer){
	prev_layer=_prev_layer;
}
