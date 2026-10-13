struct S;
extern "C" int func_00206868(S *arg0);
extern "C" int func_0025C300(S *arg0);

extern "C" int func_002DB0D8(S *arg0, int arg1) {
    int i = 0;
    int p = func_00206868(arg0);
    while (p != 0) {
        if (i == arg1)
            return p;
        i++;
        p = func_0025C300((S *)p);
    }
    return 0;
}
