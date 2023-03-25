//---------------------------------------------------------------------------

#ifndef ActivationFunctionsH
#define ActivationFunctionsH
//---------------------------------------------------------------------------
double linear(double input);
double relu(double input);
double leakyRelu(double input, double alpha=0.01);
double sigmoid(double input);
double tanh(double input);
double softmax(double *input,double numerator_input, int input_size);
double elu(double input, double alpha=0.01);
double swish(double input, double beta=1);
double gelu(double input);
#endif
