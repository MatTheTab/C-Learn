#include <iostream>
#include <cassert>
#include "neuron.h"

using namespace std;

int main() {
    double inputs[] = {1.0, 2.0, 3.0};
    double weights[] = {0.5, 1.0, 1.5};
    int num_weights = 3;
    double expected_output = 7.0;

    Neuron neuron(num_weights, weights);
    double actual_output = neuron.weightedSum(inputs);

    assert(actual_output == expected_output);
    return 0;
}
