typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" int func_00578B50(unsigned int mode, int c);
extern "C" u8 *func_00578610(u8 *arg0);
extern "C" char *func_005750C0(char *a, u8 *b);
extern "C" s32 func_005788B8(void *p);
extern char D_00555208[];

struct func_00555180_pair {
    void *p;
    s32 n;
};

struct func_00555180_self {
    char pad0[0x4D4];
    s32 unk4D4;
    s32 unk4D8;
    s32 unk4DC;
    s32 unk4E0;
};

extern "C" void func_00555180(char *arg0) {
    struct func_00555180_self *self = (struct func_00555180_self *)arg0;
    struct func_00555180_pair tmp;
    char *r;
    u8 *q;

    self->unk4DC = 0;
    self->unk4E0 = 1;
    self->unk4D8 = 0;
    self->unk4D4 = 0;
    q = func_00578610((u8 *)func_00578B50(3, 0));
    r = func_005750C0(arg0 + 0x4E8, q);
    tmp.p = (void *)D_00555208;
    tmp.n = 0;
    *(struct func_00555180_pair *)(r + 0x38) = tmp;
    func_005788B8(r);
}
