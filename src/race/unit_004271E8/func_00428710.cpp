struct Table;
struct A { int p0; Table *t; };
extern "C" int func_00427778(Table *, const char *) throw();
extern "C" void func_00428670(A *, int, float, int, int, float) throw();
extern "C" void func_00428710(A *self, const char *name, float f0, int b, int c, float f1) {
    if (self->t) {
        func_00428670(self, func_00427778(self->t, name), f0, b, c, f1);
    }
}
