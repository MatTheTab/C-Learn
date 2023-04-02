#include <iostream>
#include <cassert>
#include "Layer.h"
#include "Layer.cpp"

using namespace std;

bool isEqual(double* arr1, double* arr2, int arr_size){
    for(int i=0; i<arr_size; i++){
        if(abs(arr1[i] - arr2[i]) > 0.01){
            return false;
        }
    }
    return true;
}

//TODO: Fix, does not work
int main() {
    double vals[6][5] = {
	{1,1,1,1,1},
	{2,3,-5,7,8}, 
	{1,2.3,5.5,-9,-1000}, 
	{-1,-1,-1,-1,-1}, 
	{0,0,1,0,0}, 
	{0,0,0,0,0}};
	int num_weights=5;
	double expected_outputs[6]={5.5,0,62.85,0,5.5,0};
	
	double** weights;
	weights = new double*[6];
	for(int i=0; i<6; i++){
    	weights[i] = new double[5];
    	for(int j=0; j<5; j++) {
        	weights[i][j] = vals[i][j];
			}
		}
	double inputs[5]={1,2,5.5,-3,0};

    
    Layer* input_layer = new Layer(5);
	Layer* output_layer = new Layer(6,relu,true,input_layer);
	input_layer->setWeights(weights);
	input_layer->inputValues(inputs);
	output_layer->feedForwards();
	assert(isEqual(output_layer->getValues(),expected_outputs,6));
    return 0;
}
