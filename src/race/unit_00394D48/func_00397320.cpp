typedef int s32;

extern "C" void RaceEntryCar__update(s32 mode);
extern "C" void func_004A53F8();
extern "C" void func_0049AB58(float shift);
extern "C" void ModelSet2__begin(void *obj, s32 arg1);
extern "C" void func_004A6100(float a, float b, float c, float d);
extern "C" void ModelSet2___render(void *obj, s32 arg1, s32 arg2);
extern "C" void ModelSet2__end(void *obj);
extern "C" void func_004A5400();

struct Vec4 {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
};

struct ObjInner {
    char pad[0x7C];
    s32 unk7C;
};

struct ObjA {
    char pad[0xAC];
    ObjInner *unkAC;
};

extern "C" void func_00397320(ObjA *arg0, Vec4 *arg1) {
    if (arg0->unkAC != 0) {
        RaceEntryCar__update(1);
        func_004A53F8();
        func_0049AB58(0.005f);
        s32 s0 = arg0->unkAC->unk7C;
        ModelSet2__begin(arg0->unkAC, s0);
        func_004A6100(arg1->unk0, arg1->unk4, arg1->unk8, arg1->unkC);
        ModelSet2___render(arg0->unkAC, 0, s0);
        ModelSet2__end(arg0->unkAC);
        func_004A5400();
        RaceEntryCar__update(0);
    }
}
