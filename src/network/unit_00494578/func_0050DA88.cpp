struct Entry { int key; int value; };
extern "C" Entry D_0064A4A8[];
extern "C" int func_0050DA88(int key) {
    int i;
    for (i = 0; D_0064A4A8[i].key != 0xFFFFFF; i++) {
        if (D_0064A4A8[i].key == key) break;
    }
    return D_0064A4A8[i].value;
}
