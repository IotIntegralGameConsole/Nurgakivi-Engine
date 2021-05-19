#include <stdio.h>
#include <stdlib.h>
#include <CL/gl.h>

#define GL_SHARING_EXTENSION "cl_khr_gl_sharing"
std::string stdDevString(extensions);
free(extensions);

size_t szOldPos = 0;
size_t szSpacePos = stdDevString.find(' ', szOldPos);
// Extension String Array Divide
while (szSpacePos != stdDevString.npos)
{
    if(strcmp(GL_SHARING_EXTENSION, stdDevString.substr*(szOldPos, szSpacePos - szOldPos).c_str()) == 0)
    {
        // Device OpenGL Sharing Support
        uiDeviceUsed = i;
        bSharingSupported = true;
        break;
    }
    do {
        szOldPos = szSpacePos + 1;
        szSpacePos = stdDevString.find(' ', szOldPos);
    }
    while (szSpacePos == szOldPos);
}

// This is Setting For Linux Platform
cl_context_properties props[] =
{
    CL_CONTEXT_KHR,
    (cl_context_properties)glXGetCurrentContext(),
    CL_GLX_DISPLAY_KHR,
    (cl_context_properties)glXGetCurrentDisplay(),
    CL_CONTEXT_PLATFORM,
    (cl_context_properties)cpPlatform,
    0
};
cxGPUContext = clCreateContext(props, 1, &cdDevices[uiDeviceUsed],
                               NULL, NULL, &ciErrNum);

// OpenCL Buffer Creation
/*
cl_mem clCreateFromGLBuffer(cl_context cl_context,
                            cl_mem_flags cl_flags,
                            cl_int *errcode_ret)
*/
GLuint initVBO(int vbolen)
{
    GLint bsize;
    GLuint vbo_buffer;
    glGenBuffers(1, &vbo_buffer);

    glBindBuffer(GL_ARRAY_BUFFER, vbo_buffer);

    // create Buffer. Basically Size Setting & Parameter
    glBufferData (GL_ARRAY_BUFFER, vbolen * sizeof(float)*4,
                  NULL, GL_STREAM_DRAW);

    // Same Like Creating Buffer Size Request
    // Check Again
    glGetBufferParameteriv(GL_ARRAT=Y_BUFFER,
                           GL_BUFFER_SIZE, &bsize);
    if ((GLuint)bsize != (vbolen*sizeof(float)*4)) {
        printf(
        "Vertex Buffer object (%d) has incorrect size (%d).\n",
        (unsigned)vbo_buffer,(unsigned)bsize);
    }

    // All
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    return vbo_buffer;
}

// Static Buffer Object
GLuint vbo = initVBO(640, 480);
cl_vbo_mem = clCreateFromGLBuffer(context,CL_MEM_READ_WRITE, vbo,&err);

// Start Static Location & End Static Location Saving Array in Kernel
_Kernel void init_vbo_kernel(_global float4 *vbo,
  int w, int h, int seq)
  {
      int gid = get_global_id(0);
      float4 linepts;
      float f = 1.0f;
      float a = (float)h/4.0f;
      float b = w/2.0f;

      linepts.x = gid;
      linepts.y = b + a*sin(3.14*2.0*((float)gid/(float)w*f +
        (float)seq/(float)w));
      linepts.z = gid+1.0f;
      linepts.w = b + a*sin(3.14*2.0*((float)(gid+1.0f)/(float)w*f+
                                      (float)seq/(float)w));

      vbo[gid] = linepts;
  }

  // Save Returned OpenCL Object with General OpenCL Object From clCreateFromGLBuffer()
    clSetKernelArg (kernel, 0, sizeof(cl_mem), &cl_vbo_mem);

  // Buffer For OpenGL Using
    glFinish();
    errNum = clEnqueueAcquireGLObjects(commandQueue, 1, &cl_tex_mem,
        0, NULL, NULL);
    errNum = clEnqueueNDRangeKernel(commandQueue, tex_kernel, 2, NULL,
        tex_globalWorkSize,
        tex_localWorkSize,
        0, NULL, NULL);
    clFinish(commandQueue);
    errNum = clEnqueueReleaseGLObjects(commandQueue, 1, &cl_tex_mem, 0,
            NULL, NULL);



/*
cl_int clEnqueueAcquireGLObjects (cl_command_queue command_queue,
                                  cl_uint num_objects,,
                                  const cl_mem * mem_objects,
                                  cl_uint num_events_in_wait_list,
                                  const cl_event *event_wait_list,
                                  cl_event *event)

cl_int clEnqueueReleaseGLObjects (cl__command_queue command_queue,
                                  cl_uint num_objects,,
                                  const cl_mem * mem_objects,
                                  cl_uint num_events_in_wait_list,
                                  const cl_event *event_wait_list,
                                  cl_event *event)


// Device Extension Supports
CL_DEVICE_EXTENSION char[]  cl_khr_fp64 // 64-bit Floating Point
                            cl_khr_int64_base_atomics //64-bit integer Base
                            cl_khr_int64_extended_atomics // 64-bit integer Extension
                            cl_khr_fp16 // 16-bit Floating Point
                            cl_khr_gl_sharing // GL Sharing
                            cl_khr_gl_event // GL Event
                            cl_khr_d3d10_sharing // Direct 3D Sharing




size_t extensionSize;
ciErrNum = clGetDeviceInfo (cdDevices[i], CL_DEVICE_EXTENSION, 0,
                            NULL, &extensionSize);

char* extensions = (char*)malloc(extensionSize);
ciErrNum = clGetDeviceInfo(cdDevices[i], CL_DEVICE_EXTENSIONS,
                           extensionSize, extensions, &extensionSize);


// Create OpenCL Image From OpenGL Texture (2D Texture)
cl_mem clCreateFromGLTexture2D (cl_context cl_context,
                                cl_mem_flags cl_flags,
                                GLenum texture_target,
                                GLint miplevel,
                                GLuint texture,
                                cl_int *errcode_ret)

// Create OpenCL Image From OpenGL Texture (3D Texture)
cl_mem clCreateFromGLTexture3D (cl_context cl_context,
                                cl_mem_flags cl_flags,
                                GLenum texture_target,
                                GLint miplevel,
                                GLuint texture,
                                cl_int *errcode_ret)


//GL Render Buffer
cl_mem clCreateFromGLRenderbuffer (cl_context context,
                                cl_mem_flags flags,
                                GLuint renderbuffer,
                                cl_int *errcode_ret)

// OpenGL Object Information
cl_int clGetGLObjectInfo(cl_mem memobj,
                         cl_gl_object_type *gl_object_type,
                         GLuint *gl_object_name)

// Texture Object Information
cl_int clGetGLTextureInfo (cl_mem memobj,
                           cl_gl_texture_info param_name,
                           size_t param_value_size,
                           void *param_value,
                           size_t *param_value_size_ret)

//

*/

/* If 4 Floating points RGBA Texture Sharing Between OpenGL & OpenCL */
glGenTextures(1, &tex);
glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
glBindTexture(GL_TEXTURE_RECTANGLE_ARB, tex);
glTeximage2D(GL_TEXTURE_RECTANGLE_ARB, 0, GL_RGBA32F_ARB, width, height, 0, GL_LUMINANCE, GL_FLOAT, NULL);

/* Shown OpenGL Texture send to clCreateFromGLTexture2D() parameter Before OpenCL Texture Memory Object */
*p_cl_tex_mem = clCreateFromGLTexture2D(context,
                       CL_MEM_READ_WRITE, GL_TEXTURE_RECTANGLE_ARB,
                       0, tex, &errNum);



