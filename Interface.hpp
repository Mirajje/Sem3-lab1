#ifndef MAIN_CPP_INTERFACE_HPP
#define MAIN_CPP_INTERFACE_HPP

#include <chrono>
#include <random>
#include "Sorts.hpp"
#include <iostream>

struct Timer
{
    std::chrono::time_point<std::chrono::steady_clock> begin, end;
    std::chrono::duration<float> elapsed_ms;

    Timer()
    {
        begin = std::chrono::steady_clock::now();
    }

    ~Timer()
    {
        end = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        if (elapsed_ms.count() > 1)
            std::cout << "time elapsed: " << elapsed_ms.count() << " ms\n";
        else
            std::cout << "time elapsed: " << elapsed_ms.count() * 1000000 << " ns\n";
    }
};

template <class T> void input(T* a);
template <class T> Sequence<T>* arrayInput();
template <class T> void rnd(Sequence<T>* arr, int amplitude);
template <class T> void runTimeTests();
template <class T> void runTime(Sequence<T>* arr);
template <class T> int menu();

template <class T>
int menu()
{
    long k;

    int command = 0;
    int n = -1;
    Sequence<T>* arr = arrayInput<T>();

    runTime(arr);

    Sequence<T>* origin = new ArraySequence<T>(*arr);

    while (1)
    {
        std::cout << "Enter command: 1 - display array, 2 - sort array using quickSort, "
                     "3 - sort array using shellSort, 4 - sort array using mergeSort, 5 - display "
                     "origin array, 6 - create a new array, 7 - terminate the program\n";

        command = -1;
        while (command > 7 || command < 1)
            input(&command);

        switch (command)
        {
            case 7:
                return 0;

            case 1:
                std::cout << std::endl;
                arr->print();
                std::cout << std::endl;
                break;

            case 2:
                (*arr) = (*origin);

                try
                {
                    std::cout << "Sorted with quick sort, ";
                    Timer timer;
                    Sorts<T>::quickSort(arr, 0, arr->getLength(), [](const T& a, const T& b) { return (a < b); });
                }
                catch (const Errors& error)
                {
                    std::cout << "Process finished with error code = " << error << std::endl;
                    exit(0);
                }
                break;

            case 3:
                (*arr) = (*origin);

                try
                {
                    std::cout << "Sorted with Shell sort, ";
                    Timer timer;
                    Sorts<T>::shellSort(arr, [](const T& a, const T& b) { return (a < b); });
                }
                catch (const Errors& error)
                {
                    std::cout << "Process finished with error code = " << error << std::endl;
                    exit(0);
                }
                break;

            case 4:
                (*arr) = (*origin);

                try
                {
                    std::cout << "Sorted with merge sort, ";
                    Timer timer;
                    Sorts<T>::mergeSort(arr, [](const T& a, const T& b) { return (a < b); });
                }
                catch (const Errors& error)
                {
                    std::cout << "Process finished with error code = " << error << std::endl;
                    exit(0);
                }
                break;

            case 5:
                std::cout << std::endl;
                origin->print();
                std::cout << std::endl;
                break;

            case 6:
                std::cout << "Choose data type: 1 - int, 2 - float, 3 - string\n";
                k = -1;
                while (k <= 0 || k > 3)
                    input(&k);
                switch (k)
                {
                    case 1:
                        menu<int>();
                        break;

                    case 2:
                        menu<float>();
                        break;

                    case 3:
                        menu<std::string>();
                        break;

                }
                return 0;

            default:
                return -1;
        }
    }
}

