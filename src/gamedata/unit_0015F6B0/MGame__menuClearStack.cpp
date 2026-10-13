typedef int s32;

struct Inner {
    char pad0[0x10];
    s32 unk10;
};

struct Buf {
    struct Inner *ptr;
    char pad4[0xC];
};

extern "C" void func_0015F388(void *arg0, s32 arg1);
extern "C" s32 func_0015F3E0(void *arg0, s32 arg1);
extern "C" void func_0042FB48(s32 arg0);

extern "C" void MGame__menuClearStack(void *arg0, s32 arg1) {
    struct Buf g;
    struct Inner *p;

    func_0015F3E0(&g, arg1);
    p = g.ptr;
    func_0042FB48(p->unk10 + 0x3A368);
    func_0015F388(&g, 2);
}
