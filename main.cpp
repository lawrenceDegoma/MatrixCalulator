// Matrix arithmetic

#include <iostream>
#include<ctime>
#include <cstdlib>
#include "Matrix.h"


int main() {
    srand(time(0));
    int c1,r1;
    std::cout<<"Choose the size of the row of the first matrix: ";
    std::cin>>r1;
    std::cout<<"Choose the size of the column of the first matrix: ";
    std::cin>>c1;

    Matrix x(r1, c1);

    int c2, r2;
    std::cout << "Choose the size of the row of the second matrix: ";
    std::cin >> r2;
    std::cout << "Choose the size of the column of the second matrix: ";
    std::cin >> c2;

    Matrix y(r2, c2);

    std::cout << "\n";
    x.printMatrix();
    std::cout << "\n";
    y.printMatrix();

    std::cout<<"\nAddition: \n";
    Matrix z = x + y;
    z.printMatrix();

    std::cout<<"\nSubtraction: \n";
    Matrix a = x - y;
    a.printMatrix();


    std::cout<<"\nMultiplication: \n";
    Matrix b = x * y;
    b.printMatrix();

    char ans;
    std::cout << "Try again? (Y/N): ";
    std::cin >> ans;
    if (ans == 'y' || ans == 'y')
        main();
    else {
        std::cout << "Exiting. Have a nice day!\n";
        exit(0);
    }
}