extern char IpicArchive__vtable[]; struct T { int a,b; };
struct S { int p,value,data,v; S(T *p) __asm__("func_002771C8"); };
S::S(T *arg) { p=(int)arg; v=(int)IpicArchive__vtable; int n=arg->b; data=(int)(arg+1); value=n; }
