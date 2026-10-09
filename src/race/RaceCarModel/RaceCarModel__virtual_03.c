struct Obj {
    char pad[0x1670];
    int field1670;
    int field1674;
};

void func_003B0FF0(void *, float);

static inline void update(void *obj) {
    func_003B0FF0(obj, 0x1.111110p-6f);
}

void RaceCarModel__virtual_03(struct Obj *arg0) {
    if (arg0->field1670 == 0) return;
    {
        update((char *)arg0 + 0x5E0);
        if (arg0->field1674 != 0) {
            update((char *)arg0 + 0xE20);
        }
    }
}
