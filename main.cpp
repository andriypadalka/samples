#include "CommonIncludes.h"
#include "array.h"
#include <vector>


// ///////////////////// Test functions declarations
void ForAndFunctionsCompare(int * pAr, int nSize,
     int nSamplesCount, bool bShowCurrenTime);
void Init(int * pAr, int nSize);
void InitRand(int * pAr, int nSize);
// ///////////////////// end of Test functions



int main(int argc, char *argv[])
{
    
#define TIME_MEASUREMENT_TEST
#ifdef TIME_MEASUREMENT_TEST
    {
        #define ARR_SIZE 2000
        int iAr[ARR_SIZE], iAr2[ARR_SIZE];
        for(int i = 0; i < ARR_SIZE; ++i)
            iAr[i] = rand();

        int nSamplesCount = 3;
        EXPR_TIME_CONS_AVER(nSamplesCount,
            for(int j = 0; j < ARR_SIZE; ++j) iAr2[j] = iAr[j], true);
        EXPR_TIME_CONS_AVER(nSamplesCount,
            memcpy(iAr2, iAr, sizeof(int) * ARR_SIZE),  true);
        cout<<endl;

        Array ar(10);
        EXPR_TIME_CONS_AVER(nSamplesCount, Array ar2(ar), false);
        EXPR_TIME_CONS_AVER(nSamplesCount, Array ar3(std::move(ar)), false);

        Test_FuncTime(ForAndFunctionsCompare(iAr, ARR_SIZE, nSamplesCount, true));
    }
#endif //TIME_MEASUREMENT_TEST

//#define USAGE_OF_TESTUNIT_TOOL
#ifdef USAGE_OF_TESTUNIT_TOOL
    {
        std::vector<Array> vc;
        int nCount = 2;
        for(int i = 0; i < nCount; ++i)
        {
                                                                                Test123_ClassArray(cout<<"-- before push: size cap "<<vc.size()<<' '<<vc.capacity()<<endl);
            vc.push_back(Array(rand()% 21));
                                                                                Test123_ClassArray(cout<<"-- after push: size cap "<<vc.size()<<' '<<vc.capacity()<<"\n\n");
        }

        for(int i = 0; i < nCount; ++i)
            vc[i].Show();

    }
#endif //USAGE_OF_TESTUNIT_TOOL

//#define ASSIGNMENT_OPERATOR_TEST
#ifdef ASSIGNMENT_OPERATOR_TEST
    {
        Array ar(5);
        ar.Show();
        Array ar2(6);
        ar = ar2;
        ar.Show();
        ar2.Show();
    }
#endif // ASSIGNMENT_OPERATOR_TEST


    return 0;
}

// ///////////////////// Test functions  definitions
// the name of the function may starts from task number
void ForAndFunctionsCompare(int * iAr, int nSize,
     int nSamplesCount, bool bShowCurTime)
{
    // here must be description of what this test-function must check,
    // for example:
    // variable nVariableName must be == ...... because .....
    // or see reference for task#...
    // variable nVariableName must be in the range min < ..< max
    EXPR_TIME_CONS_AVER(nSamplesCount,
               for(int j = 0; j < nSize; ++j) iAr[j] = j + 1, bShowCurTime);
    EXPR_TIME_CONS_AVER(nSamplesCount,
               Init(iAr, nSize), bShowCurTime);
    EXPR_TIME_CONS_AVER(nSamplesCount,
               InitRand(iAr, nSize), bShowCurTime);
}
void Init(int * pAr, int nSize)
{
    for(int i = 0; i < nSize; ++i)
        pAr[i] = i + 1;
}
void InitRand(int * pAr, int nSize)
{
    for(int i = 0; i < nSize; ++i)
        pAr[i] = rand();
}

// ///////////////////// end of Test functions
