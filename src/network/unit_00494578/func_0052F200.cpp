struct Ops { char pad[0x14]; int (*call)(int,int,int,int,int,int,int,int,int); };
extern Ops *D_0064B4B4;
extern "C" int func_00535780(int);
extern "C" int func_00536CF8();
extern "C" int func_00536D38();
extern "C" int func_0052F200(int a,int b,int c,int d,int e,int f,int g,int h,int i) {
    int result = func_00535780(func_00536CF8());
    if (result == 0) {
        int call_result = D_0064B4B4->call(a,b,c,d,e,f,g,h,i);
        int after = func_00535780(func_00536D38());
        result = after == 0 ? call_result : after;
    }
    return result;
}
