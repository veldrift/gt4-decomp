typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

struct Obj {
    char pad[0x40];
    s32 flag;
};

struct Desc {
    void (*entry)(void *);
    void *arg;
};

extern "C" void func_004EB7D0(void *);
extern "C" int func_00578B50(u32 mode, s32 c);
extern "C" u8 *func_00578610(u8 *p);
extern "C" Obj *func_00575098(Desc *d, s32 prio);
extern "C" void func_005788B8(Obj *o);

extern "C" void func_004EB830(void *arg0)
{
    Desc d;
    d.entry = func_004EB7D0;
    d.arg = arg0;
    Obj *o = func_00575098(&d, (s32)func_00578610((u8 *)func_00578B50(3, ((s32 *)arg0)[1])));
    o->flag = 1;
    func_005788B8(o);
}
