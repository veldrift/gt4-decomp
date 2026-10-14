typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
struct Obj { char pad[0x104]; s32 f104; char pad108[0x50]; s32 f158; };
struct Bits { s8 bits[8]; s32 first; s32 last; };
extern "C" s32 func_0051B8A8(Obj *, u32);
extern "C" s32 func_00532310(s8, Obj *, s32, u32, u32, s32, s32);
extern "C" s32 func_00519A20(s8 arg0, Obj *arg1, u32 arg2, u32 arg3, s32 arg4, s32 arg5, Bits *arg6) {
    s32 result = 0;
    if (arg2 >= 6U) return 0x17;
    if (arg3 >= 0x100U) return 0x17;
    if (arg4 <= 0) return 0x17;
    if (arg5 == 0) return 0x17;
    if (arg1 == 0) return 0x17;
    if (arg1->f158 == 4) return 0xF;
    if (arg6->last >= 0) {
        for (s32 i=arg6->first; i<=arg6->last; ++i) {
            if (i != arg1->f104 && func_0051B8A8(arg1,i) && ((arg6->bits[i>>3] >> (i&7))&1)) {
                if (func_00532310(arg0,arg1,i,arg2,arg3,arg4,arg5)) result=13;
            }
        }
    }
    return result;
}
