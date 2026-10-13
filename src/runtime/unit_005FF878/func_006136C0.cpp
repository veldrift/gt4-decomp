struct Lock;
extern "C" void func_00576788(Lock *l);
extern "C" void func_005767C0(Lock *l);

struct Guard {
    Lock *l;
    Guard(Lock *lock) : l(lock) { func_00576788(l); }
    ~Guard() { func_005767C0(l); }
};

struct Obj {
    char pad[0x1C];
    char lock[4];
};

extern "C" void func_006136C0(Obj *o, int a);

extern "C" void func_006136C0(Obj *o, int a)
{
    Guard g((Lock *)o->lock);
    func_006136C0(o, a);
}
