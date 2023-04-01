#include <iostream>
#include <cassert>
#include "Layer.h"
#include "Layer.cpp"

using namespace std;

int main() {
    double inputs[] = {2,3,-5,7,8};
    double weights1[] = {1,0,2.3,5.5,-9};
    double weights2[] = {-1,-1,-1,-1,-1};
    double weights3[] = {0,0,1,0,0};
    double weights4[] = {1,0,2.3,5.5,-9};
    double weights5[] = {0,0,0,0,0};
    double weights6[] = {1,1,1,1,1};
    int num_weights = 5;
    
    Layer input_layer = new Layer(5);
    Layer output_layer = new Layer(6,leaky_relu,true,*input_layer);
    return 0;
}
