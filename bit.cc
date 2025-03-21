#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#define sbit(num, ith) num |= (1LL << ith)
#define fbit(num, ith) num ^= (1LL << ith)
#define ubit(num, ith) num &= ~(1LL << ith)
#define isSet(x,ith) (bool)(x & (1LL << ith))
#define clrlsb(num, ith) num = (num & (~((1LL << (ith + 1)) - 1)))
#define clrmsb(num, ith) num = (num & ((1LL << (ith + 1)) - 1))
//__builtin_popcount(x): Counts the number of one’s(set bits) in an integer
//__builtin_parity(x): Returns true(1)(odd number of set bits) false(0)(even number of set bits)
//__builtin_clz(x): cnt leading zeros
//__builtin_ctz(x): Cnt trailing zeros
// __builtin_ffs(x) (Find First Setbit index + 1) from right
// __lg(x) (index of highest setbit) msb