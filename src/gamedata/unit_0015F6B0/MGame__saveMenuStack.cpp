typedef int s32;

struct Inner001662B8 {
    char pad0[0x10];
    s32 unk10;
};

struct Buf001662B8 {
    struct Inner001662B8 *ptr;
    char pad4[0xC];
};

extern "C" void func_0015F388(void *arg0, int arg1);
extern "C" void *func_0015F3E0(void *arg0, void *arg1);
extern "C" void func_0042FE88(s32 a);

extern "C" void MGame__saveMenuStack(void *arg0, void *arg1) {
    struct Buf001662B8 buf;
    struct Inner001662B8 *p;

    func_0015F3E0(&buf, arg1);
    p = buf.ptr;
    func_0042FE88(p->unk10 + 0x3A368);
    func_0015F388(&buf, 2);
}
