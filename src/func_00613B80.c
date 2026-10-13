#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00613B80_arg1 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
};

u32 func_00613B80(s32 arg0, struct func_00613B80_arg1 *arg1) {
    return (u32) (arg1->unk0 | (arg1->unk1 << 8) | (arg1->unk2 << 0x10) | (arg1->unk3 << 0x18));
}
