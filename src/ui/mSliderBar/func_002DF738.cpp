/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slider { char pad0[0xC4]; int c4; int c8; int cc; char padD0[0x28]; int f8; char padFC[0x10]; int popup; };
extern char D_0069CF88[];
extern "C" void func_0023FB80(void *);
extern "C" void func_0023F8C8(int, void *);
extern "C" void func_0023DDF0(void *, int);
extern "C" void func_002306D0(void *, int);
extern "C" void func_00231F60(void *, int);
extern "C" void func_002DF738(Slider *self, void *arg) {
 int h[4];
 func_0023FB80(h);
 func_0023F8C8(h[0], D_0069CF88);
 func_0023DDF0(h, 2);
 self->popup = 1;
 func_002306D0(arg, 0);
 func_00231F60(arg, self->c4);
 self->f8 = self->cc;
}
