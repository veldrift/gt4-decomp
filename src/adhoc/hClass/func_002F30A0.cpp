/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00312370(void *,void *);
extern "C" void func_00312318(void *,int);
extern "C" void func_002F2A60(void *,void *) throw();
extern "C" void func_002F2A08(void *,int) throw();
extern "C" void func_002F2E80(void *,void *,int) throw();
extern "C" int func_002F3A48(int);
extern "C" int func_0030BB00();
extern "C" void *func_00314920(void *);
extern "C" int HSymID__GetID(void *);
extern "C" void func_002F30A0(void *arg0,void *arg1,int n,char *arg3) {
    void *copy[4];
    int tmp[4];
    int sym[4];
    int *pt;
    int value;
    int *ps;
    func_00312370(copy,arg3);
    if(n==2) {
        pt=tmp;
        func_002F2A60(pt,arg3+4);
        value=func_002F3A48(pt[0]);
        func_002F2A08(pt,2);
    } else {
        value=func_0030BB00();
        pt=tmp;
    }
    func_002F2A60(pt,arg1);
    ps=sym;
    *ps=HSymID__GetID(func_00314920(copy[0]));
    func_002F2E80(pt,ps,value);
    func_002F2A08(pt,2);
    func_00312318(copy,2);
}
