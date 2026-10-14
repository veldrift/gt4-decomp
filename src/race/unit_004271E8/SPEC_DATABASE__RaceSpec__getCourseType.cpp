/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Row { u8 pad[0x10]; u8 type; u8 pad2[0xF]; };
struct Spec { char pad[0xA0]; unsigned key; };
extern "C" int SPEC_DATABASE__DatabaseStorage__getRow_2(void *, int, int, Row *);
extern char D_006235A8[];

static inline bool getRow(unsigned long k, Row *r) {
    return SPEC_DATABASE__DatabaseStorage__getRow_2(D_006235A8, (int)k, 0x22, r) != 0;
}

extern "C" int SPEC_DATABASE__RaceSpec__getCourseType(Spec *self) {
    Row r;
    unsigned long k = self->key;
    if (getRow(k, &r)) return r.type;
    return -1;
}
