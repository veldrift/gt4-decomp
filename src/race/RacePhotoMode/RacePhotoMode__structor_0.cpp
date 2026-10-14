struct Cam {
    char pad0[0x64]; void *vt64; char pad1[8]; void *p70;
    char pad2[0x1E548 - 0x74]; int i1E548;
    char pad3[0x1E634 - 0x1E54C]; int i1E634;
    char pad4[0x1E650 - 0x1E638]; int i1E650; int i1E654; int i1E658; int i1E65C;
    float f1E660; float f1E664; int i1E668; int i1E66C; float f1E670; float f1E674; float f1E678;
    char pad5[4]; void *vt1E680;
};
struct Sub { void *vt; char pad[0xF80 - 4]; void *owner; void *z; };
extern char RacePhotoMode__vtable[];
extern char RacePhotoModeCameraManager__vtable[];
inline char *offset(void *p, int n) { return (char *)(n + (unsigned)p); }
extern "C" void *RacePS2Base__structor_0(void *);
extern "C" void DynamicsConductorSinglePlayer__structor_1(void *);
extern "C" void PhotoModeInput__structor_0(void *);
extern "C" int func_00575E60(int, int);
extern "C" int func_00377C98(void *);
extern "C" int func_0033D958(int);
extern "C" int func_0055F420(int);
extern "C" void func_00342E98(void *, int);

extern "C" void RacePhotoMode__structor_0(Cam *o)
{
    Sub *s1 = (Sub *)offset(o, 0x1E680);
    void *s2 = offset(o, 0xE400);
    void *s3 = offset(o, 0x1E548);
    RacePS2Base__structor_0(o);
    o->vt64 = RacePhotoMode__vtable;
    DynamicsConductorSinglePlayer__structor_1(s2);
    PhotoModeInput__structor_0(s3);
    o->i1E634 = 0;
    o->i1E650 = 0;
    o->i1E654 = 0;
    int v = func_00575E60(0x40, 0x80);
    o->i1E65C = 0;
    o->f1E660 = 0.5f;
    o->i1E658 = v;
    o->f1E664 = 0.5f;
    o->f1E670 = 1.0f;
    o->f1E678 = 5500.0f;
    o->i1E668 = 0;
    o->i1E66C = 0;
    o->f1E674 = 0.0f;
    func_00377C98(s1);
    s1->vt = RacePhotoModeCameraManager__vtable;
    s1->owner = o;
    s1->z = 0;
    o->p70 = s2;
    *(int *)s3 = func_0055F420(func_0033D958(0));
    return func_00342E98(o, 0);
}
