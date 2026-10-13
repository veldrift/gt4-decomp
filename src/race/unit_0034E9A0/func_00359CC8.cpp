typedef int s32;

struct Obj_00359C98;

/* Blk: the object reached through [s0 + 0xC]. Fields used: d8 at 0xD8, the
   pointer at 0x14C, the address base at 0xDC. */
struct Blk {
    char pad0[0xD8];
    s32 d8;
    char pad1[0x14C - 0xDC];
    char *p14c;
};

extern "C" void *func_0034C190(s32 arg0, s32 arg1);
extern "C" s32 func_00359C98(Obj_00359C98 *arg0, s32 arg1);
extern "C" void func_00345F78(void *self, s32 n, s32 keep);

extern "C" void func_00359CC8(s32 arg0, s32 arg1, s32 arg2) {
    Obj_00359C98 *s0 = (Obj_00359C98 *)func_0034C190(arg0, arg1);
    func_00359C98(s0, arg2);
    Blk *b = *(Blk **)((char *)s0 + 0xC);
    s32 off = arg2 * 0x14F4;
    char *base = b->p14c;
    s32 v1 = *(s32 *)(base + off + 4);
    s32 a3 = b->d8 ^ 2;
    s32 a1 = 0;
    if (arg2 != 0) a1 = v1;
    if (a3 != 0) a1 = v1;
    func_00345F78((char *)b + 0xDC, a1, 0);
}
