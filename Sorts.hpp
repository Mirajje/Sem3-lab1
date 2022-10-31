#ifndef MAIN_CPP_SORTS_HPP
#define MAIN_CPP_SORTS_HPP

#include "SequenceLib/Sequence_lib.h"
#include <vector>

template <class T>
class Sorts
{
public:
    static Sequence<T>* mergeSort(Sequence<T>* arr, bool (*comp) (const T&, const T&));
    static void quickSort(Sequence<T>* arr, int low, int high, bool (*comp) (const T&, const T&));
    static void shellSort(Sequence<T>* arr, bool (*comp) (const T&, const T&));
    static void radixSort(Sequence<T>* arr, int m, int k);


private:
    static int symb(const int& a, int digit);
    static int symb(const std::string& a, int digit);
    static int partition(Sequence<T>* arr, int low, int high, bool (*comp) (const T&, const T&));
};

template <class T>
Sequence<T>* Sorts<T>::mergeSort(Sequence<T>* arr, bool (*comp) (const T&, const T&))
{
    if (arr == nullptr)
        throw Errors(Errors::NULL_POINTER_ERROR);

    if (arr->getLength() == 0)
        throw Errors(Errors::ZERO_SIZE_ERROR);

    if (arr->getLength() < 0)
        throw Errors(Errors::NEGATIVE_SIZE_ERROR);

    if (arr->getLength() > 1)
    {
        int length = arr->getLength();

        Sequence<T>* arr1 = mergeSort(arr->getSubSequence(0, arr->getLength() / 2 - 1), comp);
        Sequence<T>* arr2 = mergeSort(arr->getSubSequence(arr->getLength() / 2, arr->getLength() - 1), comp);
        int l = 0; int r = 0;
        while (l + r < length)
            if ((r == arr2->getLength()) ||(l < arr1->getLength()) && (comp((*arr1)[l], (*arr2)[r])))
            {
                (*arr)[l + r] = (*arr1)[l];
                l++;
            }
            else
            {
                (*arr)[l + r] = (*arr2)[r];
                r++;
            }
    }
    return arr;
}

template <class T>
void Sorts<T>::shellSort(Sequence<T>* arr, bool (*comp) (const T&, const T&))
{
    if (arr == nullptr)
        throw Errors(Errors::NULL_POINTER_ERROR);

    if (arr->getLength() == 0)
        throw Errors(Errors::ZERO_SIZE_ERROR);

    if (arr->getLength() < 0)
        throw Errors(Errors::NEGATIVE_SIZE_ERROR);

    for (int d = arr->getLength()/2; d > 0; d /= 2)
        for (int i = d; i < arr->getLength(); i++)
            for (int j = i - d; (j >= 0 && !comp((*arr)[j], (*arr)[j + d])); j -= d)
                std::swap((*arr)[j], (*arr)[j + d]);
}

template <class T>
void Sorts<T>::quickSort(Sequence<T>* arr,  int low, int high, bool (*comp) (const T&, const T&))
{
    if (arr == nullptr)
        throw Errors(Errors::NULL_POINTER_ERROR);

    if (arr->getLength() == 0)
        throw Errors(Errors::ZERO_SIZE_ERROR);

    if (arr->getLength() < 0)
        throw Errors(Errors::NEGATIVE_SIZE_ERROR);

    if (low < high)
    {
        int spot = partition(arr, low, high, comp);
        quickSort(arr, low, spot, comp);
        quickSort(arr, spot + 1, high, comp);
    }
}

template <class T>
int Sorts<T>::partition(Sequence<T>* arr, int low, int high, bool (*comp) (const T&, const T&))
{
    T pivot = (*arr)[high - 1];

    int spot = low;
    for (int i = low; i < high - 1; i++)
    {
        if (comp((*arr)[i], pivot))
        {
            std::swap((*arr)[spot], (*arr)[i]);
            spot += 1;
        }
    }
    std::swap((*arr)[spot], (*arr)[high - 1]);

    return spot;
}

template <class T>
int Sorts<T>::symb(const std::string& a, int digit)
{
    std::string str = a;
    if (digit >= str.size())
        return 0;
    return (int) str[str.size() - digit - 1];
}

template <class T>
int Sorts<T>::symb(const int& a, int digit)
{
    int aCopy = std::abs(a);
    while (digit > 0 && aCopy > 0)
    {
        aCopy /= 10;
        digit --;
    }
    if (aCopy == 0)
        return 11;
    if (a > 0)
        return aCopy % 10 + 12;
    return 10 - aCopy % 10;
}

template <class T>
void Sorts<T>::radixSort(Sequence<T>* arr, int m, int k)
{
    Sequence<T>* new_array;
    std::vector<int> c(k);
    int count, tmp, d;
    for (int i = 0; i < m; i++)
    {
        new_array = new ArraySequence<T>(arr->getLength());
        std::fill(c.begin(), c.end(), 0);
        for (int j = 0; j < arr->getLength(); j++)
            c[symb((*arr)[j], i)]++;

        count = 0;
        for (int j = 0; j < k; j++)
        {
            tmp = c[j];
            c[j] = count;
            count += tmp;
        }

        for (int j = 0; j < arr->getLength(); j++)
        {
            d = symb((*arr)[j], i);
            (*new_array)[c[d]] = (*arr)[j];
            c[d]++;
        }
        (*arr) = std::move(*new_array);
    }
}

#endif
