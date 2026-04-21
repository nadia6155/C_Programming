#include <stdio.h>

#include <string.h>

// int function returns an integer
int sum(int a, int b) {
    return a + b;
}

// void is a function that returns no value 
void greet()
{
    printf("Hello, world!\n");
}

// structures usually kept outside main as global variables
struct person {
    char name[30];
    int age;
};

// function to take pointer to structure age and add 1 (e.g. for bday)
void updateAge(struct person *c) {
    c->age++; // add 1 to age (or c->age +=1;)
}

// main function
int main(void)
{

    greet();

    int var;

    var = 10;

    int age = 20;

    float height = 5.7;

    char grade = 'A';

    // double has more accuracy that float (8 bytes instead of 4)
    double pi = 3.14159;

    // %d is the integar data type format specifier
    printf("%d\n", sum(10, 20));

    printf("Age: %d\n", age);

    // %f is the float data type format specifier 
    printf("Height: %.1f\n", height);

    // %c is the char data type format specifier
    printf("Grade: %c\n", grade);

    // %lf is the double data type format specifier 
    printf("Pi: %.5lf\n", pi);

    printf("Initial value: %d\n", var);

    var = 25;

    printf("Updated val: %d\n", var);

    var = var + 5;

    printf("Updated after adding 5 to num: %d\n", var);

    int num = 22;

    // sizeof used to get size
    printf("%d bytes\n", sizeof(num));

    //sizeof data types (z is vlaue of type size_t unsigned int type, u is print as unsigned int)
    printf("The size of int: %d\n", sizeof(int));
    printf("The size of char: %zu\n", sizeof(char));
    printf("the size of float: %zu\n", sizeof(float));
    printf("The size of double: %zu\n", sizeof(double));

    num++;

    printf("Incremented num: %d\n", num);

    num--;

    printf("Decremented num: %d\n", num);
    
    // new variable adding an int and a float 
    float newNum = pi + var;

    printf("New Num: %.3f\n", newNum);

    // +, -, * operators
    printf("age + var = %d\n", age + var);
    printf("age - var = %d\n", age - var);
    printf("age * var %d\n", age * var);

    // ONLY IN DECLARATION: * deference operator creates pointer variable. & address of operator returns address of variable
    int* add_of_age = &age;

    // DEFERENCE OPERATOR*- print value at address of variable
    printf("Pointer deference* - Print value at the address of age: %d\n", *add_of_age);

    // print address of age 
    printf("Pointer reference - Print pointer memory address: %p\n", add_of_age);
    printf("Point to mem addr of age and print: %p\n", &age);

    // print memory address of newNum
    printf("Point to mem addr of newNum and print: %p\n", &newNum);

    // array
    int someNumbers[5] = {0, 10, 15, 25, 50};

    // point to someNumbers[0]
    int *p = someNumbers;

    // POINTER ARITHMETIC
    printf("Pointer at someNumbers[0], print value with deference operator: %d\n", *p);
    printf("Add 1 to pointer at someNumbers array, print val with * operator: %d\n", *(p+1));
    printf("Move pointer to last int in someNumbers array, and print value using deference operator: %d\n", *(p+4));

    // increment the pointer 
    p++;
    printf("Incremented pointer to next int in someNumbers array: %d\n", *p);

    // decrement the pointer
    p--;
    printf("Decremented pointer back to previous int in someNumbers array: %d\n", *p);

    // pointer to pointer 
    int pointerVar = 3; // variable
    int *pointer = &pointerVar; // pointer to variable
    int **ptr2ptr = &pointer; // pointer to pointer 

    printf("variable: %d\n", pointerVar);
    printf("pointer to variable: %d\n", *pointer);
    printf("pointer to pointer: %d\n", **ptr2ptr);

    // change value of variable using pointer to pointer
    **ptr2ptr = 5; // changes original value pointerVariable
    printf("changed original value using pointer to pointer: %d\n", pointerVar);

    // structures group variable together
    //initialise struct
    struct fruitStructure {
        int code;
        char fruitName[10];
        float price;
    };

    // create a variable for the structure 
    struct fruitStructure s1;

    // assign values to the structure
    s1.code = 1;
    strcpy(s1.fruitName, "apple"); // use strcpy for strings from <string.h>
    s1.price = 1.99;

    printf("My structure variable name is: %s\n", s1.fruitName);
    printf("The price of the fruit is: %.2f\n", s1.price);

    // other struct syntax for variables
    struct fruitStructure s2 = {2, "cherry", 2.50};

    printf("Fruit code is: %d. Fruit name is: %s. Fruit price is: %.2f.\n", s2.code, s2.fruitName, s2.price);

    // modify struct variable 
    s2.price = 3.00;
    printf("The new price for %s is %.2f.\n", s2.fruitName, s2.price);

    // nested structure
    struct ownerStructure {
        char name[20];
        int age;
    };

    struct carStructure {
        int carID;
        char carName[20];
        char location[10];
        struct ownerStructure owner; // nested structure
    };

    struct ownerStructure owner1 = {"Nadia M", 27};

    struct carStructure car1 = {1, "Ford KA", "London", owner1};

    printf("Car is %s and car owner is %s.\n", car1.carName, car1.owner.name);


    // pointer to a structure variable
    struct carStructure *ptr = &car1;

    // access structure values using -> operator for pointer
    printf("Car name: %s\n", ptr->carName);
    printf("Location: %s\n", ptr->location);

    // struct is outside main, made variable here
    struct person person1 = {"Rowan", 28};
    printf("Rowan age before bday (pointer/func change): %d\n", person1.age);
    updateAge(&person1); // pass pointer to the function to it can update the age
    printf("Rowan age after bday (pointer/func change): %d\n", person1.age);

    return 0;
}