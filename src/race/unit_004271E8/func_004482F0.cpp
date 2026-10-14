typedef int s32;
typedef long s64;
typedef unsigned long u64;

struct Ent { s32 val; s32 key; };
struct Obj { char pad[8]; s32 count; char pad2[4]; Ent ents[1]; };
extern Obj **D_006236DC[];

extern "C" s64 func_004482F0(s32 arg0, s32 arg1) {
    u64 hi = (u64)(unsigned)arg1 << 32;
    Obj **t = D_006236DC[arg1];
    s32 a2 = -1;
    if (arg0 >= 0) {
        Obj *o = *t;
        if (arg0 < o->count) {
            Ent *e = o->ents + arg0;
            a2 = e->val;
        }
    }
    s64 r = -1;
    if (a2 == -1) return r;
    r = (s64)(hi | (u64)(unsigned)a2);
    return r;
}
