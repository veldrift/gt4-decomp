/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { unsigned char m0, m1, m2, m3; };
struct E { char p[0x440]; unsigned char m440; char q[0x466 - 0x441]; signed char m466; char r[0x64C - 0x467]; short m64C; };
struct Ctx { char p[1]; };
struct Tb { char pad[0xF910]; unsigned char a[1]; };
struct Self { char p[4]; Ctx *m4; char q[0x104 - 8]; E e; };
extern "C" void func_003F1BD8(Ctx *, int, int, int);

extern "C" void func_0035BF08(Self *self, unsigned char a1, unsigned char a2, unsigned char a3, unsigned char t0) {
    E *e = &self->e;
    Ent *sl = (Ent *)&((Tb *)self->m4)->a[e->m440 * 4];
    e->m64C = 0;
    unsigned char t1 = sl->m0;
    if (t1 != 0) {
        if (t1 == 1) {
            if (a1 == 0xFE) return;
        }
    }
    sl->m3 = a3;
    sl->m1 = a1;
    sl->m2 = a2;
    sl->m0 = 1;
    int m = e->m466;
    if ((m == 0 && t0 == 1) || (m == 1 && t0 == 0))
        return func_003F1BD8(self->m4, 10, e->m440, t0);
}
