/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { void *vtbl; void *self; };
extern char MboolReader__vtable[];
extern "C" int func_0024DB78(S *, int);
extern "C" void MReaderBase__structor_0(S *, int);
extern "C" int MboolReader__structor_8(int arg) {
 int buf[4];
 S s;
 S *ps=&s;
 void *vt=MboolReader__vtable;
 ps->vtbl=vt;
 ps->self=buf;
 func_0024DB78(ps,arg);
 int r=buf[0];
 ps->vtbl=vt;
 MReaderBase__structor_0(ps,0);
 return r;
}
