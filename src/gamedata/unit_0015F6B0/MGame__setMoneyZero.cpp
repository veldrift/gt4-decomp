typedef int s32;

struct Inner00163950 {
    char pad0[0x10];
    s32 unk10;
};

struct Buf00163950 {
    struct Inner00163950 *ptr;
    char pad4[0xC];
};

extern "C" void func_0015F388(void *arg0, int arg1);
extern "C" void func_0015F3E0(void *arg0, void *arg1);
extern "C" void func_0043AF88(int a, int b);

extern "C" void MGame__setMoneyZero(void *arg0, void *arg1) {
    struct Buf00163950 buf;
    struct Inner00163950 *p;

    func_0015F3E0(&buf, arg1);
    p = buf.ptr;
    func_0043AF88(p->unk10 + 0x348, 0);
    func_0015F388(&buf, 2);
}
