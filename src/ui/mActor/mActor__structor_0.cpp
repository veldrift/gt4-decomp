/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
extern Rep D_00659FA8;
extern char mActor__vtable[];
extern "C" void *hObject__structor_0(void *);
extern "C" char *func_005C2560(Rep *);
struct S { int x0; char *vt; int x8, xc; char *name; };
static inline char *grab(Rep *r) {
 char *d = (char *)(r + 1);
 if (r->sel) d = func_005C2560(r);
 else { int n = r->ref + 1; r->ref = n; }
 return d;
}
extern "C" int mActor__structor_0(S *s) {
 hObject__structor_0(s);
 s->vt = mActor__vtable;
 char **p = &s->name;
 *p = grab(&D_00659FA8);
}
