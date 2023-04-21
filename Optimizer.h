#include "Network.cpp"
#include "Network.h"
//Abstract optimizer class

class Optimizer {
private:
	Network* my_network;
public:
	Optimizer();
    virtual void step() = 0;
};


