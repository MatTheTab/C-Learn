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

void SGD::epoch(long num_epochs, double lr){
	for(long current_epoch=0;current_epoch<num_epochs;current_epoch++){
		this->step(lr);
	}
}

void SGD::step(double lr){
	//getGradient()
	//backPropagate()
}

//TODO: Is this even correct(?)
double SGD::getGradient(){
	//TODO: change, possibly idk
	double epsilon=0.0000001;

}

void SGD::backPropagate(){
}
