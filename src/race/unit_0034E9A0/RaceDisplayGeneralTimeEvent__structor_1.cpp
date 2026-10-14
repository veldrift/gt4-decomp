/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Tab { char pad[8]; char **list; };
struct P { char pad0[0x60]; Tab *tab; char pad1[0x78]; int dc; };
struct S { P *p; };
struct E1 { int value; char *vt; int b; E1() __asm__("func_003A32F0"); };
struct E2 { int value; char *vt; int a, b; E2() __asm__("func_003A34E8"); };
extern "C" void func_003A3660(void *, int);
extern char RaceDisplayGeneralTimeEvent__vtable[];
struct D : E2 { D(int v, int t) { value = v; vt = RaceDisplayGeneralTimeEvent__vtable; func_003A3660(this, t); } };
extern "C" int func_0034C190(void *, int);
extern "C" void func_0035E3C8(int, int);
extern "C" int func_0035E3F8(P *, S *, int);
extern "C" void RaceDisplayEventBase__put(void *, void *);
extern "C" void func_003A3660(void *, int);
extern "C" void func_003BBA80(char *, int);
extern "C" int func_003DD788(char *, int);
extern "C" void func_003C0CC8(P *, int, int, int);
struct R { char pad[0x441]; unsigned char a; char pad2[0x1F0]; unsigned char b; };
extern "C" void RaceDisplayGeneralTimeEvent__structor_1(S *self, int v, int w, int x, int t, int f)
{
    int o = func_0034C190(self, v);
    func_0035E3C8(o, t);
    R *r = (R *)(o + 0x104);
    if (!r->a && !r->b) {
        P *p = self->p;
        int ok = func_0035E3F8(p, self, o) == 0;
        if (!p->dc) {
            E1 e;
            e.value = v;
            e.b = w;
            RaceDisplayEventBase__put(&e, p);
            E2 d;
            E2 *pd = &d;
            pd->vt = RaceDisplayGeneralTimeEvent__vtable;
            pd->value = v;
            func_003A3660(pd, t);
            RaceDisplayEventBase__put(pd, p);
        }
        if (ok) {
            func_003BBA80(p->tab->list[v] + 0x1A0, t);
            if (!f) {
                func_003DD788(p->tab->list[v] + 0x11E0, t);
                func_003C0CC8(p, v, t, ok);
            }
        }
    }
}
