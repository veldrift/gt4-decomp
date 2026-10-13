struct Obj {
    char pad0[0x75F];
    unsigned char flag;
};

extern "C" short Automobile__GetImplicitCurrentLap(Obj *arg0);
extern "C" unsigned DynamicsConductor__CurrentLapTime_Normal(char *a, char *b);

extern "C" int func_00357830(int arg0, Obj *arg1) {
    if (!Automobile__GetImplicitCurrentLap(arg1))
        return 0;
    if (arg1->flag == 1)
        return 0;
    return DynamicsConductor__CurrentLapTime_Normal((char *)arg0, (char *)arg1);
}
