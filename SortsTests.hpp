#ifndef MAIN_CPP_SORTSTESTS_HPP
#define MAIN_CPP_SORTSTESTS_HPP

#include "Sorts.hpp"
#include <cassert>
#include <memory>

class SortsTests
{
public:
    static void allTestsTogether();

private:
    static void quickSortTests();
    static void quickSortRandomTest();
    static void quickSortSortedTest();
    static void quickSortReverseTest();
    static void quickSortRepetitionTest();
    static void quickSortSmallTest();
    static void quickSortStringTest();
    static void quickSortFloatTest();

    static void shellSortTests();
    static void shellSortRandomTest();
    static void shellSortSortedTest();
    static void shellSortReverseTest();
    static void shellSortRepetitionTest();
    static void shellSortSmallTest();
    static void shellSortStringTest();
    static void shellSortFloatTest();

    static void mergeSortTests();
    static void mergeSortRandomTest();
    static void mergeSortSortedTest();
    static void mergeSortReverseTest();
    static void mergeSortRepetitionTest();
    static void mergeSortSmallTest();
    static void mergeSortStringTest();
    static void mergeSortFloatTest();

    static void radixSortTests();
    static void radixSortRandomTest();
    static void radixSortSortedTest();
    static void radixSortReverseTest();
    static void radixSortRepetitionTest();
    static void radixSortSmallTest();
    static void radixSortStringTest();
};

void SortsTests::quickSortTests()
{
    quickSortRandomTest();
    quickSortSortedTest();
    quickSortReverseTest();
    quickSortRepetitionTest();
    quickSortSmallTest();
    quickSortStringTest();
    quickSortFloatTest();
}

void SortsTests::shellSortTests()
{
    shellSortRandomTest();
    shellSortSortedTest();
    shellSortReverseTest();
    shellSortRepetitionTest();
    shellSortSmallTest();
    shellSortStringTest();
    shellSortFloatTest();
}

void SortsTests::mergeSortTests()
{
    mergeSortRandomTest();
    mergeSortSortedTest();
    mergeSortReverseTest();
    mergeSortRepetitionTest();
    mergeSortSmallTest();
    mergeSortStringTest();
    mergeSortFloatTest();
}

void SortsTests::radixSortTests()
{
    radixSortRandomTest();
    radixSortSortedTest();
    radixSortReverseTest();
    radixSortRepetitionTest();
    radixSortSmallTest();
    radixSortStringTest();
}

void SortsTests::allTestsTogether()
{
    quickSortTests();
    shellSortTests();
    mergeSortTests();
    radixSortTests();
}

