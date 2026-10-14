typedef int s32;

struct Blob {
    char d[0x64];
};
struct Hdr {
    s32 a, b, c, d, e;
};
struct Msg {
    s32 f0;
    Hdr hdr;
    char buf[0x64];
    s32 f7C;
    s32 f80;
};

void *memcpy(void *, const void *, unsigned int);
extern s32 D_00853538;
extern s32 D_0064A2D8;
extern void (*D_0064A304)();
extern s32 D_0064A248;
extern Hdr D_0064A200;

extern "C" {
int func_0050A958() throw();
int func_0050A968();
int func_0050B460(int, int, int, Msg *);
void func_005075C0();
int func_005A6AB0(void *, void *, s32) throw();
}

extern "C" s32 func_005070E8(Blob local, s32 arg1, s32 arg2, s32 arg3)
{
    Msg msg;

    if (D_00853538 != 0) {
    if (func_0050A968() != 1) {
        return -5;
    }
    if (func_0050A958() == 0) {
        return -6;
    }
    D_0064A2D8 = arg2;
    D_0064A304 = func_005075C0;
    msg.f0 = arg3;
    D_0064A248 = 0;
    msg.hdr = D_0064A200;
    func_005A6AB0(msg.buf, &local, 0x64);
    msg.f80 = arg1;
    msg.buf[0x63] = 0;
    msg.f7C = 0;
    return func_0050B460(1, 0xE4, 0x84, &msg) == 0 ? 0 : -7;
    }
    return -5;
}
