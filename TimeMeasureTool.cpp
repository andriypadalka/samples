#include"TimeMeasureTool.h"

//this tool is compatible for x86_64 architecture only
#ifdef _WIN32                //  Windows
    #include <intrin.h>
    uint64_t rdtsc()
    {
        return __rdtsc();
    }
#else                        //  Linux/GCC
    uint64_t rdtsc()
    {
        unsigned int lo,hi;
        __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
        return ((uint64_t)hi << 32) | lo;
    }
#endif //_WIN32
