struct Ref{int p;operator int()const{return p;}};
#include "types.h"
#include "m2c_macros.h"
#define NULL 0

extern "C" M2C_UNK func_001540C8(s32, Ref *, s32, s32, s32, f32); /* extern */
extern "C" M2C_UNK func_0021B328(Ref *, void *);               /* extern */
extern "C" M2C_UNK func_0021B340(void *, M2C_UNK);             /* extern */
extern "C" M2C_UNK func_0025A7E0(Ref *, void *);               /* extern */
extern "C" M2C_UNK func_0026A118(Ref *, M2C_UNK);              /* extern */
extern "C" M2C_UNK func_0026AC20(void *, int, s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

extern "C" void func_0013A570(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 fparg0) {
    struct StackFrame_0013A570 { s32 sp0; s8 pad0[0xC]; Ref sp10; s8 pad1[0xC]; } sp_;

    func_0025A7E0(&sp_.sp10, arg0);
    func_0026AC20(((s8 *)&sp_), sp_.sp10, arg1, 1, 0, 1);
    func_0026A118(&sp_.sp10, 2);
    if (sp_.sp0 != 0) {
        func_0021B328(&sp_.sp10, ((s8 *)&sp_));
        func_001540C8(M2C_FIELD(arg0, Ref *, 0x2A4), &sp_.sp10, arg2, arg3, arg4, fparg0);
    }
    func_0021B340(((s8 *)&sp_), 2);
}
