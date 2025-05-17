/*
 * Fibonacci.cpp
 *
 *  Created on: 2025年5月13日
 *      Author: wangb
 */

#include <iostream>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {

    //for (int n = 0; n <= 25; ++n) {
        //std::cout << "fibonacci(" << n << ") = " << fibonacci(n) << std::endl;
    //}
    for (int n = 0; n <= 42; ++n) {
            std::cout << "fibonacci(" << n << ") = " << fibonacci(n) << std::endl;
    }
    return 0;
}



