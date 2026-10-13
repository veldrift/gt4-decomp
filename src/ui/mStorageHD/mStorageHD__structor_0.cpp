#include "types.h"
#define NULL 0

extern char D_00699010[];
extern char mStorageHD__vtable[];
s32 mStorage__structor_0(void *arg0);
void func_00240398(s32, s32 *);
void *func_00326750(unsigned int size, int align, const char *name);

void mStorageHD__structor_0(s32 arg0) {
    s32 sp[4];
    void *temp_v0;
    temp_v0 = func_00326750(0x14, 4, D_00699010);
    mStorage__structor_0(temp_v0);
    ((void **)temp_v0)[1] = mStorageHD__vtable;
    sp[0] = (s32)temp_v0;
    func_00240398(arg0, sp);
}
