struct Obj { char pad[4]; char *p4; char pad2[8]; char *p10; char *p14; };
extern "C" void func_00491D48(Obj *, int);
static inline void adj(char **p, int d) { if (*p) *p += d; }
extern "C" void func_00491C50(Obj *self, int d, int arg2) {
    adj(&self->p4, d);
    adj(&self->p10, d);
    adj(&self->p14, d);
    func_00491D48(self, arg2);
}
