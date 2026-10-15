/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V2 { float x, y; };
struct Edge { char pad[0x10]; float x1, y1, x2, y2; int f20; int hit; float t; void *src; V2 dir; char tail[0xC]; };
struct Wall { char pad[0x20]; int hit; float t; char pad2[4]; };
struct Obj {
    char pad[8];
    Edge edges[8];
    Wall walls[8];
    char pad1[0x38c - 0x228 - 8 * 0x2c];
    float f38c;
    char pad2[0x3a0 - 0x390];
    float f3a0;
    char pad3[0x3f4 - 0x3a4];
    int f3f4, f3f8;
    float f3fc;
    char pad4[0x41c - 0x400];
    int f41c;
    V2 f420;
    void *f428;
    int f42c;
    char pad5[4];
    bool f434, f438, f43c;
    char pad6[0x484 - 0x440];
    int f484;
    void *f488;
};
extern char D_0045D550[];
extern "C" void func_00395A38(void *, void *, void *, int, float, float, float, float);
extern "C" int func_0045D8E0(Obj *p) {
    int i = 0;
    Edge *e = p->edges;
    Wall *w = p->walls;
    float xmax = e->x1;
    float ymax = e->y1;
    float xmin = xmax;
    float ymin = ymax;
    for (; i < 8; i++, e++, w++) {
        float x = e->x1;
        float y = e->y1;
        if (x < xmin) xmin = x;
        if (xmax < x) xmax = x;
        if (y < ymin) ymin = y;
        if (ymax < y) ymax = y;
        x = e->x2;
        if (x < xmin) xmin = x;
        if (xmax < x) xmax = x;
        x = e->y2;
        if (x < ymin) ymin = x;
        if (ymax < x) ymax = x;
        e->hit = 0;
        e->t = 2.0f;
        w->hit = 0;
        w->t = 2.0f;
    }
    func_00395A38(p->f488, D_0045D550, p, p->f484, xmin, -ymax, xmax, -ymin);
    float best = 2.0f;
    e = p->edges;
    w = p->walls;
    int index = -1;
    i = 0;
    for (; i < 8; i++, e++, w++) {
        if (e->hit != 0 && e->f20 == 0) {
            float t = e->t;
            if (t < best) { best = t; index = i; }
        }
        if (w->hit != 0) {
            float t = w->t;
            if (t < best) { best = t; index = i + 8; }
        }
    }
    if (index < 0) return 0;
    float start = p->f38c;
    p->f3fc = (p->f3a0 - start) * best + start;
    if (index < 8) {
        p->f41c = index;
        p->f3f4 = 1;
        p->f428 = p->edges[index].src;
        p->f420 = p->edges[index].dir;
        p->f43c |= 1;
        if (p->f41c < 4) p->f434 |= 1;
        else p->f438 |= 1;
    } else {
        int wall = index - 8;
        p->f3f8 = 1;
        p->f42c = wall;
        p->f43c |= 1;
        if (wall < 3) p->f434 |= 1;
        if ((unsigned)(p->f42c - 4) < 3) p->f438 |= 1;
    }
    return 1;
}
