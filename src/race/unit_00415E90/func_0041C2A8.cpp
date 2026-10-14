/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct S {
    f32 m[5][4];
    f32 f50, f54, f58, f5C, f60, f64, f68, f6C, f70, f74, f78, f7C, f80;
    char pad84[0xA0 - 0x84];
    s32 n0[2]; s32 pA8, pAC;
    s32 n1[2]; s32 pB8, pBC, pC0, pC4, pC8, pCC, pD0, pD4;
};
extern "C" {
S *func_0041C2A8(S *a, S *b) {
    int i;
    f32 *sa = &b->m[0][0];
    f32 *sb = &b->m[0][2];
    f32 *da = &a->m[0][0];
    f32 *db = &a->m[0][2];
    for (i = 0; i < 2; i++) {
        f32 v_sa = sa[0 + i];
        da[0 + i] = v_sa;
        f32 v_sb = sb[0 + i];
        db[0 + i] = v_sb;
        da[4 + i] = sa[4 + i];
        db[4 + i] = sb[4 + i];
        da[8 + i] = sa[8 + i];
        db[8 + i] = sb[8 + i];
        da[12 + i] = sa[12 + i];
        db[12 + i] = sb[12 + i];
        da[16 + i] = sa[16 + i];
        db[16 + i] = sb[16 + i];
        a->n0[i] = b->n0[i];
        a->n1[i] = b->n1[i];
    }
    a->f50 = b->f50; a->f54 = b->f54; a->f58 = b->f58; a->f5C = b->f5C;
    a->f60 = b->f60; a->f64 = b->f64; a->f68 = b->f68; a->f6C = b->f6C;
    a->f70 = b->f70; a->f74 = b->f74; a->f78 = b->f78; a->f7C = b->f7C;
    a->f80 = b->f80;
    a->pA8 = b->pA8; a->pAC = b->pAC;
    a->pB8 = b->pB8; a->pBC = b->pBC; a->pC0 = b->pC0; a->pC4 = b->pC4;
    a->pC8 = b->pC8; a->pCC = b->pCC; a->pD0 = b->pD0; a->pD4 = b->pD4;
    return a;
}
}
