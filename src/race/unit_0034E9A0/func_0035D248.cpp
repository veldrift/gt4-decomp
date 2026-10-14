/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Data { char p[0x31C]; struct { float f; char q[0x58 - 4]; } e[8]; };
struct Obj { char p[1]; unsigned char m1; char q[0x14 - 2]; unsigned char m14[8]; };
struct S104 { char p[0x440]; unsigned char m440; };
struct Self { char p[0x10]; Data *m10; char q[0x104 - 0x14]; S104 s; char r[0x788 - 0x104 - sizeof(S104)]; unsigned char m788; };
extern "C" Obj *func_00359510(Data *) throw();
extern "C" int func_0035C7C8(Self *) throw();

extern "C" float func_0035D248(Self *self, int idx) {
    Data *d = self->m10;
    Obj *o = func_00359510(d);
    unsigned char k = 0;
    if (idx < o->m1) k = o->m14[idx];
    float f = d->e[k].f;
    int ok = func_0035C7C8(self);
    S104 *e = &self->s;
    if (!ok) return f;
    int a3 = self->m788;
    if (!a3) return f;
    unsigned char c = e->m440;
    int s = idx + c;
    int v = s % 4;
    if ((c & 7) >= 4) v = 3 - v;
    int t = v * 7;
    if (a3 < t) return f;
    a3 = 1 - (a3 - t);
    if (a3 < 0) a3 = 0;
    return f * (float)a3;
}
