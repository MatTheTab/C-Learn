//#include "Network.cpp"
  #include "Network.h"
int testNetwork() {
	//TODO: fill testing functionality
	Network* test_network= new Network();
	test_network->createInputLayer(5);
	long neurons[] = {3,7,7,9,5};
	Activation_Function functions[] = {linear,relu,relu,tanh_act, tanh_act};
	test_network->createLayers(neurons,functions);
	test_network->createOutputLayer(2,linear,softmax);
}
