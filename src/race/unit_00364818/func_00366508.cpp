typedef unsigned char u8;

struct Obj {
    char pad[0xCBDE];
    u8 state;
};

extern "C" void func_003663A0(int x);
extern "C" int func_0034C190(Obj *o, int i);

extern "C" void func_00366508(Obj *o, int a, int n)
{
    if (o->state != 2) {
        for (int i = a; i < n; i++)
            func_003663A0(func_0034C190(o, i));
    }
}
