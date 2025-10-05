#include <cuda_runtime.h>

__global__ void addKernel(int *a, int *b, int *c) {
    *c = *a + *b;
}

extern "C" void addCuda(int a, int b, int *c) {
    int *d_a, *d_b, *d_c;
    int h_c;

    cudaMalloc(&d_a, sizeof(int));
    cudaMalloc(&d_b, sizeof(int));
    cudaMalloc(&d_c, sizeof(int));

    cudaMemcpy(d_a, &a, sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, &b, sizeof(int), cudaMemcpyHostToDevice);

    addKernel<<<1,1>>>(d_a, d_b, d_c);
    cudaDeviceSynchronize();

    cudaMemcpy(&h_c, d_c, sizeof(int), cudaMemcpyDeviceToHost);

    *c = h_c;

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
}
