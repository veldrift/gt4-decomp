struct Data { char bytes[4]; };
extern "C" int func_00531C78(void *);
extern "C" int func_00535780(int);
extern "C" int func_00536CF8(void);
extern "C" int func_00536D38(void);
extern "C" int func_0052F688(Data *out) {
    Data data;
    int r = func_00535780(func_00536CF8());
    if (r == 0) {
        int value = func_00531C78(&data);
        *out = data;
        int status = func_00535780(func_00536D38());
        r = status == 0 ? value : status;
    }
    return r;
}
