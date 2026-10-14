/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Inner { char pad[0x7C]; s32 unk7C; };
extern "C" void func_00173250(void *, int) throw();
extern "C" void func_001732A8(void *, s32) throw();
extern "C" void MFadeActor__global_0082AD80(s32, s32, s32, s32);
extern "C" void func_002550B8(void *, int);
extern "C" void func_00255110(void *, s32);

extern "C" void MMCFileActor__global_00823FF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Inner *buf0[4];
    s32 buf1[4];
    if (arg2 >= 2) {
        func_001732A8(buf0, arg1);
        s32 *p = buf1;
        func_00255110(p, arg3);
        buf0[0]->unk7C = *p;
        MFadeActor__global_0082AD80(arg0, arg1, arg2 - 1, arg3 + 4);
        func_002550B8(p, 2);
        func_00173250(buf0, 2);
    }
}
