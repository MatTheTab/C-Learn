#include "SGD.h"
//SGD optimizer class

//TODO: Review and possibly change this whole implementation,
//change getGradient() to make it non-class function

SGD::SGD(Network *new_network){
	this->my_network=new_network;
}

void SGD::setNetwork(Network *new_network){
	this->my_network=new_network;
}

void SGD::epoch(DataFrame data_frame, long num_epochs, double lr){
	long weight_index=0;
	for(long current_epoch=0;current_epoch<num_epochs;current_epoch++){
		for(long current_data_point=0;current_data_point<data_frame.size();current_data_point++){
			this->step(data_frame[current_data_point],lr, weight_index);
			weight_index++;
			if(weight_index>=my_network.getNumOutputWeights()){ weight_index=0;	}
		}
	}
}

void SGD::step(DataRow data_row, double lr, long weight_index){
	//callculate network error
	//weight*=weight at index
	//weight-lr*getGradient()
	//backPropagate()
}

//TODO: Is this even correct(?)
double SGD::getGradient(double network_error,double* weight){
	//TODO: change, possibly idk
	double epsilon=0.0000001;
	*weight+=epsilon;
	double gradient=(getError(my_network)-network_error)/epsilon
	*weight-=epsilon;
	return gradient;
}

void SGD::backPropagate(){
}
