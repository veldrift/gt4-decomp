/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec2 { float x, z; };
struct V3 { float x, y, z; };
struct Obj { char pad[4]; void **p; char pad8[8]; };
struct Entry {
    unsigned int flags;
    unsigned short idx;
    char pad[0x3A];
};
struct List {
    char pad[0x18];
    int n;
    Entry *ents;
    char pad20[4];
    Obj *objs;
};
struct Mid { char pad[0xCC]; List *list; };
struct Ctx { char pad[4]; Mid *mid; };
struct Pos { float x, w, z; };
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" void func_003C6B90(void *, Vec2 *);
extern "C" bool func_003C9E70(Obj *, Vec2 *) throw();
extern "C" float func_005F5010(float *);
extern "C" void func_005F5040(float *, float *);
extern "C" void func_005F5268(void *, void *);

extern "C" int func_003FECB0(Pos *pos, Ctx *ctx, float r) {
    List *l = ctx->mid->list;
    pos->w = 0;
    if (!l) return -1;
    Vec2 p;
    p.x = pos->x;
    p.z = pos->z;
    int i;
    {
        for (i = 0; i < l->n; i++) {
            Entry *e = &l->ents[i];
            Obj *o = &l->objs[e->idx];
            if (e->flags & 1) {
                float a_[3];
                float *a = a_;
                float b[3];
                Vec2 c;
                func_005A48D8(a, 0, 12);
                func_003C6B90(*o->p, &c);
                a[0] = c.x;
                a_[2] = c.z;
                func_005F5040(a, b);
                func_005F5268(b, pos);
                if (func_005F5010(b) < r * r) {
                    func_005F5040(a, &pos->x);
                    return i;
                }
            } else if (func_003C9E70(o, &p)) {
                return i;
            } else {
                continue;
            }
        }
    }
    return -1;
}
