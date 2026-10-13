typedef int s32;

extern "C" void func_001DC5F8(void *, int);
extern "C" void func_001DC650(void *, void *);

struct Obj {
    char pad0[0x1C8];
    s32 unk1C8;
    s32 unk1CC;
};

struct A {
    Obj *p;
    s32 pad[3];
};

extern "C" void func_001E8B90(void *arg0, void *arg1)
{
    A a;
    func_001DC650(&a, arg1);
    a.p->unk1CC = -1;
    func_001DC5F8(&a, 2);
    func_001DC650(&a, arg1);
    a.p->unk1C8 = 0;
    func_001DC5F8(&a, 2);
}
