/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" void *func_00105378(void *);
extern "C" void *func_001054D8(void *, s32, s32, s32, s32);
extern "C" void *func_001056A0(void *);
extern "C" void *pglPushAttrib(s32);
extern "C" void *func_004A3088(f32);
extern "C" void *func_004A3230(s32);
extern "C" void *func_004A5688();
extern "C" void func_00105280(void *, s32);

extern "C" void func_00341D88(char *arg0) {
    char sp[0x40];
    func_00105378(sp);
    func_001054D8(sp, *(f32 *)(arg0 + 0xE2E0), *(f32 *)(arg0 + 0xE2E4), *(f32 *)(arg0 + 0xE2E8), *(f32 *)(arg0 + 0xE2EC));
    pglPushAttrib(0x887);
    func_001056A0(sp);
    func_004A3088(0x0.0p+0f);
    func_004A3230(2);
    func_004A3088(1.0f);
    func_004A5688();
    func_00105280(sp, 2);
}
