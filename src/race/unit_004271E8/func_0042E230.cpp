typedef float f32;
extern "C" void func_0042E008(f32, f32, f32, f32);
extern "C" void func_0042E0A0(int, int, f32, f32, f32, f32);
extern "C" void func_004AA168(int);
extern f32 D_006A4F38[];
extern f32 D_006A4F50[];
struct Obj {
    char pad0[8];
    unsigned char n;
    unsigned char flag;
    char pad1;
    unsigned char sel;
    int p[4];
    f32 x1c, x20, x24, x28;
};
extern "C" void func_0042E230(Obj *o) {
    f32 d = o->x28 - o->x20;
    f32 *t;
    int i;
    if (o->sel == 0) t = D_006A4F38; else t = D_006A4F50;
    if (o->flag != 0) {
        i = 0;
        if (o->n - 1 > 0) {
            do {
                f32 a = t[i];
                i++;
                f32 b;
                if (i < o->n - 1) b = t[i]; else b = t[4];
                func_0042E0A0(o->p[i], o->p[i + 1], o->x1c, o->x20 + a * d, o->x24, o->x20 + b * d);
            } while (i < o->n - 1);
        }
    
    } else {
        i = 0;
        if (o->n != 0) {
            do {
                func_004AA168(o->p[i]);
                f32 a = t[i];
                i++;
                f32 b;
                if (i < o->n) b = t[i]; else b = t[4];
                func_0042E008(o->x1c, o->x20 + a * d, o->x24, o->x20 + b * d);
            } while (i < o->n);
        }
    }
}
