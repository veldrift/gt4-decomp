struct Record { char bytes[0x44]; };
struct Key { unsigned char bytes[4]; };
struct E { Record **values; Record *cached[3]; int count, unused; };
struct S { char pad[0x84]; Record *records; E *entries; };
extern "C" int func_00523D48(void *, unsigned short *) throw();
extern "C" int func_00528600(S *, E *, unsigned short);
extern "C" int func_00526D28(S *s, unsigned short index, Key *input) {
    Key key = *input;
    unsigned short slot;
    func_00523D48(s, &slot);
    if (s->entries != 0) {
        E *entry = (E *)(key.bytes[2] * 24 + (int)s->entries);
        Record **values = entry->values;
        if (values[slot] != 0) {
            if (values[index] == 0) {
                Record *records = s->records;
                int n = entry->count;
                values[index] = records + index;
                n++;
                entry->count = n;
                int r = func_00528600(s, entry, slot);
                if (r != 0) return r;
            } else return 0;
        }
    }
    return 0;
}
