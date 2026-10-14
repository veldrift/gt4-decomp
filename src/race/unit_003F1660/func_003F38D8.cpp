/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Info { char p0; u8 n; char p[0x12]; u8 list[1]; };
struct Sub { char p[4]; float a4[1]; };
struct Wheel { char p0[0x20]; float f20; char p1[0x40]; float f64; char p2[0x3C]; float fa4; char p3[0xEC - 0xA8]; };
struct Obj { char p[0x10]; char *sub; char q[0x104 - 0x14]; char in[0x48C - 0x0]; };
struct Tbl { float g0, g4, g8, gc; };
extern Tbl D_00845A00;
extern "C" Info *func_00359510(void *);

extern "C" void func_003F38D8(char *o)
{
    char *in = o + 0x104;
    char *s = *(char **)(o + 0x10);
    float f20 = *(float *)(o + 0x54C);
    Info *info = func_00359510(s);
    int i = 0;
    Tbl *g = &D_00845A00;
    for (; i < info->n; i++) {
            Wheel *w = (Wheel *)(o + 0x164 + i * 0xEC);
            int sp4 = (int)s + 4;
            int idx = 0;
            if (i < info->n)
                idx = info->list[i];
            float k = *(float *)(s + 0x1010 + idx * 4) * *(float *)(idx * 4 + sp4 + 0x2C0);
            float x = w->f20;
            if (x < 0.0f)
                x = -x;
            float y = w->fa4;
            float f4 = k * w->f64 * x * g->g0;
            if (*(float *)(in + 0x48C) == 0.0f)
                f4 = 0.0f;
            f4 -= (x + g->g8) * g->g4 * (y + g->gc);
            y += f4 * f20;
            if (y > 1.0f)
                y = 1.0f;
            else if (y < 0.0f)
                y = 0.0f;
            w->fa4 = y;
    }
}
