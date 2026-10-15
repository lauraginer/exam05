#include "bigint.hpp"

int main()
{
    const bigint a(42);
    bigint b(21), c, d(1337), e(d);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;

    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "(c += a) = " << (c += a) << std::endl;

    std::cout << "b = " << b << std::endl;
    std::cout << "++b = " << ++b << std::endl;
    std::cout << "b++ = " << b++ << std::endl;

    std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
    std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;
    std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl;

    std::cout << "a =" << a << std::endl;
    std::cout << "d =" << d << std::endl;

    std::cout << "(d < a) = " << (d < a) << std::endl;
    std::cout << "(d <= a) = " << (d <= a) << std::endl;
    std::cout << "(d > a) = " << (d > a) << std::endl;
    std::cout << "(d >= a) = " << (d >= a) << std::endl;
    std::cout << "(d == a) = " << (d == a) << std::endl;
    std::cout << "(d != a) = " << (d != a) << std::endl;

	 // --- Suma y acarreo ---
    std::cout << "99 + 1 = "      << (bigint(99) + bigint(1)) << std::endl;        // 100
    std::cout << "999 + 1 = "     << (bigint(999) + bigint(1)) << std::endl;       // 1000
    std::cout << "0 + 0 = "       << (bigint(0) + bigint(0)) << std::endl;         // 0
    std::cout << "5 + 0 = "       << (bigint(5) + bigint(0)) << std::endl;         // 5
    std::cout << "1 + 99999 = "   << (bigint(1) + bigint(99999)) << std::endl;     // 100000
    std::cout << "123 + 7 = "     << (bigint(123) + bigint(7)) << std::endl;       // 130

    // --- Números enormes (más que un unsigned int) ---
    bigint big(4000000000u);
    big += big;
    big += big;
    std::cout << "big = " << big << std::endl;                // 16000000000

    bigint huge(1);
    huge <<= 40;                                              // 1 con 40 ceros
    std::cout << "huge = " << huge << std::endl;
    std::cout << "huge + 1 = " << (huge + 1) << std::endl;   // 1 con 39 ceros y un 1

}