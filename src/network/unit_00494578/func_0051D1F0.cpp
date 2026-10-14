struct Obj { unsigned int id; int x4; int state; char pad[0x78]; int handle; int (*fn)(int,int,int,int,int); };
extern "C" Obj *func_0051DD88(void);
extern "C" int func_0051D2E0(Obj *, int);
extern "C" int func_0051DCF8(unsigned int);
static inline bool eq(int a,int b) { return a==b; }
extern "C" int func_0051D1F0(int, int arg1) {
    Obj *p = func_0051DD88();
    if (!p) return 2;
    int result = func_0051D2E0(p,arg1);
    if (result) {
        if (arg1) {
            int v = p->state;
            if (v==2 || v==4 || v==3 || v==5 || v==6 || v==7 || v==9 || p->state==10) {
                if (p->fn) {
                    unsigned int id = p->id;
                    p->fn(p->handle,0,0,0,1);
                    if (!func_0051DCF8(id)) return 0xCB23;
                }
                p->state = 11;
            }
        }
    }
    return result;
}
