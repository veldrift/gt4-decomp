/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char *D_0064C3E4;
extern "C" int func_0054A370(int) throw();
extern "C" int func_0054A8A8(int,int) throw() __attribute__((const));
extern "C" void func_00549858(char *,int,int) throw();
extern "C" int func_00561EF0(int,int);
extern "C" void func_00576788(char *);
extern "C" void func_005767C0(char *);
extern "C" int func_0054B088(int id) {
    int status=1;
    func_00576788(D_0064C3E4+0x34);
    if (func_0054A370(id)) {
        int q=id/4;
        int r=id%4;
        status=7;
        int result=func_00561EF0(q,r);
        if(result>=0) status=0;
        status=func_0054A8A8(status,result);
        int offset=(q*111+r*27)*4;
        func_00549858((char *)(offset+(int)D_0064C3E4)+0x78,result,status);
        *(int *)((char *)(offset+(int)D_0064C3E4)+0xcc)=1;
        *((char *)(offset+(int)D_0064C3E4)+0x78)=0;
    }
    func_005767C0(D_0064C3E4+0x34);
    return status;
}
