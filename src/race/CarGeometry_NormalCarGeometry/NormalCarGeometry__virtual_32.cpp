struct GeometryInfo {
    unsigned char pad[2];
    unsigned char kind;
    unsigned char variant;
};

extern "C" GeometryInfo *func_0038D0B8(void *);

extern "C" int NormalCarGeometry__virtual_32(void *arg0) {
    unsigned char kind = func_0038D0B8(arg0)->kind;
    if (kind == 0 || kind == 15 || kind == 16 || kind == 17 || kind == 32) return 0;
    return 1;
}
