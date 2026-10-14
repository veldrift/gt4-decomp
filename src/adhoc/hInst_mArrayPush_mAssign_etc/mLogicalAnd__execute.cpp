typedef int s32;
typedef short s16;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj { char pad0[4]; VEntry *vtbl; };
struct Items { char pad0[0x14]; s32 *list; char pad1[8]; s32 count; };
struct Rhs { char pad0[0x30]; s32 *tab; };
struct Self { char pad0[0x24]; Rhs *rhs; s32 *out; Items *items; };

static inline s32 vcall(void *o) {
    VObj *ob = (VObj *)o;
    VEntry *e = (VEntry *)((char *)ob->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_002FC870(void *arg0, s32 arg1);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

extern "C" void mLogicalAnd__execute(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    s32 *slot;
    Items *s2;
    Self *self = (Self *)arg1;
    Items *it = self->items;
    s32 idx = it->count - 1;
    it->count = idx;
    s32 *ep = it->list + idx;
    VObj *o = (VObj *)*ep;
    if (vcall(o) == 0) {
        Rhs *rh = self->rhs;
        s32 k = arg0[2];
        s32 *v;
        if (rh != 0) {
            v = rh->tab + k;
        } else {
            v = 0;
        }
        self->out = v;
        func_002FE278(buf0, 0);
        s2 = self->items;
        slot = &s2->list[s2->count];
        if (slot != buf0) {
            newVal = buf0[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *slot;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *slot = newVal;
        }
        s2->count = s2->count + 1;
        func_002FC870(buf0, 2);
        return;
    }
    func_002FE278(buf0, 1);
    s2 = self->items;
    slot = &s2->list[s2->count];
    if (slot != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *slot;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *slot = newVal;
    }
    s2->count = s2->count + 1;
    func_002FC870(buf0, 2);
}
