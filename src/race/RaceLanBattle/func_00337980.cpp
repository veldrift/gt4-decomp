/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Item { char bytes[0x214]; };
struct VE { short delta, index; void (*fn)(void *, Item *); };
struct Input { char pad[0xD0]; char *vt; };
struct Self {
    char p0[0xCD8]; int fCD8;
    char p1[0xE444-0xCDC]; int idx;
    char p2[0xE454-0xE448]; int fE454;
    char p3[0xE710-0xE458]; Item items[5];
    char p4[0xF184-0xE710-5*0x214]; Input in;
    char p5[0xF374-0xF184-sizeof(Input)]; int fF374;
};
extern "C" void func_00337980(Self *self) {
    if (self->fF374 && self->fE454 && self->fCD8 == 0) {
        Input *in = &self->in;
        VE *e = (VE *)(in->vt + 0x30);
        e->fn((char *)in + e->delta, &self->items[self->idx]);
    }
}
