struct Ops { char pad[0x80]; int (*call)(int,int,int,int,int,int,int,int,int,int,int); };
extern Ops *D_0064B4B4;
extern "C" int func_00535780(int);
extern "C" int func_00536CF8(void);
extern "C" int func_00536D38(void);
extern "C" int func_005158B0(int a,int b,int c,int d,int e,int f,int g,int h,int i,int j,int k) {
    int result = func_00535780(func_00536CF8());
    if (result == 0) {
        int value = D_0064B4B4->call(a,b,c,d,e,f,g,h,i,j,k);
        int status = func_00535780(func_00536D38());
        result = status == 0 ? value : status;
    }
    return result;
}
