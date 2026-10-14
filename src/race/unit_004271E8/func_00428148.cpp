struct Res { int p0; void *vt; int cnt; float v; };
struct Rec { int p0; char *p4; char *p8; int pc; };
struct Tbl { int p0; int p4; int p8; int pc; Rec *recs; };
struct Obj { int p0; Tbl *t; };
extern char D_006877A0[];
extern "C" {
float func_0042A4A8(void *, int, int, int, float);
float func_0042D430(void *, int, int, int, float);
void func_0042D7C8(Res *, int);
void func_0042C300(Rec *, int, Res *, float);
void func_0042C348(Rec *, int, Res *, float, float);
int func_00428148(Obj *o, float *out, int ri, int a, float f0, float f1, int b, float *tp) {
    Res r;
    int idx;
    int first;
    float t;
    Rec *rec;
    if (o->t == 0) return 0;
    if (a >= 0) {
        idx = a;
        first = 1;
    } else if (b >= 0) {
        idx = b;
        first = 0;
    } else {
        return 0;
    }
    rec = (Rec *)((char *)o->t->recs + ri * 16);
    if (first)
        t = func_0042D430(rec->p4 + idx * 32, a, ri, b, f0);
    else
        t = func_0042A4A8(rec->p8 + idx * 32, a, ri, b, f0);
    if (tp) *tp = t;
    r.p0 = 0;
    r.vt = D_006877A0;
    r.cnt = 0;
    if (first)
        func_0042C300(rec, idx, &r, t);
    else
        func_0042C348(rec, idx, &r, t, f1);
    if (r.cnt) {
        *out = r.v;
        func_0042D7C8(&r, 2);
        return 1;
    }
    func_0042D7C8(&r, 2);
    return 0;
}
}
