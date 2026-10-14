/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned short u16;
typedef float f32;

struct Arg1 {
    char pad[0x18];
    u16 f18;
};
struct Self {
    char pad[0x2C];
    unsigned char f2C;
    char pad2D[0x40 - 0x2D];
    s32 f40;
};

struct Self;
extern "C" void func_004551D0(Self *, u16) throw();
extern "C" void func_0049CC38(s32);
extern "C" void func_0049CE40(s32);
extern "C" void func_0049CEA0();
extern "C" void func_0049F3C0(s32, f32);
extern "C" void func_004A1638(s32);
extern "C" void func_004A26F0(s32);
extern "C" void func_004A27C8(s32);
extern "C" void func_004A2808(s32, float);
extern "C" void func_004A2858(s32, float);
extern "C" void func_004A28B8(s32, s32);
extern "C" void func_004A2980(int);
extern "C" void func_004A29A8(int);
extern "C" void func_004A3020(float);
extern "C" void func_004A60E0(f32, f32, f32, f32);
extern "C" void func_004A6100(float, float, float, float);
extern "C" void func_004AB040(s32);

extern s32 D_00623894;
extern s32 D_00623898;
extern f32 D_0062389C;
extern f32 D_006238A0;
extern s32 D_006238B8;

extern "C" void ModelSet2__begin(Self *self, Arg1 *arg1) {
    if (arg1 != 0) {
        if (self->f2C != 0) {
            func_004551D0(self, arg1->f18);
        }
    }
    if (D_00623894 != 0) {
        func_004A1638(5);
    } else {
        func_004AB040(5);
    }
    func_004A1638(4);
    func_004AB040(3);
    func_004A1638(0xF);
    func_004A1638(0x11);
    func_004A2808(0x44, 0.0f);
    func_004A3020(0.0f);
    if (D_00623898 != 0) {
        func_004A29A8(1);
    }
    if (D_006238B8 != 0) {
        func_004A2980(-1);
    }
    func_004A26F0(3);
    func_004A28B8(6, 0x20);
    func_004A2858(5, 0.5f);
    func_004A27C8(0);
    func_0049F3C0(3, D_0062389C);
    func_0049F3C0(2, D_006238A0);
    func_004A60E0(1.0f, 1.0f, 1.0f, 1.0f);
    func_004A6100(0.0f, 0.0f, 0.0f, 0.0f);
    func_0049CE40(self->f40);
    func_0049CC38((s32)func_0049CEA0);
}
