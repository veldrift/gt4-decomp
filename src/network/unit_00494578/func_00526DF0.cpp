struct Key { unsigned char bytes[4]; };
struct E { int *values; int cached[3]; int count, unused; };
struct S { char pad[0x88]; E *entries; };
extern "C" int func_00523D48(void *, unsigned short *) throw();
extern "C" int func_00528600(S *, E *, unsigned short, unsigned int);
extern "C" int func_00526DF0(S *s, unsigned short index, Key *input) {
    Key key = *input;
    unsigned short slot;
    func_00523D48(s, &slot);
    if (s->entries != 0) {
        E *entry = (E *)(key.bytes[2] * 24 + (int)s->entries);
        int *values = entry->values;
        if (values[slot] != 0) {
            unsigned int i;
            for (i = 0; i < 3; ++i) {
                if (values[index] == entry->cached[i]) entry->cached[i] = 0;
            }
            if (values[index] != 0) {
                int count = entry->count;
                values[index] = 0;
                entry->count = count - 1;
            }
            int r = func_00528600(s, entry, slot, i);
            if (r != 0) return r;
        }
    }
    return 0;
}
