typedef unsigned short u16;
typedef float f32;

struct Sub {
    char pad0[0x44];
    f32 f44;
    char p48[0x4BA - 0x48];
    u16 h4BA;
    char p4BC[0x4E8 - 0x4BC];
    f32 f4E8;
    f32 f4EC;
    char p4F0[0x4FC - 0x4F0];
    f32 f4FC;
    char p500[0x5A4 - 0x500];
    f32 f5A4;
    char p5A8[0x5B0 - 0x5A8];
    f32 f5B0;
    char p5B4[0x5BC - 0x5B4];
    f32 f5BC;
};

struct S {
    char pad[0x10];
    char *s4;
    char p14[0x104 - 0x14];
    Sub sub;
};

extern "C" void func_0035C0B8(void);
extern "C" void func_0035ACB0(void *arg0);
extern "C" void func_003658A0(void *arg0);
extern "C" void func_00354AC0(void *arg0);
extern "C" void func_003F3090(void *arg0);
extern "C" f32 func_0034E9A0(void *a, void *b, f32 c);
extern "C" f32 func_0034EA08(void *a, void *b, f32 c);
extern "C" void func_00357418(void *arg0);
extern "C" void func_00357690(void *arg0);

extern "C" void func_00357700(S *arg0) {
    Sub *temp_s1;
    char *temp_s3;
    char *temp_s4;
    char *temp_s0;

    temp_s1 = &arg0->sub;
    temp_s3 = (char *)arg0 + 0x6DC;
    temp_s4 = arg0->s4;
    if (temp_s1->h4BA != 0) {
        func_0035C0B8();
    }
    temp_s0 = temp_s4 + 0x134;
    func_0035ACB0(arg0);
    func_003658A0(arg0);
    func_00354AC0(arg0);
    func_003F3090(arg0);
    temp_s1->f4E8 = func_0034E9A0(temp_s0, temp_s3, temp_s1->f4FC);
    temp_s1->f4EC = func_0034EA08(temp_s0, temp_s3, temp_s1->f4FC);
    f32 acc;
    acc = temp_s1->f5B0;
    acc = acc + temp_s1->f5A4;
    f32 neg;
    neg = -(temp_s1->f44 * ((f32 *)temp_s4)[0x48 / 4] * 9.8f);
    temp_s1->f5BC = -(acc + neg);
    func_00357418(arg0);
    return func_00357690(arg0);
}
