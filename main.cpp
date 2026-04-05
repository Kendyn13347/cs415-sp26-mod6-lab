#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// ============================================================
// Part 1: Primitive Data Types (Task 1A)
// ============================================================
void part1_primitives() {
    int a = 10;                // Standard integer
    float b = 3.14;            // Single-precision floating point
    double c = 3.1415926535;   // Double-precision floating point
    bool flag = true;          // Boolean (0 or 1)
    char ch = 'A';             // Single 8-bit character
    cout << a << " " << b << " " << c << " " << flag << " " << ch << endl;
}

// ============================================================
// Part 2: Strings and Memory (Task 2A)
// ============================================================
void part2_strings() {
    char str1[] = "Hello";    // Fixed size array
    char str2[20];            // Buffer of 20 bytes
    strcpy(str2, str1);       // Copying content
    strcat(str2, " World");   // Concatenating content
    cout << str2 << endl;
}

// ============================================================
// Part 3A: Static Arrays
// ============================================================
void part3a_static() {
    int arr[] = {1,2,3,4,5};
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
    cout << "Size: " << sizeof(arr) << " bytes" << endl;
}

// ============================================================
// Part 3B: Dynamic Arrays
// ============================================================
void part3b_dynamic() {
    int size = 5;
    int* dyn = new int[size]{10, 20, 30, 40, 50};
    for (int i = 0; i < size; i++) cout << dyn[i] << " ";
    cout << endl;
    delete[] dyn;
}

// ============================================================
// Part 4: Records (Structs)
// ============================================================
struct Person {
    string name;
    int age;
    double height;
};

void part4_structs() {
    Person p = {"Alice", 30, 5.6};
    cout << "Name: " << p.name << ", Age: " << p.age << ", Height: " << p.height << endl;
    cout << "Struct size: " << sizeof(Person) << " bytes" << endl;
}

// ============================================================
// Part 5: Pointers and References
// ============================================================
void part5_pointers() {
    int x = 42;
    int* ptr = &x;
    int& ref = x;

    cout << "Value: " << x << endl;
    cout << "Via pointer: " << *ptr << endl;
    cout << "Via reference: " << ref << endl;
    cout << "Address of x: " << &x << endl;

    *ptr = 100;
    cout << "After *ptr=100, x = " << x << endl;

    ptr = nullptr;
}

// ============================================================
// Part 6: Memory Layout and Safety Issues
// ============================================================
void part6_memory() {
    int arr[3] = {10,20,30};
    // This prints the hex addresses. Note they are 4 bytes apart.
    cout << &arr[0] << " " << &arr[1] << endl;

    // Dangling pointer example (conceptual):
    int* ptr = new int(10);
    delete ptr;
    // ptr still holds the address, but that memory is now "garbage" or reused.
}

// ============================================================
// Challenge 2: Float Precision Loss
// ============================================================
void challenge2_precision() {
    float large = 1e38f;
    float small = 1.0f;
    float result = large + small;
    cout << "large + small == large? "
         << (result == large ? "YES — precision lost!" : "No") << endl;
}

// ============================================================
// Challenge 3: Out-of-Bounds Access
// ============================================================
void challenge3_oob() {
    int arr[5] = {1, 2, 3, 4, 5};
    // C++ does NOT bounds-check, this is Undefined Behavior
    cout << "arr[10] = " << arr[10] << " <-- garbage/undefined" << endl;
}

// ============================================================
int main() {
     part1_primitives();
     part2_strings();
     part3a_static();
     part3b_dynamic();
     part4_structs();
     part5_pointers();
     part6_memory();
     challenge2_precision();
     challenge3_oob();
    return 0;
}