template <class T>
void runTimeTests()
{
    std::unique_ptr<Sequence<int>> arr(new ArraySequence<int>(10000));

    for (int i = 0; i < arr->getLength(); i++)
        (*arr)[i] = i;
    std::swap((*arr)[5267], (*arr)[9913]);

    std::cout << "Sorting an almost sorted array:\n";
    runTime(arr.get());

    std::cout << "\nSorting reverse order array:\n";
    for (int i = 0; i < arr->getLength(); i++)
        (*arr)[i] = arr->getLength() - 1 - i;

    runTime(arr.get());
    std::cout << "\nSorting an array with a lot of repetitions:\n";

    for (int i = 0; i < arr->getLength(); i++)
        (*arr)[i] = 10;
    (*arr)[10] = 2; (*arr)[7777] = -14; (*arr)[9999] = 9999;

    runTime(arr.get());
    std::cout << "\nSorting a small array:\n";
    (*arr) = {3, -1, 2};
    runTime(arr.get());

    std::cout << "\nQuickSort has O(nlogn) complexity. In the worst case scenario complexity becomes O(n^2). Another "
                 "problem with it is that recursion depth will be n so stack overflow is possible.\n";

    std::cout << "\nShellSort has O(nlog^2n) complexity at best. In the worst case scenario complexity becomes O(n^2). "
                 "Average sorting time depends on the choice of intervals\n";

    std::cout << "\nMergeSort has O(nlogn) complexity in any case\n";

}

template <class T>
void runTime(Sequence<T>* arr)
{
    std::unique_ptr<Sequence<T>> origin(new ArraySequence<T>(*arr));

    //testing quickSort time
    {
        try
        {
            std::cout << "Sorted with quick sort, ";
            Timer timer;
            Sorts<T>::quickSort(arr, 0, arr->getLength(), [](const T& a, const T& b) { return (a < b); });
        }
        catch (const Errors& error)
        {
            std::cout << "Process finished with error code = " << error << std::endl;
            exit(0);
        }
    }

    (*arr) = (*origin);

    //testing shellSort time
    {
        try
        {
            std::cout << "Sorted with Shell sort, ";
            Timer timer;
            Sorts<T>::shellSort(arr, [](const T& a, const T& b) { return (a < b); });
        }
        catch (const Errors& error)
        {
            std::cout << "Process finished with error code = " << error << std::endl;
            exit(0);
        }
    }

    (*arr) = (*origin);

    //testing mergeSort time
    {
        try
        {
            std::cout << "Sorted with merge sort, ";
            Timer timer;
            Sorts<T>::mergeSort(arr, [](const T& a, const T& b) { return (a < b); });
        }
        catch (const Errors& error)
        {
            std::cout << "Process finished with error code = " << error << std::endl;
            exit(0);
        }
    }

    (*arr) = (*origin);

    //testing radixSort time
    {
        try
        {
            std::cout << "Sorted with radix sort, ";
            Timer timer;
            Sorts<T>::radixSort(arr, 3, 300);
        }
        catch (const Errors& error)
        {
            std::cout << "Process finished with error code = " << error << std::endl;
            exit(0);
        }
    }
}

template <class T>
void input(T* a)
{
    while (true)
    {
        std::cout << "Enter a value:";
        std::cin >> *a;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            continue;
        }
        break;
    }
}

template <class T>
void rnd(Sequence<T>* arr, int amplitude)
{
    if (typeid(T) == typeid(std::string))
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(0, 255);
        for (int i = 0; i < arr->getLength(); i++)
            for (int j = 0; j < amplitude; j++)
                (*arr)[i] += (char) dist(mt);
    }
    else if ((typeid(T) == typeid(int)) || (typeid(T) == typeid(float)))
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<float> dist(-amplitude, amplitude);
        for (int i = 0; i < arr->getLength(); i++)
            (*arr)[i] = dist(mt);
    }
}

template <class T>
Sequence<T>* arrayInput()
{
    std::cout << "Enter size of array\n";
    int n = -1;
    while (n < 0 || n > 1000000000)
        input(&n);
    Sequence<T>* arr = new ArraySequence<T>(n);

    int amplitude = -1;

    n = -1;
    std::cout << "1 - enter manually, 2 - random generation\n";
    while (n <= 0 || n > 2)
        input(&n);

    switch (n)
    {
        case 1:
            for (int i = 0; i < arr->getLength(); i++)
                input(&(*arr)[i]);
            break;

        case 2:
            std::cout << "Enter range of random generation (size in case of string)\n";
            while (amplitude <= 0 || amplitude > 1000000000.0)
                input(&amplitude);

            rnd<T>(arr, amplitude);
            break;
    }
    return arr;
}

#endif
