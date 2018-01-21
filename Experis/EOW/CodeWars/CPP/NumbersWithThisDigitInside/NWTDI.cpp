#include <iostream>
#include <vector>

std::vector<long> numbersWithDigitInside(long x, long d)
{
    std::vector<long> result;
    
    return result;
}


Describe(ExampleTests)
{
    It(Test1)
    {
        std::vector<long> expected = { 0, 0, 0 };
        std::vector<long> actual = numbersWithDigitInside(5, 6);
    
        Assert::That(actual, Is().EqualToContainer(expected));
    }
    
    It(Test2)
    {
        std::vector<long> expected = { 1, 6, 6 };
        std::vector<long> actual = numbersWithDigitInside(7, 6);
    
        Assert::That(actual, Is().EqualToContainer(expected));
    }
    
    It(Test3)
    {
        std::vector<long> expected = { 3, 22, 110 };
        std::vector<long> actual = numbersWithDigitInside(11, 1);
    
        Assert::That(actual, Is().EqualToContainer(expected));
    }
    
    It(Test4)
    {
        std::vector<long> expected = { 2, 30, 200 };
        std::vector<long> actual = numbersWithDigitInside(20, 0);
        
        Assert::That(actual, Is().EqualToContainer(expected));
    }
    
    It(Test5)
    {
        std::vector<long> expected = { 9, 286, 5955146588160 };
        std::vector<long> actual = numbersWithDigitInside(44, 4);
    
        Assert::That(actual, Is().EqualToContainer(expected));
    }
};







