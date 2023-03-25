//---------------------------------------------------------------------------

#pragma hdrstop

#include "ActivationFunctions.h"
#include <algorithm>
#include <cmath>

//Linear activation function
double linear(double input){
	return input;
}

//Relu activation function
double relu(double input){
	return std::max(0.0,input);
}

//Leaky Relu activation function
double leakyRelu(double input, double alpha) {
	return std::max(alpha*input,input);
}

//Sigmoid activation function
double sigmoid(double input) {
	return 1.0 / (1.0 + std::exp(-input));
}

//Tanh activation function
double tanh(double input) {
	return std::tanh(input);
}

//Softmax activation function
double softmax(double *input,double numerator_input, int input_size) {
	double denumerator_sum=0;
	for(int i=0;i<input_size;i++){
		denumerator_sum+=std::exp(input[i]);
	}
	return std::exp(numerator_input)/denumerator_sum;
}

//ELU activation function
double elu(double input, double alpha){
	if (input<0){
		return alpha*(std::exp(input)-1);
}
	return input;
}

//Swish activation function
double swish(double input, double beta){
	return input/(1 + std::exp(-beta * input));
}

//GELU activation function
double gelu(double input) {
    const double PI = std::atan(1.0)*4;
    return input * 0.5 * (1.0 + std::tanh(std::sqrt(2.0/PI) * (input + 0.044715 * std::pow(input, 3))));
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
