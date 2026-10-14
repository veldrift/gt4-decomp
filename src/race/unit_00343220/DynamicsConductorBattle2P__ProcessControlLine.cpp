/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { char p[0x104]; char q[0x4B2]; unsigned char b5B6; unsigned char b5B7; char p2[0x718 - 0x5B8]; int m718; };
struct Ent2 { char p[0x5B6]; unsigned char b5B6; unsigned char b5B7; };
struct Sub { char p[0x614]; int m614; };
struct Self {
    char *m0;
    char pad[0x10140 - 4];
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
};
extern "C" Ent2 *func_0034C190(Self *, int);
extern "C" void func_00343D78(void *, int) throw();
extern "C" void func_0034C0A0(Self *, int);
extern "C" int func_0034C158(Self *, unsigned);
extern "C" void func_0035DF80(char *, int, int, int);
extern "C" void RaceDisplayGeneralTimeEvent__structor_1(Self *, int, int, int, unsigned, int);
extern "C" void func_00363528(void *);
extern "C" int DynamicsConductor__GetStandings(Self *, int);

extern "C" void DynamicsConductorBattle2P__ProcessControlLine(Self *self, int a1, int a2, int a3, unsigned a4, unsigned a5) {
    int one = 1;
    int r;
    Ent2 *e = func_0034C190(self, a1);
    Sub *s = (Sub *)((char *)e + 0x104);
    RaceDisplayGeneralTimeEvent__structor_1(self, a1, a2, a4, a5, e->b5B7);
    int v = self->v36();
    r = func_0034C190(self, DynamicsConductor__GetStandings(self, 0))->b5B6 != 0;
    if (v != 0) {
        r = (a2 == v) ? one : r;
    }
    if (r) {
        func_0035DF80(self->m0, 5, a1, 2);
        func_00343D78(func_0034C190(self, a1), 3);
    }
    func_00363528(e);
    s->m614 = a4;
}
