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
                    Timer timer;
                    Sorts<T>::quickSort(arr, 0, arr->getLength(), [](const T& a, const T& b) { return (a < b); });
                    std::cout << "Sorted with quick sort, ";
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
                    Timer timer;
                    Sorts<T>::shellSort(arr, [](const T& a, const T& b) { return (a < b); });
                    std::cout << "Sorted with Shell sort, ";
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
                    Timer timer;
                    Sorts<T>::mergeSort(arr, [](const T& a, const T& b) { return (a < b); });
                    std::cout << "Sorted with merge sort, ";
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
    Sequence<int>* arr = new ArraySequence<int>({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
                                                 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
                                                 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55,
                                                 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73,
                                                 74, 75, 76, 77, 78, 79, 80, 82, 81, 83, 84, 85, 86, 87, 88, 89, 90, 91,
                                                 92, 93, 94, 95, 96, 97, 98, 99, });

    std::cout << "Sorting an almost sorted array:\n";
    runTime(arr);
    std::cout << "\nSorting reverse order array:\n";
    (*arr) = {100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75,
              74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49,
              48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23,
              22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    runTime(arr);
    std::cout << "\nSorting an array with a lot of repetitions:\n";
    (*arr) = {10, 10, 10, 4, 10, 1, 2, 3, 10, 10, 10, 10, 10, 10, 10, 2, 10, 10, 10, 4, 10, 1, 2, 3, 10, 10, 10, 10,
              10, 10, 10, 2, 10, 10, 10, 4, 10, 1, 2, 3, 10, 10, 10, 10, 10, 10, 10, 2, 10, 10, 10, 4, 10, 1, 2, 3, 10,
              10, 10, 10, 10, 10, 10, 2, 10, 10, 10, 4, 10, 1, 2, 3, 10, 10, 10, 10,
              10, 10, 10, 2, 10, 10, 10, 4, 10, 1, 2, 3, 10, 10, 10, 10, 10, 10, 10, 2};

    runTime(arr);
    std::cout << "\nSorting a small array:\n";
    (*arr) = {3, -1, 2};
    runTime(arr);

    std::cout << "\nQuickSort has O(nlogn) complexity. In the worst case scenario complexity becomes O(n^2). Another "
                 "problem with it is that recursion depth will be n so stack overflow is possible.\n";

    std::cout << "\nShellSort has O(nlog^2n) complexity at best. In the worst case scenario complexity becomes O(n^2). "
                 "Average sorting time depends on the choice of intervals\n";

    std::cout << "\nMergeSort has O(nlogn) complexity in any case\n";

}

template <class T>
void runTime(Sequence<T>* arr)
{
    Sequence<T>* origin = new ArraySequence<T>(*arr);

    //testing quickSort time
    {
        Timer timer;
        try
        {
            Sorts<T>::quickSort(arr, 0, arr->getLength(), [](const T& a, const T& b) { return (a < b); });
        }
        catch (const Errors& error)
        {
            std::cout << "Process finished with error code = " << error << std::endl;
            exit(0);
        }
        std::cout << "Sorted with quick sort, ";
    }

    (*arr) = (*origin);

    //testing shellSort time
    {
        Timer timer;
        try
        {
            Sorts<T>::shellSort(arr, [](const T& a, const T& b) { return (a < b); });
        }
        catch (const Errors& error)
        {
            std::cout << "Process finished with error code = " << error << std::endl;
            exit(0);
        }
        std::cout << "Sorted with Shell sort, ";
    }

    (*arr) = (*origin);

    //testing mergeSort time
    {
        Timer timer;
        try
        {
            Sorts<T>::mergeSort(arr, [](const T& a, const T& b) { return (a < b); });
        }
        catch (const Errors& error)
        {
            std::cout << "Process finished with error code = " << error << std::endl;
            exit(0);
        }
        std::cout << "Sorted with merge sort, ";
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
