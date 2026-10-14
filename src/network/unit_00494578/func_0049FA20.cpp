/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { char p0[0x40]; unsigned int color; char p44[0x1b4]; int *ptr; };
extern "C" void func_004A72C0(void *, unsigned int);
extern "C" void func_0049FA20(S *self, int addr, int count) {
 if (self->color != 0xc0c0c0c0) func_004A72C0(self, 0xc0c0c0c0);
 int *p = self->ptr;
 count = (count + 1) & ~1;
 p[0] = (count >> 1) | 0x30000000;
 p[1] = addr & 0x0fffffff;
 p[3] = (count << 16) | 0x7400c040;
 p[2] = 0;
 self->ptr = p + 4;
}
