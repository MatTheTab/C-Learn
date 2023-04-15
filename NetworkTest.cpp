#include "Network.cpp"

int main() {
	Network* test_network= new Network();
	Layer* input_layer=new Layer();
	test_network.append(input_layer);
	Layer* layer_1=new Layer()
	Layer* layer_2=new Layer()
	Layer* layer_3=new Layer()
	Layer* output_layer= new Layer()
	std::vector<Layer*> layers = {layer_1, layer_2, layer_3};
	test_network.append(layers);
	test_network.append(output_layer);
	//TODO: uncomment and fill
	//input_layer.setWeights();
	//TODO: uncomment and fill
	//Layer* new_layer=new Layer(starting_weights);
	
}
