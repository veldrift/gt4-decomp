typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef float f32;

struct Obj {
    char pad0;        /* 0x00 */
    u8 b1;            /* 0x01 */
    u8 b2;            /* 0x02 */
    char pad3;        /* 0x03 */
    s16 h4;           /* 0x04 */
    s16 h6;           /* 0x06 */
    s16 h8;           /* 0x08 */
    s16 hA;           /* 0x0A */
    char padC[0x20];  /* 0x0C..0x2B */
    f32 f2C;          /* 0x2C */
    f32 f30;          /* 0x30 */
    f32 f34;          /* 0x34 */
    f32 f38;          /* 0x38 */
};

extern "C" void func_003AEC80(void *arg0, s32 arg1, s32 arg2);
extern "C" void func_003AECA0(void *arg0, s32 arg1, s32 arg2);
extern "C" s32 func_003AFD78(s32 x, s32 w, s32 fl);

extern "C" void func_003A9F00(void *arg0, s32 arg1, s32 arg2) {
    Obj *self = (Obj *)arg0;
    char *s4 = (char *)arg0 + 0xE0;
    char *s5 = (char *)arg0 + 0x74;
    char *s6 = (char *)arg0 + 0x3C;
    char *s7 = (char *)arg0 + 0x150;
    s32 a;
    s32 b;
    s32 x;
    s32 y;

    func_003AEC80(arg0, arg1, arg2);
    a = func_003AFD78(self->h4, self->h8, self->b1);
    b = func_003AFD78(self->h6, self->hA, self->b2);
    x = a + self->h8;
    y = b + self->hA;
    self->f30 = (f32)b;
    self->f2C = (f32)a;
    self->f34 = (f32)x;
    self->f38 = (f32)y;
    func_003AEC80(s4, x - 0x24, y - 0xC);
    func_003AECA0(s4, 1, 1);
    func_003AEC80(s5, x - 0x91, y - 0xC);
    func_003AECA0(s5, 1, 1);
    func_003AEC80(s6, x - 0x12C, y - 0xC);
    func_003AECA0(s6, 1, 1);
    func_003AEC80(s7, 0x1A, 0x1C7);
    func_003AECA0(s7, 0, 1);
}
