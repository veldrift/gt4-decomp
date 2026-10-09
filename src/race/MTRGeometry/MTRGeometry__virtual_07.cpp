struct Obj { char pad[4]; int field4; };

extern "C" float MTRGeometry__virtual_07(Obj *arg0, int arg1) {
    if (arg0->field4 == 0) {
        if (arg1 == 0) return -0x1.22d0e40000000p-4f;
        return 0x1.22d0e40000000p-4f;
    }
    if (arg1 == 0) return -0x1.3958100000000p-3f;
    return 0x1.3958100000000p-3f;
}
