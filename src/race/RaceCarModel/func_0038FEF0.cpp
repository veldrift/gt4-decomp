struct Obj { char pad[0x100]; void *field100; };
struct Source { char pad[0x94]; void *field94; };
extern "C" void func_0038FFC8(void *, void *);
extern "C" void func_00575DA0(void *);
extern "C" void func_005C1628(void *);

extern "C" void func_0038FEF0(Obj *arg0, Source *arg1) {
    void *resource = arg1->field94;
    func_0038FFC8(arg0->field100, resource);
    func_00575DA0(resource);
    func_005C1628(arg0);
}
