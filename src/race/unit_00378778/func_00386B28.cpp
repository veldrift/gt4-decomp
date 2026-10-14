struct Elem {
    char pad[0x370];
};

extern "C" void func_003867A0(Elem *e, float t);

extern "C" void func_00386B28(Elem *first, float t) {
    for (int i = 0; i < 2; i++)
        func_003867A0(first++, t);
}
