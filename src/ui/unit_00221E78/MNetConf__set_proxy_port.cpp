/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VObj { char pad[4]; char *vt; };
struct ESet { short delta, index; void (*fn)(void *, int); };
struct EGet { short delta, index; int (*fn)(void *); };
struct A { VObj *p; int pad[3]; };
static inline int get(VObj *o) {
    EGet *e = (EGet *)(o->vt + 0x58);
    return e->fn((char *)o + e->delta);
}
extern "C" void func_00221B28(void *, void *) throw();
extern "C" void func_00221AD0(void *, int) throw();
extern "C" void MNetConf__set_proxy_port(void *arg0, void *arg1, int count, VObj **args) {
    A a;
    func_00221B28(&a, arg1);
    VObj *o = a.p;
    ESet *e = (ESet *)(o->vt + 0x1C8);
    char *self = (char *)o + e->delta;
    e->fn(self, get(args[0]));
    func_00221AD0(&a, 2);
}
