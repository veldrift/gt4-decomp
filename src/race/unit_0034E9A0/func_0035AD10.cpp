/* compiler: ee-gcc2.96-nogcse */
struct Self {
    void *m0;
    char p[0xD9E4 - 4];
    unsigned short cnt[6];
    unsigned short hw[6][4];
    unsigned char pr[6][8];
};
extern "C" void func_0035E000(void *, int, int);
extern "C" void *func_0034C190(Self *, int);
extern "C" int Automobile__GetExplicitCurrentLap(void *);

extern "C" void func_0035AD10(Self *self, int idx) {
    func_0035E000(self->m0, idx, 1);
    self->cnt[idx]++;
    unsigned char *q = (unsigned char *)(idx * 8 + (int)self + 0xDA27);
    for (int n = 3; n > 0; n--) {
        *(unsigned short *)(q - 0x31) = *(unsigned short *)(q - 0x33);
        q[-1] = q[-3];
        q[0] = q[-2];
        q -= 2;
    }
    self->hw[idx][0] = Automobile__GetExplicitCurrentLap(func_0034C190(self, idx));
    self->pr[idx][0] = -1;
    self->pr[idx][1] = -1;
}
