#include "array.h"
#include "CommonIncludes.h"


Array::Array(int nSize): m_nSize(nSize), m_nReadonly(m_nSize * 2)
{
    if(m_nSize < 2)
        m_nSize = 2;
    m_pAr = new int[m_nSize];
    for(int i = 0; i < m_nSize; ++i)
        m_pAr[i] = rand() % 100;
                                                                           Test123_ClassArray(cout<<"Array(int nSize = 2) "<<this<<' '<<m_nSize<<endl);
}
Array::Array(const Array & Right): m_nSize(Right.m_nSize),
    m_nReadonly(Right.m_nReadonly)
{
    m_pAr = new int[m_nSize];
    memcpy(m_pAr, Right.m_pAr, sizeof(int) * m_nSize);
                                                                           Test123_ClassArray(cout<<"Array copy constr "<<this<<" from "<<&Right<<' '<<m_nSize<<endl);
}
Array::Array(Array && Right) noexcept
    : m_nSize(Right.m_nSize), m_pAr(Right.m_pAr),
      m_nReadonly(Right.m_nReadonly)
{
    Right.m_nSize = 0;
    Right.m_pAr = 0;
                                                                           Test123_ClassArray(cout<<"Array && move constr "<<this<<" from "<<&Right<<' '<<m_nSize<<endl);
}
Array::~Array()
{
    delete [] m_pAr;
                                                                           Test123_ClassArray(cout<<"~Array() "<<this<<' '<<m_nSize<<endl);
}

                                                                // first vesion of operator
//Array & Array::operator = (const Array & Right)
//{
//    if(this != &Right)
//    {
//        Array temp(Right);
//        char sBuff[sizeof(Array)];
//        memcpy(sBuff, this, sizeof(Array));
//        memcpy(this, &temp, sizeof(Array));
//        memcpy(&temp, sBuff, sizeof(Array));
//    }
//                                                                           Test123_ClassArray(cout<<"Array oper = "<<this<<" from "<<&Right<<' '<<m_nSize<<endl);
//    return *this;
//}


Array & Array::operator = (const Array & Right)
{
    if(this != &Right)
    {
        TSwap(this, Right);
    }
                                                                           Test123_ClassArray(cout<<"Array oper = "<<this<<" from "<<&Right<<' '<<m_nSize<<endl);
    return *this;
}

void Array::Show()
{
    for(int i = 0; i < m_nSize; ++i)
        cout<<m_pAr[i]<<' ';
    cout<<endl;
                                                                           Test123_ClassArray(cout<<" === Show() === "<<this<<' '<<m_nReadonly<<endl);
}