void SortsTests::quickSortRandomTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({1, 17, 3, 4, 24, -5, 19, 14, 2}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({-5, 1, 2, 3, 4, 14, 17, 19, 24}));
    Sorts<int>::quickSort(seq.get(), 0, seq->getLength(), [](const int& a, const int&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::quickSortSortedTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({-5, 1, 2, 3, 4, 14, 17, 19, 24}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({-5, 1, 2, 3, 4, 14, 17, 19, 24}));
    Sorts<int>::quickSort(seq.get(), 0, seq->getLength(), [](const int& a, const int&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::quickSortReverseTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({24, 19, 17, 14, 4, 3, 2, 1, -5}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({-5, 1, 2, 3, 4, 14, 17, 19, 24}));
    Sorts<int>::quickSort(seq.get(), 0, seq->getLength(), [](const int& a, const int&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::quickSortRepetitionTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({1, 1, 1, 1, 1, 2, 1, 1, 1}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({1, 1, 1, 1, 1, 1, 1, 1, 2}));
    Sorts<int>::quickSort(seq.get(), 0, seq->getLength(), [](const int& a, const int&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::quickSortSmallTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({2, -5, 3}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({-5, 2, 3}));
    Sorts<int>::quickSort(seq.get(), 0, seq->getLength(), [](const int& a, const int&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::quickSortStringTest()
{
    std::unique_ptr<Sequence<std::string>> seq(new ArraySequence<std::string>({"aedb", "gyuld", "abcd", "aaaa", "zzzzz", "xxxx"}));
    std::unique_ptr<Sequence<std::string>> sorted(new ArraySequence<std::string>({"aaaa", "abcd", "aedb", "gyuld", "xxxx", "zzzzz"}));
    Sorts<std::string>::quickSort(seq.get(), 0, seq->getLength(), [](const std::string& a, const std::string&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::quickSortFloatTest()
{
    std::unique_ptr<Sequence<float>> seq(new ArraySequence<float>({-1.5, 7.6, 111111.1, -111111.1}));
    std::unique_ptr<Sequence<float>> sorted(new ArraySequence<float>({-111111.1, -1.5, 7.6, 111111.1}));
    Sorts<float>::quickSort(seq.get(), 0, seq->getLength(), [](const float& a, const float&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::shellSortRandomTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({1, 17, 3, 4, 24, -5, 19, 14, 2}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({-5, 1, 2, 3, 4, 14, 17, 19, 24}));
    Sorts<int>::shellSort(seq.get(), [](const int& a, const int&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::shellSortSortedTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({-5, 1, 2, 3, 4, 14, 17, 19, 24}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({-5, 1, 2, 3, 4, 14, 17, 19, 24}));
    Sorts<int>::shellSort(seq.get(), [](const int& a, const int&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::shellSortReverseTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({24, 19, 17, 14, 4, 3, 2, 1, -5}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({-5, 1, 2, 3, 4, 14, 17, 19, 24}));
    Sorts<int>::shellSort(seq.get(), [](const int& a, const int&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::shellSortRepetitionTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({1, 1, 1, 1, 1, 2, 1, 1, 1}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({1, 1, 1, 1, 1, 1, 1, 1, 2}));
    Sorts<int>::shellSort(seq.get(), [](const int& a, const int&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::shellSortSmallTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({2, -5, 3}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({-5, 2, 3}));
    Sorts<int>::shellSort(seq.get(), [](const int& a, const int&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::shellSortStringTest()
{
    std::unique_ptr<Sequence<std::string>> seq(new ArraySequence<std::string>({"aedb", "gyuld", "abcd", "aaaa", "zzzzz", "xxxx"}));
    std::unique_ptr<Sequence<std::string>> sorted(new ArraySequence<std::string>({"aaaa", "abcd", "aedb", "gyuld", "xxxx", "zzzzz"}));
    Sorts<std::string>::shellSort(seq.get(), [](const std::string& a, const std::string&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::shellSortFloatTest()
{
    std::unique_ptr<Sequence<float>> seq(new ArraySequence<float>({-1.5, 7.6, 111111.1, -111111.1}));
    std::unique_ptr<Sequence<float>> sorted(new ArraySequence<float>({-111111.1, -1.5, 7.6, 111111.1}));
    Sorts<float>::shellSort(seq.get(), [](const float& a, const float&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::mergeSortRandomTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({1, 17, 3, 4, 24, -5, 19, 14, 2}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({-5, 1, 2, 3, 4, 14, 17, 19, 24}));
    Sorts<int>::mergeSort(seq.get(), [](const int& a, const int&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::mergeSortSortedTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({-5, 1, 2, 3, 4, 14, 17, 19, 24}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({-5, 1, 2, 3, 4, 14, 17, 19, 24}));
    Sorts<int>::mergeSort(seq.get(), [](const int& a, const int&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::mergeSortReverseTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({24, 19, 17, 14, 4, 3, 2, 1, -5}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({-5, 1, 2, 3, 4, 14, 17, 19, 24}));
    Sorts<int>::mergeSort(seq.get(), [](const int& a, const int&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::mergeSortRepetitionTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({1, 1, 1, 1, 1, 2, 1, 1, 1}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({1, 1, 1, 1, 1, 1, 1, 1, 2}));
    Sorts<int>::mergeSort(seq.get(), [](const int& a, const int&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::mergeSortSmallTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({2, -5, 3}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>( {-5, 2, 3}));
    Sorts<int>::mergeSort(seq.get(), [](const int& a, const int&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::mergeSortStringTest()
{
    std::unique_ptr<Sequence<std::string>> seq(new ArraySequence<std::string>({"aedb", "gyuld", "abcd", "aaaa", "zzzzz", "xxxx"}));
    std::unique_ptr<Sequence<std::string>> sorted(new ArraySequence<std::string>({"aaaa", "abcd", "aedb", "gyuld", "xxxx", "zzzzz"}));
    Sorts<std::string>::mergeSort(seq.get(), [](const std::string& a, const std::string&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::mergeSortFloatTest()
{
    std::unique_ptr<Sequence<float>> seq(new ArraySequence<float>({-1.5, 7.6, 111111.1, -111111.1}));
    std::unique_ptr<Sequence<float>> sorted(new ArraySequence<float>({-111111.1, -1.5, 7.6, 111111.1}));
    Sorts<float>::mergeSort(seq.get(), [](const float& a, const float&b) { return (a < b); });
    assert(*seq == *sorted);
}

void SortsTests::radixSortRandomTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({1, 17, 3, 4, 24, -5, 19, 14, 2}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({-5, 1, 2, 3, 4, 14, 17, 19, 24}));
    Sorts<int>::radixSort(seq.get(), 2, 300);
    assert(*seq == *sorted);
}

void SortsTests::radixSortSortedTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({-5, 1, 2, 3, 4, 14, 17, 19, 24}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({-5, 1, 2, 3, 4, 14, 17, 19, 24}));
    Sorts<int>::radixSort(seq.get(), 2, 300);
    assert(*seq == *sorted);
}

void SortsTests::radixSortReverseTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({24, 19, 17, 14, 4, 3, 2, 1, -5}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({-5, 1, 2, 3, 4, 14, 17, 19, 24}));
    Sorts<int>::radixSort(seq.get(), 2, 300);
    assert(*seq == *sorted);
}

void SortsTests::radixSortRepetitionTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({1, 1, 1, 1, 1, 2, 1, 1, 1}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({1, 1, 1, 1, 1, 1, 1, 1, 2}));
    Sorts<int>::radixSort(seq.get(), 2, 300);
    assert(*seq == *sorted);
}

void SortsTests::radixSortSmallTest()
{
    std::unique_ptr<Sequence<int>> seq(new ArraySequence<int>({2, -5, 3}));
    std::unique_ptr<Sequence<int>> sorted(new ArraySequence<int>({-5, 2, 3}));

    Sorts<int>::radixSort(seq.get(), 2, 300);
    assert(*seq == *sorted);
}

void SortsTests::radixSortStringTest()
{
    std::unique_ptr<Sequence<std::string>> seq(new ArraySequence<std::string>({"aedb", "gyuld", "abcd", "aaaa", "zzzzz", "xxxx"}));
    std::unique_ptr<Sequence<std::string>> sorted(new ArraySequence<std::string>({"aaaa", "abcd", "aedb", "gyuld", "xxxx", "zzzzz"}));
    Sorts<std::string>::radixSort(seq.get(), 2, 300);
    assert(*seq == *sorted);
}

#endif
