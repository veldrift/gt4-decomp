/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef float f32;

struct Obj { char pad0[0x32]; u8 b32; };
struct Pr {
    char pad0;
    u8 n;
    char pad2[0xA];
    u8 a[2];
    char pad0E[0x16];
    u8 c[2];
};
struct Slot {
    char pad0[0xC];
    f32 fC;
    f32 f10;
    char pad14[0x78];
    f32 f8C;
    char pad90[0x5C];
};
struct Q { f32 f[13]; };
struct Win { f32 x, y; };
struct Car {
    char pad0[0x10];
    Obj *obj;
    char pad14[0xF0];
    Win win;
    char pad10C[0x58];
    Slot slots[1];
};
struct Vec3 { f32 x, y, z; };

extern "C" Pr *func_00359510(Obj *);
extern "C" void func_003667A8(Car *, int, Vec3 *, Vec3 *) throw();

extern "C" void func_003668F0(Car *self) {
    Win *win = &self->win;
    Obj *obj = self->obj;
    Pr *pr = func_00359510(obj);
    f32 *v = (f32 *)((char *)self + 0x648);
    Vec3 sp;
    Vec3 out;
    sp.x = v[0];
    sp.y = v[2];
    sp.z = -v[1];
    int i;
    if (obj->b32 == 6) {
        i = 0;
        u8 *ap = pr->a;
        for (; i < 2;) {
            u8 a = ap[i++];
            u8 t1 = pr->c[a];
            u8 t0 = a;
            char *q0 = (char *)self + t0 * 0x34;
            char *q1 = (char *)self + t1 * 0x34;
            if (*(float *)(q0 + 0x7CC) < *(float *)(q1 + 0x7CC)) {
                t0 = t1;
                t1 = a;
            }
            Slot *s0 = &self->slots[t0];
            Slot *s1 = &self->slots[t1];
            out.x = win->x + (s0->fC + s1->fC) * 0.5f;
            out.y = (s0->f8C + s1->f8C) * 0.5f;
            out.z = -(win->y + (s0->f10 + s1->f10) * 0.5f);
            func_003667A8(self, t0, &out, &sp);
        }
    } else {
        for (i = 0; i < pr->n; i++) {
            Slot *s = &self->slots[i];
            out.x = win->x + s->fC;
            out.y = s->f8C;
            out.z = -(win->y + s->f10);
            func_003667A8(self, i, &out, &sp);
        }
    }
}
