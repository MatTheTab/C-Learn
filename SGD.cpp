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

void SGD::epoch(long num_epochs){
	for(long current_epoch=0;current_epoch<num_epochs;current_epoch++){
		//TODO:
		//fill
	}
}

void SGD::step(double lr){
	//TODO
	//implement
	//decide what to do with error calculations
}

void SGD::getGradient(){
}

void SGD::backPropagate(){
}

void SGD::getLoss(){
}
