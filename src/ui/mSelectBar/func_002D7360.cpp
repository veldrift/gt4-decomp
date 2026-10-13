struct S;
extern "C" int func_00206868(S *arg0);
extern "C" int func_0025C300(S *arg0);

struct S {
    char pad[0xBC];
    int count;
};

extern "C" int func_002D7360(S *arg0) {
    int i = 0;
    int p = func_00206868(arg0);
    if (p != 0) {
        int *cnt = &arg0->count;
        do {
            if (i == *cnt)
                return p;
            i++;
            p = func_0025C300((S *)p);
        } while (p != 0);
    }
    return 0;
}
