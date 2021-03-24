# bitwise_operations_cpp


Bitwise operators

| Operator | Meaning | Description |
|:---:|:---:|---|
|  &   | bitwise AND  | Does AND on every bit of two numbers. 1 only if both bits are 1.
|&#124;| bitwise OR   | Does OR on every bit of two numbers.  1 if any of the two bits is 1.
|  ^   | bitwise XOR  | Does XOR on every bit of two numbers. 1 if the two bits are different.
|  ~   | bitwise NOT  | Inverts all bits of it
|  <<  |  left shift  | Left  shifts the bits of the first, the second decides the number of places to shift.
|  `>>`  |  right shift | Right shifts the bits of the first, the second decides the number of places to shift.


## Build

    mkdir build
    cd build
    conan install ..
    cmake ..
    cmake --build .
    ./bitwise_operations_cpp
    ./bitwise_operations_cpp

