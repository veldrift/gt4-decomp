struct GeometryInfo {
    unsigned char pad[2];
    unsigned char kind;
    unsigned char variant;
};

extern "C" GeometryInfo *func_0038D0B8(void *);

extern "C" int NormalCarGeometry__GetNumCrew(void *arg0) {
    if (func_0038D0B8(arg0)->kind == 0) return 0;
    switch (func_0038D0B8(arg0)->variant) {
    case 0: return 1;
    case 1: return 2;
    default: return 0;
    }
}
