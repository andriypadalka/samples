#ifndef ARRAY_H
#define ARRAY_H

class Array
{
    int m_nSize;
    int * m_pAr;
    const int m_nReadonly;
public:
    Array(int nSize = 2);
    Array(const Array & Right);
    Array(Array && Right) noexcept;
    ~Array();

    Array & operator = (const Array & Right);
    void Show();

};

#endif // ARRAY_H
