#include "clUtilities.hpp"
#include "CL/cl.h"
#include <sstream>

#define ERROR_STRING_CASE(ErrorValue) \
    case ErrorValue: return #ErrorValue;

std::string cl::errorToString(int errorCode)
{
    switch (errorCode) {
        ERROR_STRING_CASE(CL_SUCCESS);
        ERROR_STRING_CASE(CL_DEVICE_NOT_FOUND);
        ERROR_STRING_CASE(CL_DEVICE_NOT_AVAILABLE);
        ERROR_STRING_CASE(CL_COMPILER_NOT_AVAILABLE);
        ERROR_STRING_CASE(CL_MEM_OBJECT_ALLOCATION_FAILURE);
        ERROR_STRING_CASE(CL_OUT_OF_RESOURCES);
        ERROR_STRING_CASE(CL_OUT_OF_HOST_MEMORY);
        ERROR_STRING_CASE(CL_PROFILING_INFO_NOT_AVAILABLE);
        ERROR_STRING_CASE(CL_MEM_COPY_OVERLAP);
        ERROR_STRING_CASE(CL_IMAGE_FORMAT_MISMATCH);
        ERROR_STRING_CASE(CL_IMAGE_FORMAT_NOT_SUPPORTED);
        ERROR_STRING_CASE(CL_BUILD_PROGRAM_FAILURE);
        ERROR_STRING_CASE(CL_MAP_FAILURE);
        ERROR_STRING_CASE(CL_MISALIGNED_SUB_BUFFER_OFFSET);
        ERROR_STRING_CASE(CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST);
        ERROR_STRING_CASE(CL_COMPILE_PROGRAM_FAILURE);
        ERROR_STRING_CASE(CL_LINKER_NOT_AVAILABLE);
        ERROR_STRING_CASE(CL_LINK_PROGRAM_FAILURE);
        ERROR_STRING_CASE(CL_DEVICE_PARTITION_FAILED);
        ERROR_STRING_CASE(CL_KERNEL_ARG_INFO_NOT_AVAILABLE);
        ERROR_STRING_CASE(CL_INVALID_VALUE);
        ERROR_STRING_CASE(CL_INVALID_DEVICE_TYPE);
        ERROR_STRING_CASE(CL_INVALID_PLATFORM);
        ERROR_STRING_CASE(CL_INVALID_DEVICE);
        ERROR_STRING_CASE(CL_INVALID_CONTEXT);
        ERROR_STRING_CASE(CL_INVALID_QUEUE_PROPERTIES);
        ERROR_STRING_CASE(CL_INVALID_COMMAND_QUEUE);
        ERROR_STRING_CASE(CL_INVALID_HOST_PTR);
        ERROR_STRING_CASE(CL_INVALID_MEM_OBJECT);
        ERROR_STRING_CASE(CL_INVALID_IMAGE_FORMAT_DESCRIPTOR);
        ERROR_STRING_CASE(CL_INVALID_IMAGE_SIZE);
        ERROR_STRING_CASE(CL_INVALID_SAMPLER);
        ERROR_STRING_CASE(CL_INVALID_BINARY);
        ERROR_STRING_CASE(CL_INVALID_BUILD_OPTIONS);
        ERROR_STRING_CASE(CL_INVALID_PROGRAM);
        ERROR_STRING_CASE(CL_INVALID_PROGRAM_EXECUTABLE);
        ERROR_STRING_CASE(CL_INVALID_KERNEL_NAME);
        ERROR_STRING_CASE(CL_INVALID_KERNEL_DEFINITION);
        ERROR_STRING_CASE(CL_INVALID_KERNEL);
        ERROR_STRING_CASE(CL_INVALID_ARG_INDEX);
        ERROR_STRING_CASE(CL_INVALID_ARG_VALUE);
        ERROR_STRING_CASE(CL_INVALID_ARG_SIZE);
        ERROR_STRING_CASE(CL_INVALID_KERNEL_ARGS);
        ERROR_STRING_CASE(CL_INVALID_WORK_DIMENSION);
        ERROR_STRING_CASE(CL_INVALID_WORK_GROUP_SIZE);
        ERROR_STRING_CASE(CL_INVALID_WORK_ITEM_SIZE);
        ERROR_STRING_CASE(CL_INVALID_GLOBAL_OFFSET);
        ERROR_STRING_CASE(CL_INVALID_EVENT_WAIT_LIST);
        ERROR_STRING_CASE(CL_INVALID_EVENT);
        ERROR_STRING_CASE(CL_INVALID_OPERATION);
        ERROR_STRING_CASE(CL_INVALID_GL_OBJECT);
        ERROR_STRING_CASE(CL_INVALID_BUFFER_SIZE);
        ERROR_STRING_CASE(CL_INVALID_MIP_LEVEL);
        ERROR_STRING_CASE(CL_INVALID_GLOBAL_WORK_SIZE);
        ERROR_STRING_CASE(CL_INVALID_PROPERTY);
        ERROR_STRING_CASE(CL_INVALID_IMAGE_DESCRIPTOR);
        ERROR_STRING_CASE(CL_INVALID_COMPILER_OPTIONS);
        ERROR_STRING_CASE(CL_INVALID_LINKER_OPTIONS);
        ERROR_STRING_CASE(CL_INVALID_DEVICE_PARTITION_COUNT);
        ERROR_STRING_CASE(CL_INVALID_PIPE_SIZE);
        ERROR_STRING_CASE(CL_INVALID_DEVICE_QUEUE);
        ERROR_STRING_CASE(CL_INVALID_SPEC_ID);
        ERROR_STRING_CASE(CL_MAX_SIZE_RESTRICTION_EXCEEDED);
        default: {
            std::stringstream ss;
            ss << "Unknown error (" << errorCode << ")";
            return ss.str();
        }
    }
}

#undef ERROR_STRING_CASE
