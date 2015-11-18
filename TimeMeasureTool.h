#ifndef TIMEMEASURETOOL_H
#define TIMEMEASURETOOL_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <stdint.h>
//this tool is compatible for x86_64 architecture only
#ifdef _WIN32                //  Windows
    uint64_t rdtsc();
#else                        //  Linux/GCC
    uint64_t rdtsc();
#endif //_WIN32

#define EXPR_TIME_CONS(nCount, expr)\
{\
    char ExprText[sizeof(#expr) + 1] = {0};\
    memcpy(ExprText, #expr, sizeof(#expr));\
    cout<<"=== "<<ExprText<<" === start"<<endl;\
    uint64_t ui1, ui2, uiTicks;\
    for(int iIn = 0; iIn < nCount; ++iIn)\
    {\
        ui1 = rdtsc();\
        expr;\
        ui2 = rdtsc();\
        uiTicks = ui2 - ui1;\
        cout<<uiTicks<<endl;\
    }\
    cout<<"=== "<<ExprText<<" ===  end"<<"\n\n";\
}

#define EXPR_TIME_CONS_AVER(nCount, expr, bShowCurTime)\
{\
    char ExprText[sizeof(#expr) + 1] = {0};\
    memcpy(ExprText, #expr, sizeof(#expr));\
    if(bShowCurTime == true)\
        cout<<"=== "<<ExprText<<" === start"<<endl;\
    uint64_t ui1, ui2, uiTicks, uiAverage = 0;\
    for(int iIn = 0; iIn < nCount; ++iIn)\
    {\
        ui1 = rdtsc();\
        expr;\
        ui2 = rdtsc();\
        uiTicks = ui2 - ui1;\
        uiAverage += uiTicks;\
        if(bShowCurTime == true)\
            cout<<uiTicks<<endl;\
    }\
    cout<<"=== "<<ExprText<<" average == "<<uiAverage / nCount<<"\n\n";\
}


// #define EXPR_TIME_NO_OUT(nCount, expr, uint64_tArray, nArrSize, charBufferForExprAsText, nBuffSize)
// int nMinSamplesCount =  nCount < nArrSize ? nCount : nArrSize;
// int nMinTextLength =  nBuffSize < sizeof(ExprText) ? nBuffSize : sizeof(ExprText);

#endif // TIMEMEASURETOOL_H
