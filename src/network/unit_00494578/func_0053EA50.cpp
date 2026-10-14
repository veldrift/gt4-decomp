/* compiler: ee-gcc2.96-as2004 */
typedef long ID;
struct A { int head; ID id __attribute__((packed)); char padC[8]; int x14; int x18; char pad1c[0x20]; int state; int x40; char *work; };
struct Api { char pad[0x78]; void (*format)(char*,ID,Api*); };
extern Api *D_0064B4B0;
extern char D_006C4350[];
extern char D_006C4480[];
extern "C" int func_0053EF68();
extern "C" void func_0057DA20(char*,const char*,int,int,char*);
extern "C" int func_0053C2F0(A*,const char*,const char*) throw();
extern "C" int func_0053A878(void*) throw();
extern "C" int func_0053EA50(A* a,int n,int unused,int handle) {
    char buf[16];
    int r=2;
    if(!a) return r;
    r=0xd6da;
    if(a->state) return r;
    r=2;
    if(!handle) return r;
    if(func_0053EF68()) return 100;
    *(int*)(a->work+8)=n;
    Api *api=D_0064B4B0;
    api->format(buf,a->id,api);
    func_0057DA20(a->work+0x2a7c,D_006C4350,a->x18,a->x14,buf);
    n=func_0053C2F0(a,D_006C4480,a->work+0x2a7c);
    if(n==0) {
        a->state=7;
        func_0053A878(a->work+0x10);
        *(int*)(a->work+0x2068)=handle;
    }
    return n;
}
