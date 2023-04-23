//#include "Network.cpp"
#include "Network.h"
//Abstract optimizer class

class Optimizer {
protected:
	Network* my_network;
public:
    //TODO:
	//Change the below possibly to include the input of data so that the
	//Optimizer can feed the data to the Network
	virtual void epoch(long num_epochs) = 0;
	virtual void step(double lr) = 0;
};


