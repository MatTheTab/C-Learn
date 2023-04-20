#include "Network.cpp"

int main() {
	Network* test_network= new Network();
	test_network->createInputLayer(5);
	long neurons[5] = {3,7,7,9,5};
	Activation_Function functions[5] = {linear,relu,relu,tanh, tanh};
	test_network->createLayers(neurons,functions);
	test_network->createOutputLayer(2,linear,softmax);
}
