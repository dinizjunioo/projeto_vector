#include<iostream>
#include<vector>

#include "main.h"
#include "vector_tests.h"
//#include "iterator_tests.h"



void run_iterator_tests(void);
void run_move_semantics_tests(void);



int main(void)
{

    constexpr std::array<int, 5> values_i{ 1,2,3,4,5 };
    constexpr std::array<int, 5> source_i{ 6,7,8,9,10 };
    std::cout << ">>> Testing out vector with integers.\n";
    run_regular_vector_tests<int, 5>(values_i, source_i);

    //std::array<std::string, 5> values_s{ "1","2","3","4","5" };
    //std::array<std::string, 5> source_s{ "6","7","8","9","10" };
    //std::cout << ">>> Testing out vector with strings.\n";
    //run_regular_vector_tests<std::string, 5>(values_s, source_s);

    std::cout << ">>> Testing out iterator operations on vector.\n";
    run_iterator_tests();

    //std::cout << ">>> Testing out move sintax operations.\n";
    //run_move_semantics_tests();

    return 1;
}