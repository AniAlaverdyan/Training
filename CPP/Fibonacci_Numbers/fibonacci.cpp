#include <iostream>

int Fibonacci(int n)
{
    if(n > 2)
    {
        int a = 0;
	int b = 1;
        int count = 2;
	std::cout << a << std::endl;
        std::cout << b << std::endl;
	while (count < n)
	{
	    b = a + b;
	    a = b - a;
	    std::cout << b << std::endl;
	    count++;
	}     
    }
    else if(n == 1) {std::cout << "0" << std::endl;}
    else if(n == 2) {std::cout << "0\n1";}
    else {std::cout << "Wrong input.";}
}

int main()
{
    int fibo_numbers;
    std::cout << "Enter a number: "; 
    std::cin >> fibo_numbers;
    Fibonacci(fibo_numbers);

    return 0;
}
