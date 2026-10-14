struct VE { short d; short i; int (*f)(void *, void *, int); };
struct VT { char p[0x30]; VE e; };
struct Base { char p[0x5C]; VT *vt; };
struct Item { Base *base; char p0[0xC]; int f10; char p1[0x158]; int f16C; };
extern "C" {
int func_00475BB0(Item *, int);
void func_004760A0(Item *);
int func_00476500(Item *);
void func_0047D080(void *, int);
int func_0047D0E8(void *, int);
}
extern "C" int func_00476380(Item *self, int ev) {
    void *sub = (char *)self + 0x40;
    int r = func_0047D0E8(sub, 0x1B);
    func_0047D080(sub, ev);
    if (self->f10 != 0) {
        if (ev == 0xD && func_00476500(self)) return 1;
        if (func_00475BB0(self, ev)) return 1;
    }
    if (self->f16C != 0) {
        if (ev == 0x1B && r == 0) {
            func_004760A0(self);
            return 1;
        }
    }
    Base *b = self->base;
    if (b) {
        VE *e = &b->vt->e;
        return e->f((char *)b + e->d, self, 0x40);
    }
    return 0;
}
