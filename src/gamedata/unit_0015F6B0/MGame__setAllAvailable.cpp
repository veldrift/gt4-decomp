typedef int s32;

struct Obj {
    char pad[0x10];
    char *unk10;
};

struct Buf {
    struct Obj *unk0;
    char pad[0xC];
};

extern "C" void func_0015F388(void *arg0, s32 arg1);
extern "C" void func_0015F3E0(void *arg0, void *arg1);

extern "C" void MGame__setAllAvailable(void *arg0, void *arg1) {
    struct Buf buf;
    struct Obj *p;

    func_0015F3E0(&buf, arg1);
    p = buf.unk0;
    *(s32 *)(p->unk10 + 0x38958) = 1;
    func_0015F388(&buf, 2);
}
