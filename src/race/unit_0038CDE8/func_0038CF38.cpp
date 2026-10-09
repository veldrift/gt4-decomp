struct GeometryData {
    char pad0[0x38];
    float field38;
    float field3C;
    char pad40[0x84];
    float fieldC4;
    float fieldC8;
    float fieldCC;
};

extern "C" GeometryData *func_0038D0C0(void *);

extern "C" float func_0038CF38(void *arg0) {
    if (func_0038D0C0(arg0)->fieldC4 == 0x0p0f &&
        func_0038D0C0(arg0)->fieldC8 == 0x0p0f &&
        func_0038D0C0(arg0)->fieldCC == 0x0p0f) {
        return 0x0p0f;
    }
    GeometryData *data = func_0038D0C0(arg0);
    return data->fieldCC - func_0038D0C0(arg0)->field3C;
}
