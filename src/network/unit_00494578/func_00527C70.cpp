typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
struct Obj { char pad0[0x84]; char *unk84; char pad88[0x9C - 0x88]; u16 unk9C; };
extern "C" void func_00527B28(Obj *, u16) throw();
extern "C" s32 func_00527C70(Obj *arg0, u16 a1, u16 a2) {
    s32 found = 0;
    u16 i = 0;
    if (a1 != 0) {
        if (a2 < a1) i = a1 - 1;
    } else {
        i = arg0->unk9C - 1;
    }
    if (a2 < i) {
        char *tbl = arg0->unk84;
        do {
            s32 st = *(s32 *)(tbl + i * 0x44);
            if (st == 3) found = 1;
            if (st == 4) found = 1;
            i = i - 1;
        } while (a2 < i);
    }
    if (found == 0) func_00527B28(arg0, a2);
    return 0;
}
