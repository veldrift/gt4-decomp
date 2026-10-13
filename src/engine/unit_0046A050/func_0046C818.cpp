typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Buf;

struct Arg1 {
    char pad0[0x1C];
    u8 b1C;
    u8 b1D;
    char pad1[6];
    s32 w24;
    s32 w28;
    s32 w2C;
    s32 w30;
    s32 w34;
};

extern char D_006ABAA8[];

extern "C" void func_0046F300(Buf *b, int c);
extern "C" void func_0046F378(Buf *b, unsigned int c);
extern "C" void func_0046F400(Buf *b, s32 a, s32 c);
extern "C" s32 func_0057F260(char *s);

extern "C" void func_0046C818(s32 arg0, struct Arg1 *arg1) {
    Buf *b = (Buf *)(arg0 + 0x85C);
    s32 n;

    func_0046F378(b, 0xFFE0);
    func_0046F378(b, 0x10);
    n = func_0057F260(D_006ABAA8);
    func_0046F400(b, (s32)D_006ABAA8, n + 1);
    func_0046F300(b, arg1->b1C);
    func_0046F300(b, arg1->b1D);
    func_0046F300(b, arg1->w24);
    func_0046F378(b, arg1->w28);
    func_0046F378(b, arg1->w2C);
    func_0046F300(b, arg1->w30);
    func_0046F300(b, arg1->w34);
}
