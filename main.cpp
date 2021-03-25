#include "fmt/core.h"
#include <bitset>

auto leftShift(const uint8_t& value, const uint8_t& shift)
{
  fmt::print("Left shift ({} << {})\n", value, shift);
  auto bit_input = std::bitset<8 * sizeof(value)>(value);
  fmt::print("In : dec: {1:>3} - bitset: {1:#10b}\n", +value, bit_input.to_ulong());

  auto    bit_shifted = std::bitset<8 * sizeof(value)>(value << shift);
  uint8_t out_shifted = bit_shifted.to_ulong();
  fmt::print("Out: dec: {0:>3} - bitset: {0:#10b}\n", out_shifted);
  return +out_shifted;
}

auto rightShift(const uint8_t& value, const uint8_t& shift)
{
  fmt::print("Right shift ({} >> {})\n", value, shift);
  auto bit_input = std::bitset<8 * sizeof(value)>(value);
  fmt::print("In : dec: {1:>3} - bitset: {1:#10b}\n", +value, bit_input.to_ulong());

  auto    bit_shifted = std::bitset<8 * sizeof(value)>(value >> shift);
  uint8_t out_shifted = bit_shifted.to_ulong();
  fmt::print("Out: dec: {0:>3} - bitset: {0:#10b}\n", out_shifted);

  return +out_shifted;
}

auto bitwiseAND(const uint8_t& value, const std::string& bit_string = R"(11111111)")
{
  fmt::print("Bitwise AND ({} & {})\n", value, bit_string);
  auto bit_input = std::bitset<8 * sizeof(value)>(value);
  fmt::print("In : dec: {1:>3} - bitset: {1:#10b}\n", +value, bit_input.to_ulong());

  std::bitset<8 * sizeof(value)> mask{bit_string};

  auto bit_and = (bit_input & mask);
  auto out_int = bit_and.to_ulong();
  fmt::print("Out: dec: {0:>3} - bitset: {0:#10b}\n", out_int);

  return +out_int;
}

auto bitwiseOR(const uint8_t& value, const uint8_t& bit_string = 0)
{
  fmt::print("Bitwise OR ({} | {})\n", value, bit_string);
  auto bit_input = std::bitset<8 * sizeof(value)>(value);
  fmt::print("In : dec: {1:>3} - bitset: {1:#10b}\n", +value, bit_input.to_ulong());

  std::bitset<8 * sizeof(value)> mask{bit_string};

  auto bit_or  = (bit_input | mask);
  auto out_int = bit_or.to_ulong();
  fmt::print("Out: dec: {0:>3} - bitset: {0:#10b}\n", out_int);

  return +out_int;
}

auto bitwiseORstr(const uint8_t& value, const std::string& bit_string = R"(00000000)")
{
  fmt::print("Bitwise OR ({} | {})\n", value, bit_string);
  auto bit_input = std::bitset<8 * sizeof(value)>(value);
  fmt::print("In : dec: {1:>3} - bitset: {1:#10b}\n", +value, bit_input.to_ulong());

  std::bitset<8 * sizeof(value)> mask{bit_string};

  auto bit_or  = (bit_input | mask);
  auto out_int = bit_or.to_ulong();
  fmt::print("Out: dec: {0:>3} - bitset: {0:#10b}\n", out_int);

  return +out_int;
}

auto bitwiseXOR(const uint8_t& lhs, const uint8_t& rhs = 0)
{
  fmt::print("Bitwise XOR ({} | {})\n", lhs, rhs);
  fmt::print("Bitwise XOR ({:b} | {:b})\n", lhs, rhs);
  auto left = std::bitset<8 * sizeof(lhs)>(lhs);
  fmt::print("In : dec: {1:>3} - bitset: {1:#10b}\n", +lhs, left.to_ulong());

  std::bitset<8 * sizeof(rhs)> right{rhs};

  auto bit_or  = (left ^ right);
  auto out_int = bit_or.to_ulong();
  fmt::print("Out: dec: {0:>3} - bitset: {0:#10b}\n", out_int);

  return +out_int;
}

auto bitwiseXORstr(const uint8_t& value, const std::string& bit_string = R"(00000000)")
{
  fmt::print("Bitwise XOR ({} | {})\n", value, bit_string);
  auto bit_input = std::bitset<8 * sizeof(value)>(value);
  fmt::print("In : dec: {1:>3} - bitset: {1:#10b}\n", +value, bit_input.to_ulong());

  std::bitset<8 * sizeof(value)> mask{bit_string};

  auto bit_or  = (bit_input ^ mask);
  auto out_int = bit_or.to_ulong();
  fmt::print("Out: dec: {0:>3} - bitset: {0:#10b}\n", out_int);

  return +out_int;
}

auto bitwiseNOT(const uint8_t& value)
{
  fmt::print("Bitwise NOT (~{})\n", value);
  fmt::print("Bitwise NOT (~{:b})\n", value);
  auto result = std::bitset<8 * sizeof(value)>(value);
  fmt::print("In : dec: {1:>3} - bitset: {1:#10b}\n", +value, result.to_ulong());

  auto bit_not = ~(result);
  auto out_int = bit_not.to_ulong();
  fmt::print("Out: dec: {0:>3} - bitset: {0:#10b}\n", out_int);

  return +out_int;
}

template<typename T>
auto twosComplement(const T& value)
{
  fmt::print("Two's complement\n");
  fmt::print("In : Hex {0:#04X} - Dec: {0:<5} - Bin: {0:#18b}\n", value);

  auto     bit_input       = std::bitset<8 * sizeof(value)>(value);
  auto     bit_not         = ~(bit_input);
  T twos_complement = bit_not.to_ulong() + 1;

  fmt::print("Out: Hex {0:#04X} - Dec: {0:<5} - Bin: {0:#18b}\n", twos_complement);

  return twos_complement;
}

unsigned short toLittleEndian(const unsigned short big)
{
  auto first  = 0x00ff;
  auto second = 0xff00;
  auto bits = 8;
  return (((big & first) << bits) | ((big & second) >> bits));
}

std::string getEndianness()
{
  const int   value{0x01};
  const void* address                   = static_cast<const void*>(&value);
  const auto* least_significant_address = static_cast<const unsigned char*>(address);
  return (*least_significant_address == 0x01) ? "little-endian" : "big-endian";
}

int main()
{
  fmt::print("Bitwise operations with std::bitset \n");
  leftShift(5, 2);
  rightShift(20, 2);
  bitwiseAND(5);
  bitwiseAND(255, R"(00001111)");
  bitwiseOR(5);
  bitwiseOR(5, 255);
  bitwiseORstr(255, R"(00001111)");
  std::bitset<8 * 1> val{R"(11110000)"};
  bitwiseORstr(val.to_ulong(), R"(00001111)");
  std::bitset<8 * 1> val2{5};
  bitwiseORstr(val2.to_ulong(), R"(00001111)");
  bitwiseXOR(5, 15);
  bitwiseXORstr(5, "00001111");
  bitwiseNOT(5);
  const unsigned short number = 0xCEFF;
  twosComplement(number);
  const unsigned char number2 = 0xCE;
  twosComplement(number2);
  const unsigned short number3 = 0x2f34;
  fmt::print("To little-endian {:x} - {:x}\n", number3, toLittleEndian(number3));
  fmt::print("Endianness: {}\n", getEndianness());

  return 0;
}
