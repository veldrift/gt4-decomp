/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned int u32;

struct T12 { s32 a, b, c; };
struct Vec { T12 *start; T12 *finish; T12 *eos; };
struct VEntry { s16 delta; s16 index; void (*fn)(void *, s32); };
struct Owner { char pad[0x5C]; char *vtbl; };
struct Obj {
    Owner *owner;
    Obj *prev;
    Obj *next;
    char pad0C[0x168 - 0x0C];
    char *str168;
    char pad16C[0x174 - 0x16C];
    char sub174[8];
    char *str17C;
    Vec vec;
    char pad18C[0x18C - 0x18C];
    char sub18C[4];
};
struct Self { char pad[0x14]; Obj *obj; };

extern char *D_00659E2C[];
extern "C" void PauseBase__cleanup(void);
extern "C" void func_004768C0(void *);
extern "C" void free(void *) throw();
extern "C" void func_005C1628(void *) throw();

static inline void unref(char *p) {
    s32 *r = (s32 *)(p - 0x10);
    s32 v = r[2] - 1;
    r[2] = v;
    if (v == 0) free(r);
}

static inline void destroy_range(T12 **pf, T12 *last) {
    for (T12 *p = *pf; p != last; ++p) {
    }
}

extern "C" void RacePause__cleanup(Self *self) {
    PauseBase__cleanup();
    Obj *o = self->obj;
    if (o != 0) {
        func_004768C0(o->sub18C);
        Vec *v = &o->vec;
        T12 *first = v->start;
        destroy_range(&first, v->finish);
        T12 *st = v->start;
        s32 n = v->eos - st;
        if (n != 0) {
            u32 bytes = n * 12;
            if (bytes > 0x80) {
                free(st);
            } else {
                char **slot = &D_00659E2C[(bytes + 7) >> 3];
                *(char **)st = *slot;
                *slot = (char *)st;
            }
        }
        unref(o->str17C);
        func_004768C0(o->sub174);
        unref(o->str168);
        if (o->prev == o->next) {
            Owner *ow = o->owner;
            if (ow != 0) {
                VEntry *e = (VEntry *)(ow->vtbl + 8);
                e->fn((char *)ow + e->delta, 3);
            }
        } else {
            o->next->prev = o->prev;
            o->prev->next = o->next;
        }
        func_005C1628(o);
    }
    self->obj = 0;
}
