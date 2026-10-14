/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char *D_0064C3E4;
extern "C" int func_0054A370() throw();
extern "C" int func_0054A8A8(int,int) throw() __attribute__((const));
extern "C" void func_00549858(char *,int,int) throw();
extern "C" int func_00562330(int,int,int,int);
extern "C" int func_005626F0(int,int,int);
extern "C" int func_00561E00(int);
extern "C" int func_0054A908(int id,int a,int b,int c) {
    int status=1;
    if (func_0054A370()) {
        status=5;
        int result=func_00562330(id/4,id%4,a,0x702);
        int handle=result;
        if (result>=0) {
            status=15;
            result=func_005626F0(handle,b,c);
            if (result>=0) {
                status=4;
                result=func_00561E00(handle);
                if (result==0) status=0;
            }
        }
        status=func_0054A8A8(status,result);
        int q2=id/4;
        int offset=(q2*111+(id-q2*4)*27)*4;
        func_00549858((char *)(offset+(int)D_0064C3E4)+0x78,result,status);
        *(int *)((char *)(offset+(int)D_0064C3E4)+0xcc)=1;
        *((char *)(offset+(int)D_0064C3E4)+0x78)=0;
    }
    return status;
}
