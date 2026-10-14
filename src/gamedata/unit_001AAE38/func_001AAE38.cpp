extern "C" void mUpdateContext__Sync(int);

extern "C" int func_001AAE38(char *arg0, int arg1) {
    int i = 0;

    if (arg1 > 0) {
        int *p = (int *)(arg0 + 0xAC);
        do {
            if ((*p ^ 2) != 0) {
                return 0;
            }
            mUpdateContext__Sync(1);
            i++;
        } while (i < arg1);
    }
    return 1;
}
