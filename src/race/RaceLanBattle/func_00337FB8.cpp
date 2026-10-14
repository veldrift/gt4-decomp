/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short delta, index; void (*fn)(void *, int, float, float); };
struct Self {
    char p0[0x64]; char *vt;
    char p1[0xCC8-0x68]; unsigned int mode;
    char p2[0xE480-0xCCC]; void *obj;
    char p3[0xF370-0xE484]; int flags;
    char p4[0xF380-0xF374]; int fF380;
};
extern "C" int RaceInput__getButtonDown(void *);
extern "C" int RaceInput__getButtons(void *);
extern "C" void func_00501BF0(void *, int);
extern "C" void func_00337FB8(Self *self) {
    if (RaceInput__getButtonDown((char *)self + 0xF184) & 0x40) {
        if (self->mode < 2) {
            if (self->fF380 == 0) self->flags |= 8;
        } else {
            VE *e = (VE *)(self->vt + 0x2B8);
            e->fn((char *)self + e->delta, 2, 0.0f, 0.0f);
        }
        if (RaceInput__getButtons((char *)self + 0xF184) == 0xC0)
            func_00501BF0(self->obj, 1);
    }
}
