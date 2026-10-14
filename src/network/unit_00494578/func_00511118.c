#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00511118_arg0 {
    char pad0[0x40];
    s32 unk40;
    char pad44[0x14];
    s32 unk58;
};
struct func_00511118_arg1 {
    s32 unk0;
    s32 unk4;
};

s32 func_00511118(struct func_00511118_arg0 *arg0, struct func_00511118_arg1 *arg1) {
    if ((arg0 == 0) || (arg1 == 0)) return 1;
    arg1->unk0 = (s32) arg0->unk58;
    arg1->unk4 = (s32) arg0->unk40;
    return 0;
}
