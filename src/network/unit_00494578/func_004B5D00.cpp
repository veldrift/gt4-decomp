#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004B5D00_arg0 {
    char pad0[0x858];
    s32 unk858;
};
struct func_004B5D00_temp_v0 {
    char pad0[0x418];
    s32 unk418;
};

void *func_004B5D00(void *arg0) {
    char *temp_v0;
    s32 n;

    temp_v0 = (char *)arg0 + ((1 - ((struct func_004B5D00_arg0 *)arg0)->unk858) * 0x41C) + 0x20;
    n = ((struct func_004B5D00_temp_v0 *)temp_v0)->unk418;
    n = n + 1;
    return temp_v0 + (n * 8) + 0x218;
}
