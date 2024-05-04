#include <iostream>

using namespace std;

int main()
{   // Lambda Function Signature

    /*
         Syntax:
         [capture list] (parameter list){
          function body
        }
*/
    /* First Way to Define Lambda Function
    auto func = [] (){
        cout << "Defining Lambda Function in first way." << endl;
    };

    func(); // calling defined Lambda Function.
     */

    /*
      Second Way to Define Lambda Function
    [] () {
        cout << "Defing Lambda function in second way." << endl;
    }();
    */

    /* Defining the Lambda funtion that takes parameter
    [](int a, int b){
        cout << "The Sum of a + b is: " << a + b << endl;
    }(7,3);
    */

     /* // Define a labda that returns something
     int sum =[](int a, int b)->int{
         return a + b;
     }(7,3);

     cout << "The sum of a + b is: " << sum << endl;
     */

    /* // Capture list

    int a = 7;
    int b = 8;

    [a, b] () {
        cout << "The value of A is: " << a << endl;
         cout << "The value of B is: " << b << endl;
    }();
     */

    /* // Capturing by value
    int c = 42;

    auto func = [c] () {

        cout << "The inner value of c is: " << c << endl;
    };

    for(int i=1 ; i<5 ; i++){
        cout << "The outer value of c is: " << c << endl;
        func();
        c += 1;
    }
    */

    /* // Capturing by Reference
    int c = 42;

    auto func = [&c] () { // here we are passing address here just like we do while working with pointers.

        cout << "The inner value of c is: " << c << endl;
    };

    for(int i=1 ; i<5 ; i++){
        cout << "The outer value of c is: " << c << endl;
        func();
        c += 1;
    }
    */

    /* // Capturing everything by value
    int c = 42;
    int d = 50;

    auto func = [=] () { // By putting "=" sign here we are capturing everything

        cout << "The inner value of c is: " << c << endl;

        cout << "The inner value of d is: " << d << endl;
    };

    for(int i=1 ; i<5 ; i++){
        cout << "The outer value of c is: " << c << endl;

        cout << "The outer value of d is: " << d << endl;
        func();
        c += 1;

        d += 1;
    }
     */

    // Capturing everything by reference
    int c = 42;
    int d = 50;

    auto func = [&] () { // By putting "=" sign here we are capturing everything

        cout << "The inner value of c is: " << c << endl;

        cout << "The inner value of d is: " << d << endl;
    };

    for(int i=1 ; i<5 ; i++){
        cout << "The outer value of c is: " << c << endl;

        cout << "The outer value of d is: " << d << endl;
        func();
        c += 1;

        d += 1;
    }

    return 0;
}
