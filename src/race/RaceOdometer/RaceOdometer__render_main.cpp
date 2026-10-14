/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
struct Obj {
    char pad0[0x18];
    float unk18;
};
extern Obj D_00623838;
struct Self {
    char pad0[1];
    u8 unk1;
    char pad2[2];
    s16 unk4;
    s16 unk6;
    char pad8[4];
    float unkC;
    char pad10[8];
    s32 unk18;
    float unk1C;
    char unk20[1];
};
extern "C" float func_003AFD18(int a, float x, float w);
extern "C" s32 func_003AFEC8(s32 a, float f);
extern "C" void func_0044D920(void *o, const char *s);
extern "C" void func_0044D988(void *o);
extern "C" void func_0044DDF8(void *o, float x, float y, float z);
extern "C" void func_0044DE80(void *o, s32 v);
extern "C" float func_0044DFC8(void *o, void *b);
extern "C" void func_0044E030(void *self, void *item);
extern "C" void func_0057DA20(void *buf, const char *fmt, ...);

extern "C" void RaceOdometer__render_main(Self *arg0) {
    char buf[0x20];
    float f;
    func_0044D920(&D_00623838, "GT4oddmeter#1");
    func_0044DE80(&D_00623838, func_003AFEC8(0x80E3B896, arg0->unkC));
    func_0057DA20(buf, arg0->unk20, arg0->unk18);
    f = arg0->unk1C;
    if (f == 0.0f) {
        float t = func_0044DFC8(&D_00623838, buf) / D_00623838.unk18;
        arg0->unk1C = t;
        f = t;
    }
    func_0044DDF8(&D_00623838, func_003AFD18(arg0->unk1, (float)arg0->unk4, f), (float)arg0->unk6, 0.0f);
    func_0044E030(&D_00623838, buf);
    func_0044D988(&D_00623838);
}
