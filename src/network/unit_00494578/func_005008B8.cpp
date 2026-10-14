/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x15]; signed char flag; char gap[2]; int value; };
struct Conn { char pad[0xA3C]; int value, active; };
struct Pair { Conn *p; Obj *o; };
extern char D_00645570[];
extern char D_006C0E60[];
extern "C" int func_004F0C38(Conn *,const char *);
extern "C" int func_004F0B08(Conn *,Obj *);
extern "C" void func_005008B8(Obj *o, Conn *c) {
    Pair g;
    if (!c) c=(Conn *)D_00645570;
    g.p=c; g.o=o;
    if (func_004F0C38(c,D_006C0E60)) {
        func_004F0B08(g.p,g.o);
        return;
    }
    if (!o->flag) {
        c->value=o->value;
        c->active=1;
    }
    func_004F0B08(g.p,g.o);
}
