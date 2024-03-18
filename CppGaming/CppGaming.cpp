#include <iostream>

int hp;
short mp;

int main()
{
    hp = 0b1100; // 0b: 2진법 (bin)
    mp = 0xF; // 0x: 8진법 (hex)

    std::cout << mp;
}