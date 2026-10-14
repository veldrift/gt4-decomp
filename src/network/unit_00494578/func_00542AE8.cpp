extern "C" void func_00544830(int *,int);
extern "C" int func_00544880(int *);
extern "C" int func_005448B8(const int *);
extern "C" void func_005449C8(int *,unsigned);
extern "C" void func_00544AE0(int *,int *,int *);
extern "C" void func_00544CE8(int *,int *,int *,int *);
extern "C" void func_00545308(int *,int);
extern "C" int func_00545AC8(int *,int *);
extern "C" int func_00545B28(int *,int *);
extern "C" void func_00545EB8(int *,int *);
extern "C" void func_00545FC0(int *,int *);
extern "C" void func_005464B0(int *,int *,int *);
extern "C" void func_00546668(int *,int *,int *,int *);
extern "C" void func_005A2E98(const char *,int,const char *);
extern "C" void *func_005A4724(void *,const void *,unsigned);
extern char D_006C51B0[],D_006C51F8[];
extern "C" void func_00542AE8(void *arg0,void *arg1) {
    int a[32],b[32],c[32],d[32],e[32],f[32];
    func_00544830(c,0);
    func_00545308(a,0x100);
    do {
        func_005A4724(b,a,0x80);
        func_00545308(a,0x100);
        func_005464B0(f,a,b);
        func_005A4724(arg0,f,0x40);
        func_005449C8(f,1);
        func_00545FC0(f,a);
        func_00545FC0(f,b);
        func_00544830(b,1);
        func_00544830(d,17);
        func_00544CE8(f,d,c,e);
        func_00545EB8(c,b);
        func_00544AE0(e,d,e);
        for(;;) {
            if(func_00545AC8(d,e)) {
                if(func_00545B28(b,c)) func_00545EB8(b,f);
                func_00545FC0(b,c);
                func_00545FC0(d,e);
                if(func_005448B8(d)) { func_005A4724(c,b,0x80); break; }
            } else if(func_00545B28(d,e)) {
                if(func_00545B28(c,b)) func_00545EB8(c,f);
                func_00545FC0(c,b);
                func_00545FC0(e,d);
                if(func_005448B8(e)) { func_005A4724(c,c,0x80); break; }
            } else { func_00544830(c,0); break; }
        }
    } while(func_00544880(c));
    func_00544830(a,17);
    func_00546668(a,c,a,f);
    if(!func_005448B8(a)) func_005A2E98(D_006C51B0,0x210,D_006C51F8);
    func_005A4724(arg1,c,0x40);
}
