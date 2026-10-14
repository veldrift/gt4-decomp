/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned short u16;
typedef short s16;
struct Obj { char pad[0x1C]; s32 mode; };
extern "C" s32 func_004B8CC8(s16 *, s32, s32, s32);
extern "C" s32 func_004B91A8(s16 *, s32, s32, const u16 *);
extern "C" s32 func_004B9300(s16 *, s32);
extern "C" s32 func_004B93E0(const u16 *);
extern "C" s32 func_004B6230(Obj *arg0, s16 *arg1, const u16 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 result = 0;
    if (arg0->mode == 0) {
        s32 ok = 0;
        if (arg4 >= 2) {
            const u16 *end = arg2 + arg3;
            s32 first = func_004B93E0(end - 2);
            result = 2;
            ok = func_004B8CC8(arg1, first, func_004B93E0(end - 1), arg5);
            if (ok == 0) result = 0;
        }
        if (ok == 0) {
            if (arg4 > 0) {
                ok = func_004B8CC8(arg1, func_004B93E0(arg2 + arg3 - 1), arg5, 0);
                if (ok != 0) result = 1;
            }
            if (ok == 0) {
                if (arg4 >= 0) {
                    ok = func_004B8CC8(arg1, arg5, 0, 0);
                    if (ok != 0) result = 0;
                }
                if (ok == 0) { func_004B9300(arg1, arg5); result = 0; }
            }
        }
    } else {
        s32 ok = 0;
        if (arg4 > 0) {
            ok = func_004B91A8(arg1, arg5, arg6, arg2 + arg3 - 1);
            result = ok != 0;
        }
        if (ok == 0) {
            if (arg4 >= 0) {
                ok = func_004B91A8(arg1, arg5, arg6, 0);
                if (ok != 0) result = 0;
            }
            if (ok == 0) { func_004B9300(arg1, arg5); result = 0; }
        }
    }
    return result;
}
