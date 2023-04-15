# include "Layer.h"
# include "Neuron.cpp"

//TODO: Make it easier to create a Layer
//Layer constructor function
Layer::Layer(int _num_neurons, double (*_activation_function)(double), bool add_prev_layer, Layer* _prev_layer){
	//Initializing the Layer with set number of neurons
	this->num_neurons=_num_neurons;
	Neuron* neurons = (Neuron*)malloc(sizeof(Neuron)*_num_neurons);
    //Calling constructor
    if(add_prev_layer){
    	this->prev_layer=_prev_layer;
    	for (int i = 0; i < _num_neurons; i++){
        	neurons[i] = Neuron(_prev_layer->getNumNeurons(), _activation_function);
			}
	}
	else{
		double new_weights[1]={1.0};
		for (int i = 0; i < _num_neurons; i++) {
		//Declare as input layer
		neurons[i] = Neuron(1, _activation_function);
		neurons[i].setWeights(new_weights);
			}
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
	//Declare initially empty array of activation values for neurons of this layer
	double* activation_values= new double[num_neurons];
	//Initialy empty array of output values of neurons from previous layer
	double* prev_layer_output=prev_layer->getValues();
	//Allow for possibility of manual data insertion into the layer
	if(manual_input){
		for(int i=0;i<num_neurons;i++){
			neurons[i].activate(inputs);
			activation_values[i]=neurons[i].getValue();
		}
	}
	//Default course of action, calculate values for previous layer
	else{
		for(int i=0;i<num_neurons;i++){
			neurons[i].activate(prev_layer_output);
			activation_values[i]=neurons[i].getValue();
		}
	}
	double* output=new double[num_neurons];
	//Apply loss function for all neurons in this layer
	for(int j=0;j<num_neurons;j++){
		output[j]=loss_function(activation_values,neurons[j].getValue(),num_neurons);
	}
	//Allow for possibility of changing neuron's values in this layer
	if(change_neuron_vals){
		for(int k; k<num_neurons;k++){
			neurons[k].assign_value(output[k]);
		}
	}
	delete[] activation_values;
	delete[] prev_layer_output;
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

//Layer function for getting values of weights of neurons
double* getWeights(){
	//TODO:fill
}

//Layer function for getting number of neurons
int Layer::getNumNeurons(){
	return num_neurons;
}

//Layer function for setting the previous layer
void Layer::setPreviousLayer(Layer* _prev_layer){
	prev_layer=_prev_layer;
}

//Layer set weights function
void Layer::setWeights(double** new_weights){
	for(int i=0;i<num_neurons;i++){
		neurons->setWeights(new_weights[i]);
	}
}
