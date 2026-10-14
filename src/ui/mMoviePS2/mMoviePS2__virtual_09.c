/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern char D_00618E40[];
struct mMoviePS2 {
    s32 unk0;
    void * unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};
void mMoviePS2__virtual_09(struct mMoviePS2 *arg0, void **arg1) {
    if (M2C_FIELD(*arg1, s32 *, -0x10) != 0) {
        arg0->unkC = 0;
        arg0->unk10 = 0;
        if (arg0->unk8 == 0) {
            arg0->unk8 = 1;
            func_001FE288((void *)(s32)D_00618E40, (s32) arg1);
            return;
        }
        func_001FE2B8((void *)(s32)D_00618E40, (s32) arg1, 0);
    }
}
