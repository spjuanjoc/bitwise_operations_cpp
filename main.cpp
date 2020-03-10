#include <bitset>
#include <iomanip>
#include <iostream>

using namespace std;
/*
& (bitwise AND) does AND on every bit of two numbers. 1 only if both bits are 1.
| (bitwise OR)  Does OR on every bit of two numbers.  1 if any of the two bits is 1.
^ (bitwise XOR) Does XOR on every bit of two numbers. 1 if the two bits are different.
~ (bitwise NOT) Inverts all bits of it
<< (left shift) Left  shifts the bits of the first, the second decides the number of places to shift.
>> (right shift)Right shifts the bits of the first, the second decides the number of places to shift.
*/
void leftShift(const uint8_t& value, const uint8_t& shift)
{
    cout << "Left shift:\n";
    auto val_bs = bitset<8 * sizeof(value)>(value);
    cout << "\t " << +value << setw(8) << setfill(' ') << ": " << val_bs << "\n";

    auto    shifted_bs = bitset<8 * sizeof(value)>(value << shift);
    uint8_t to_int     = shifted_bs.to_ulong();
    cout << "\t"
         << "(" << +value << " << " << +shift << "): " << shifted_bs << " : " << +to_int << "\n";
}
void rightShift(const uint8_t& value, const uint8_t& shift)
{
    cout << "Right shift:\n";
    auto val_bs = bitset<8 * sizeof(value)>(value);
    cout << "\t " << +value << setw(8) << setfill(' ') << ": " << val_bs << "\n";

    auto    shifted_bs = bitset<8 * sizeof(value)>(value >> shift);
    uint8_t to_int     = shifted_bs.to_ulong();
    cout << "\t"
         << "(" << +value << " >> " << +shift << "): " << shifted_bs << " : " << +to_int << "\n";
}
void bwAnd(const uint8_t& value, const string& bit_string = R"(11111111)")
{
    cout << "Bitwise AND for 1 byte\n";
    auto          bs = bitset<8 * 1>(value);
    bitset<8 * 1> mask{bit_string};

    auto    bs2 = ((bs) &mask);
    uint8_t res = bs2.to_ulong();
    cout << setw(4) << setfill(' ') << +value << ": " << bs << "\n";
    cout << "mask: " << mask << " : " << +mask.to_ulong() << "\n";
    cout << "res : " << bs2 << " : " << +res << "\n";
}
void bwOr(const uint8_t& value, const string& bit_string = R"(00000000)")
{
    cout << "Bitwise OR for 1 byte\n";
    auto          bs = bitset<8 * 1>(value);
    bitset<8 * 1> mask{bit_string};

    auto    bs2 = ((bs) | mask);
    uint8_t res = bs2.to_ulong();
    cout << setw(4) << setfill(' ') << +value << ": " << bs << "\n";
    cout << "mask: " << mask << " : " << +mask.to_ulong() << "\n";
    cout << "res : " << bs2 << " : " << +res << "\n";
}
void bwXOr(const uint8_t& value, const string& bit_string = R"(00000000)")
{
    cout << "Bitwise XOR for 1 byte\n";
    auto          bs = bitset<8 * 1>(value);
    bitset<8 * 1> mask{bit_string};

    auto    bs2 = ((bs) ^ mask);
    uint8_t res = bs2.to_ulong();
    cout << setw(4) << setfill(' ') << +value << ": " << bs << "\n";
    cout << "mask: " << mask << " : " << +mask.to_ulong() << "\n";
    cout << "res : " << bs2 << " : " << +res << "\n";
}
int main()
{
    cout << "Hello, bitwise operators!" << endl;

    leftShift(5, 2);
    rightShift(20, 2);
    bwAnd(5);
    bwAnd(255, R"(00001111)");
    bwOr(5);
    bwOr(255, R"(00001111)");
    bwXOr(5);
    bwXOr(255, "00001111");

    return 0;
}
