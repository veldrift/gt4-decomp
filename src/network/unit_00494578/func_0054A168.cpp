/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pad { char pad[0x49C]; int busy; };
extern "C" Pad *D_0064C3E4;
extern "C" int D_0064C3E8;
extern "C" void func_00549CA8(int,int,int,int,int,int,int,int) throw();
extern "C" void func_0054A168(void) {
    Pad *p=D_0064C3E4;
    if (p != 0) {
        if (p->busy == 0) {
            int *count=&D_0064C3E8;
            int n=*count+1;
            *count=n;
            if(n>=5) {
                *count=0;
                func_00549CA8(1,0,0,0,0,0,0,0);
            }
        }
    }
}
