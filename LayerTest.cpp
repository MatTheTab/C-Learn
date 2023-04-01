#include <iostream>
#include <cassert>
#include "Layer.h"
#include "Layer.cpp"

using namespace std;

int main() {
    double weights[6][5] = {
	{1,1,1,1,1},
	{2,3,-5,7,8}, 
	{1,0,2.3,5.5,-9}, 
	{-1,-1,-1,-1,-1}, 
	{0,0,1,0,0}, 
	{0,0,0,0,0}};
    int num_weights = 5;
    
    Layer* input_layer = new Layer(5);
	Layer* output_layer = new Layer(6,relu,true,input_layer);
	input_layer->setWeights(weights)
	input_layer.inputValues(inputs);
    return 0;
}
