struct Eye { char p[0x298]; char *vt; };
struct VE { short delta; short index; void (*fn)(void *, int); };
extern "C" char D_008286F0[];
extern "C" char D_00828720[];
extern "C" Eye D_00828778;
extern "C" void func_00574D78(void *);
extern "C" void func_00574DA8(void *, int);
extern "C" void func_001C55F0(char *);
extern "C" void func_001C5638(int, int);
extern "C" void EyeToyPS2__structor_0(void *, int);
extern "C" void func_001C59C8(int init, int prio) {
    if (prio == 0xFFFF && init == 1) func_00574D78(D_008286F0);
    if (prio == 0xFFFF && init == 1) func_001C55F0(D_00828720);
    if (prio == 0xFFFF && init == 1) EyeToyPS2__structor_0(&D_00828778, 0);
    if (prio == 0xFFFF && init == 0) {
        if (&D_00828778) {
            Eye *q = &D_00828778 + 1;
            while (q != &D_00828778) {
                --q;
                VE *e = (VE *)(q->vt + 8);
                e->fn((char *)q + e->delta, 2);
            }
        }
    }
    if (prio == 0xFFFF && init == 0) func_001C5638((int)D_00828720, 2);
    if (prio == 0xFFFF && init == 0) func_00574DA8(D_008286F0, 2);
}
