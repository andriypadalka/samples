#ifndef TSWAP_HPP
#define TSWAP_HPP

template <typename T>
void TSwap(T * pThis, const T & Right)
{
    T temp(Right);
    char sBuff[sizeof(T)];
    memcpy(sBuff, pThis, sizeof(T));
    memcpy(pThis, &temp, sizeof(T));
    memcpy(&temp, sBuff, sizeof(T));
}

#endif // TSWAP_HPP
