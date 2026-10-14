/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slot { char p[0x168 - 0]; int f168; char q[4]; int f170; int f174; };
struct Self { char p[0xFC]; int fc[16]; };
extern "C" int func_0034C190(int, int);
extern "C" int func_003CF7C8(int, int) throw();
extern "C" int func_003D2998(Self *) throw();
extern "C" int func_003D2A68(Self *, int) throw();
extern "C" int func_003D3030(Self *);

extern "C" int Pitmen__doRenderExchangeTire(Self *self, int idx, int owner, int slot, int flag)
{
    int s5 = func_003D2A68(self, func_0034C190(owner, idx));
    if (func_003D3030(self) != 0 || idx < 0)
        return 0;
    if (func_003D2998(self) == 0)
        return 0;
    char *car = (char *)self + idx * 0x8D0;
    Slot *e = (Slot *)(car + slot * 0x178 + 0x3E4);
    if (e->f168 != 0)
        return 0;
    int fc = self->fc[slot];
    int busy = 0;
    if (e->f170 != 0 || e->f174 != 0)
        busy = 1;
    if (busy != 0 || fc >= 2) {
        int v = flag != 0;
        if (s5 != 0)
            v = 0;
        return v;
    }
    return func_003CF7C8(func_0034C190(owner, idx), flag);
}
