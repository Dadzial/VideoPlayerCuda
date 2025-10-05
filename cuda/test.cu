#include <cuda_runtime.h>
#include <iostream>

__global__ void addKernel(int a, int b, int *c) {
    if(c != nullptr) {
        *c = a + b;
    }
}


extern "C" int addNumbers() {
    int a = 5;
    int b = 7;
    int c = 0;

    int *d_c;
    cudaMalloc(&d_c, sizeof(int));


    addKernel<<<1, 1>>>(a, b, d_c);


    cudaDeviceSynchronize();


    cudaMemcpy(&c, d_c, sizeof(int), cudaMemcpyDeviceToHost);

    cudaFree(d_c);

    return c;
}

