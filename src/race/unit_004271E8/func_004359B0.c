#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004359B0_arg0 {
    char pad0[0x81E8];
    s64 unk81E8;
};

void func_004359B0(struct func_004359B0_arg0 *arg0, s64 arg1) {
    arg0->unk81E8 = (s64) (arg1 ^ 0x7A726F706C6C525Eu);
}
