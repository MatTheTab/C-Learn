#include <iostream>
#include <cassert>
#include "ActivationFunctions.cpp"

using namespace std;

	bool isEqual(double x, double y, double epsilon = 0.01){
    	return fabs(x - y) < epsilon;
		}

int testActivationFunctions() {
	int arr_length=7;
    double inputs[] = {0.0, 1.0, 2.0, 3.0, -1.0, -7.5, 3.14};
    double linear_outputs[] = {0.0, 1.0, 2.0, 3.0, -1.0, -7.5, 3.14};
    double relu_outputs[] = {0.0, 1.0, 2.0, 3.0, 0, 0, 3.14};
    double leaky_relu_outputs[] = {0.0, 1.0, 2.0, 3.0, -0.01, -0.075, 3.14}; //for alpha=0.01
    double sigmoid_outputs[] = {0.5, 0.731, 0.881, 0.952, 0.269, 0.0006, 0.958};
    double tanh_outputs[] = {0.0, 0.761, 0.964, 0.996, -0.761, -1.0, 0.998};
    double elu_outputs[] = {0.0, 1.0, 2.0, 3.0, 0.01 * (exp(-1.0) - 1), 0.01 * (exp(-7.5) - 1), 3.14}; //for alpha=0.01
	double swish_outputs[] = {0.0, 0.731, 1.761, 2.857, -0.268, -0.004, 3.017}; // for beta=1
	double gelu_outputs[] = {0.0, 0.841, 1.954, 2.997, -0.158, 0.0, 3.138};
    
    //Testing loop
    for(int i=0;i<arr_length;i++){
    	assert(isEqual(linear_outputs[i],linear(inputs[i])));
    	assert(isEqual(relu_outputs[i],relu(inputs[i])));
   		assert(isEqual(leaky_relu_outputs[i],leakyRelu(inputs[i])));
    	assert(isEqual(sigmoid_outputs[i],sigmoid(inputs[i])));
    	assert(isEqual(tanh_outputs[i],tanh_act(inputs[i])));
    	assert(isEqual(elu_outputs[i],elu(inputs[i])));
    	assert(isEqual(swish_outputs[i],swish(inputs[i])));
    	assert(isEqual(gelu_outputs[i],gelu(inputs[i])));
}
    return 0;
}
