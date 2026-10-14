struct Res { int p0; int p4; int cnt; int pc; float v[9]; char pad[0xC]; };
struct Rec { int p0; char *p4; char *p8; int pc; };
struct Tbl { int p0; int p4; int p8; int pc; Rec *recs; };
struct Obj { int p0; Tbl *t; };
extern "C" {
float func_0042A4A8(void *, float);
float func_0042D430(void *, float);
void func_0042ACA8(Res *, int);
void func_0042ACC8(Res *, int);
void func_0042C300(Rec *, int, Res *, float);
void func_0042C348(Rec *, int, Res *, float, float);
int func_00427B70(Obj *o, float *out, int ri, float f0, float f1, int a, int b, float *tp) {
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
        t = func_0042D430(rec->p4 + idx * 32, f0);
    else
        t = func_0042A4A8(rec->p8 + idx * 32, f0);
    if (tp) *tp = t;
    func_0042ACA8(&r, 1);
    if (first)
        func_0042C300(rec, idx, &r, t);
    else
        func_0042C348(rec, idx, &r, t, f1);
    if (r.cnt) {
        int i;
        for (i = 0; i < 9; i++) out[i] = r.v[i];
        func_0042ACC8(&r, 2);
        return 1;
    }
    func_0042ACC8(&r, 2);
    return 0;
}
}
