typedef int s32;
typedef long s64;

struct Sub {
    char pad0[0x78];
    s64 f78;
    void *f80;
};

struct Inner {
    char pad0[0x6C];
    Sub *p6C;
};

struct Self {
    Inner *p0;
    char pad4[0x108 - 4];
    char pad108[0x164 - 0x108];
    s32 f164;
    s32 f168;
};

extern "C" void func_005CD8E8(void *arg0);
extern "C" void func_003BFFE8(void *arg0);
extern "C" void func_00394ED8(void *arg0, s64 arg1);
extern "C" void func_00394D48(void *arg0);

extern "C" void func_00335580(Self *arg0) {
    func_005CD8E8((char *)arg0 + 0x108);
    func_005CD8E8((char *)arg0 + 0xF8);
    arg0->f168 = 0;
    {
        Inner *p = arg0->p0;
        arg0->f164 = 0;
        if (p != 0) {
            func_003BFFE8(p->p6C);
            func_00394ED8(arg0->p0->p6C->f80, arg0->p0->p6C->f78);
            func_00394D48(arg0->p0->p6C->f80);
        }
    }
}
