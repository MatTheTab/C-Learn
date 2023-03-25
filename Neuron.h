#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <vector>

//TODO:change later, see: Neuron class .cpp file
extern const int RANDOM_MAX;

class Neuron {
private:
    int num_weights;
    double* weights;
	double (*activation_function)(double);


public:
	Neuron(int _num_weights);
	~Neuron();
	void setActivationFunction(double (*_activation_function)(double));
	double weightedSum(double *inputs);
	double activate(double *inputs);
	void printWeights();
    void setWeights(double * table_of_initial_weights,int num_of_weights);
};

#endif
