/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int head; void *vt; char pad[0x18]; int a,b; float x,y; int c; };
extern char D_0069BC28[],mKeyPressEvent__vtable[];
extern "C" void *func_00326750(unsigned int,int,const char *);
extern "C" void mWindowEvent__structor_0(Obj *,int,int);
extern "C" void func_002A95E0(void *,Obj **);
extern "C" void func_002AA7B0(void *,int) throw();
extern "C" void func_003285A8(int);
extern "C" void func_003285F8(int);
extern "C" void MKeyPressEvent__global_00837560(int *dst) {
    float zero = 0.0f;
    int buf[4];
    Obj *tmp;
    Obj **pt = &tmp;
    Obj *p = (Obj *)func_00326750(0x34,4,D_0069BC28);
    mWindowEvent__structor_0(p,0,0);
    p->a = 0;
    p->b = 0;
    p->vt = mKeyPressEvent__vtable;
    p->x = zero;
    p->y = zero;
    p->c = 0;
    tmp = p;
    func_002A95E0(buf,pt);
    if (dst != buf) {
        int n = buf[0];
        if (n) func_003285A8(n);
        int old = *dst;
        if (old) func_003285F8(old);
        *dst = n;
    }
    func_002AA7B0(buf,2);
}
