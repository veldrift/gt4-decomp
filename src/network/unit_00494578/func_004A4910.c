#include "spr.h"
typedef unsigned long long u64;
struct Spr { char pad[0x1D8]; u64 value; };
static inline void enable(struct Spr *p, u64 mask) { struct Spr *spr = p; spr->value |= mask; }
void func_004A4910(void) {
    enable((struct Spr *)spr_base(), 1ULL << 41);
}
