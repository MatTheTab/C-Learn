#include "Optimizer.h"

class SGD: public Optimizer {
public:
	SGD(Network* new_network=NULL);
	void setNetwork(Network* new_network);
	//TODO:
	//Change the below possibly to include the input of data so that the
	//Optimizer can feed the data to the Network
	void epoch(long num_epochs, double lr);
	void step(double lr);
	void getGradient();
	void backPropagate();
    void getLoss();
};