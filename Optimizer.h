//#include "Network.cpp"
#include "Network.h"
//Abstract optimizer class

class Optimizer {
protected:
	Network* my_network;
	Error_Function getError();
public:
    //TODO:
	//Change the below possibly to include the input of data so that the
	//Optimizer can feed the data to the Network
	//temp implementation for DataFrame
	virtual void epoch(DataFrame data_frame, long num_epochs, double lr) = 0;
	virtual void step(DataRow data_row, double lr) = 0;
};


