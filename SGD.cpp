#include "SGD.h"
//SGD optimizer class

SGD::SGD(Network *new_network){
	this->my_network=new_network;
}

void SGD::setNetwork(Network *new_network){
	this->my_network=new_network;
}

void epoch(long num_epochs){
	for(long current_epoch=0;current_epoch<num_epochs;current_epoch++){
		//TODO:
		//fill
	}
}

void step(double lr){
	//TODO
	//implement
	//decide what to do with error calculations
}
