typedef int s32;
typedef short s16;
typedef float f32;

struct Rec_003E79F8 {
    s32 link : 13;
    char pad4[0x8];
    f32 a;
    f32 b;
    char pad14[0x40 - 0x14];
};

struct Pool_003E79F8 {
    Rec_003E79F8 *recs;
    s16 idx;
};

extern "C" s32 func_003E79F8(Pool_003E79F8 *p) {
    s32 i = p->idx;
    s32 result = 0;
    f32 best = 1e7f;
    if (i >= 0) {
        Rec_003E79F8 *base = p->recs;
        do {
            Rec_003E79F8 *r = base + i;
            f32 b = r->b;
            f32 a = r->a;
            s32 next = r->link;
            f32 prod = a * b;
            if (prod < best) {
                best = prod;
                result = i;
            }
            i = next;
        } while (i >= 0);
    }
    return result;
}
