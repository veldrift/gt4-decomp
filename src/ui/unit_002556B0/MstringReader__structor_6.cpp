#include "types.h"
#define NULL 0

extern "C" s32 func_0024DB78(void *arg0, void *arg1);
extern "C" void MReaderBase__structor_0(void *arg0, s32 arg1);
extern char MstringReader__vtable[];

void MstringReader__structor_6(void *arg0, s32 arg1) {
    s32 sp[4];
    s32 vt = (s32)MstringReader__vtable;
    sp[1] = arg1;
    sp[0] = vt;
    func_0024DB78(sp, arg0);
    sp[0] = vt;
    MReaderBase__structor_0(sp, 0);
}
