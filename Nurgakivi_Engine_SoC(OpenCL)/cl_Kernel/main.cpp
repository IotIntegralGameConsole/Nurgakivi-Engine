#include <CL/cl.h>
#include <CL/opencl.h>
#include <iostream>

cl_kernel.cl:
    _kernel void cl_kernel(_global const float *a,
                              _global const float *b,
                              _global float *result)

{
    int gid = get_global_id(0);

    result[gid] = a[gid] + b[gid];
}

cl_kernel.cpp:

int main (int argc, char** argv)
{
    cl_context context =0;
    cl_commmand_queue commandQueue = 0;
    cl_program program = 0;
    cl device_id device = 0;
    cl_kernel kernel = 0;
    cl_mem memObjects[3] ={0,0,0};
    cl_int errNum;

    // Create OpenCL Text First Using Enable Platform
    context = CreateContext();
    if(context == NULL)
    {
        cerr << "Failed to create OpenCL context." << endl;
        return 1;
}

// about First Enable Device from OpenCL Text
// Create Instruction Queue
commandQueue = CreateCommandQueue(context, &device);
if (commandQueue == NULL)
{
    Cleanup(context, commandQueue, program, kernel, memObjects);
    return 1;
}

// Create OpenCL Program from HelloWorld.cl Kernel source
program = CreateProgram(context, device, "Start! CL Kernel.cl");
if(program == NULL)
{
    Cleanup(context, commandQueue, program, kernel, memObjects);
    return 1;
}

// Create OpenCL Kernel
kernel = clCreateKernel(program, "start_cl_kernel", NULL);
if(kernel == NULL)
{
    cerr << "Failed to create kernel" << endl;
    Cleanup(context, commandQueue, program, kernel, memObjects);
    return 1;
}


// Create Usage Memory Object in Kernel
// Firstly, Saving Factors about Kernel
// Create Host Memory Array
float result[ARRAY_SIZE];
float a[ARRAY_SIZE];
float b[ARRAY_SIZE];
for (int i = 0; i < ARRAY_SIZE; i++)
{
    a[i] = i;
    b[i] = i * 2;
}

if (!CreateMemObjects(context, memObjects, a, b))
{
    Cleanup(context, commandQueue, program, kernel, memObjects);
    return 1;
}

// Setting to Kernel Factor
errNum = clSetKernelArg(kernel, 0,
                        sizeof(cl_mem), &memObjects[0]);
errNum = clSetKernelArg(kernel, 1, sizeof(cl.mem),
                        &memObjects[1]);
errNum = clSetKernelArg(kernel, 2, sizeof(cl.mem),
                        &memObjects[2]);
if (errNum != CL_SUCCESS)
{
    cerr << "Error setting kernel arguments." << endl;
    Cleanup(context, commandQueue, program, kernel, memObjects);
    return 1;
}

size_t globalWorkSize[1] = {ARRAY_SIZE};
size_t localWorkSize[1] = { 1 };

// Put in Queue for Running
errNum = clEnqueueNDRangeKernel(commandQueue, kernel, 1, NULL, globalWorkSize, localWorkSize, 0, NULL, NULL);

if (errNum != CL_SUCCESS)
{
    cerr << "Error queuing kernel for execution." endl;
    Cleanup(context, commandQueue, program, kernel, memObjects);
    return 1;
}

// Out Buffer to Host Read Again
errNum = clEnqueueReadBuffer(commandQueue, memObjects[2],
                             CL_TRUE, 0, ARRAY_SIZE * sizeof(float),
                             result, 0, NULL, NULL);
                             )
if (errNum != CL_SUCCESS)
{
    cerr << "Error reading result buffer." << endl;
    Cleanup(context, commandQueue, program, kernel, memObjects);
    return 1;
}

// Result Buffer Output
for (int i = 0; i < ARRAY_SIZE; i++)
{
    cout << result[i] << " ";
}
cout << endl
cout << "Executed program successfully." << endl;

Cleanup (context, commandQueue, program, kernel, memObjects);

return 0;

}
