typedef int s32;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
};

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct Self {
    Str s;
    s32 pad4;
    Vec3 a;
    Vec3 b;
    Vec3 c;
};

extern "C" char *func_005C2560(Rep *r);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

extern "C" Self *func_0021BDB8(Self *self, Self *src) {
    Self *dst = self;
    if (src != dst) {
        {
            Rep *q = (Rep *)(*(s32 *)&dst->s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        {
            s32 p = *(s32 *)&src->s.p;
            Rep *r = (Rep *)(p - 0x10);
            s32 d = p;
            if (r->sel != 0) {
                d = (s32)func_005C2560(r);
            } else {
                r->ref++;
            }
            *(s32 *)&dst->s.p = d;
        }
    }
    Vec3 *pa = &dst->a;
    Vec3 *pb = &dst->b;
    Vec3 *pc = &dst->c;
    pa->x = src->a.x;
    pa->y = src->a.y;
    pa->z = src->a.z;
    pb->x = src->b.x;
    pb->y = src->b.y;
    pb->z = src->b.z;
    pc->x = src->c.x;
    pc->y = src->c.y;
    pc->z = src->c.z;
    return self;
}
