/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_003CAEC8(char *) throw();
extern "C" void Pitmen__StatusEntity__clear(char *) throw();
extern "C" void Pitmen__StatusCategory__clear(char *) throw();
extern "C" void Pitmen__StatusTeam__clear(char *) throw();
extern "C" void Pitmen__Camera__clear(char *) throw();
extern "C" void Pitmen__clear_2(char *);
extern "C" void func_003D53E0(char *);
extern "C" void func_00409988(char *);
extern "C" void PitinPillar__clear(char *);
extern "C" int func_004629C8(char *);
extern "C" void func_003CC608(char *o)
{
    char *p;
    char *q;
    int i, j, k;
    Pitmen__Camera__clear(o + 4);
    p = o + 0x2C4;
    i = 5;
    do {
        PitinPillar__clear(p);
        p += 0x30;
    } while (--i != -1);
    q = o + 0x3E4;
    j = 5;
    do {
        p = q;
        k = 5;
        do {
            func_00409988(p + 0x1C);
            Pitmen__StatusEntity__clear(p);
            p += 0x178;
        } while (--k != -1);
        q += 0x8D0;
    } while (--j != -1);
    p = o + 0x38C4;
    i = 5;
    do {
        func_003CAEC8(p + 4);
        Pitmen__StatusCategory__clear(p);
        p += 0xAA4;
    } while (--i != -1);
    p = o + 0x789C;
    i = 5;
    do {
        Pitmen__StatusTeam__clear(p);
        p += 0xA0;
    } while (--i != -1);
    func_003D53E0(o + 0x7C5C);
    func_004629C8(o + 0x98E8);
    *(int *)(o + 0x9908) = 1;
    *(int *)(o + 0x96CC) = -0x10;
    return Pitmen__clear_2(o);
}
