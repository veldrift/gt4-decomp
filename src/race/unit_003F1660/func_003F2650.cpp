/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Elem { float f0; char p0[0xC]; float f10, f14; char p1[0x1C]; float f34; char p2[0x58 - 0x38]; };
struct Data { char p[0x308]; Elem e[1]; };
struct Tbl { u8 on; char pad[3]; float f4, f8; float fc[5]; };
struct Obj { char p[0x10]; char *data; };
extern Tbl D_00622268[];
extern "C" float func_003F24A0(Obj *, int) throw();

extern "C" float func_003F2650(Obj *o, int a, float x)
{
    char *d = o->data;
    Tbl *t = &D_00622268[(u8)d[0x1076]];
    if (t->on == 0)
        return 0.0f;
    {
        int h = a >> 1;
        Elem *e = (Elem *)(d + 0x308 + h * 0x58);
        float f21 = 0.0f;
        float diff = x - e->f0;
        float f22 = 0.0f;
        if (diff < 0.0f)
            f22 = -(diff * diff * e->f34);
        x -= e->f10;
        float k = func_003F24A0(o, a);
        x += k;
        if (x < 0.0f) {
            float f3 = -t->f4;
            float f2 = t->f8 / t->fc[h];
            if (f3 < x)
                f2 = (f2 * x) / f3;
            f21 = f2 * *(float *)(d + 0x1040 + h * 4) * 0.5f;
        }
        f21 -= e->f14 * k;
        return f21 + f22;
    }
}
