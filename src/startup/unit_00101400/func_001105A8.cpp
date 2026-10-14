/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef long s64;

struct Entry { char pad[0x20]; s64 key; };
struct Grid { char pad[8]; Entry **entries; };
struct Result { s32 mode; u32 time; };
struct Course {
    char pad0[0x60];
    Grid *grid;
    char pad64[0xC];
    void *spec;
    char pad74[0x88 - 0x74];
    Result result;
};

#define V1(n) virtual void n(s32);
#define V10(n) V1(n##0) V1(n##1) V1(n##2) V1(n##3) V1(n##4) V1(n##5) V1(n##6) V1(n##7) V1(n##8) V1(n##9)
class RaceB {
public:
    char pad0[0x64];
    V10(a) V10(b) V10(c) V10(d) V10(e) V10(f) V10(g) V10(h) V10(i) V1(j0) V1(j1) V1(j2) V1(j3) V1(j4)
    virtual s32 getRank(s32 *count);
};
class Race : public RaceB {
public:
    char pad1[0x6C - 0x68];
    Course *course;
};

struct ShowRoomCar {
    s32 f0;
    char f4;
    void *f8;
    ShowRoomCar() __asm__("func_00364760");
    ShowRoomCar(const ShowRoomCar &);
    ~ShowRoomCar() __asm__("func_003647A0");
    void set(s64 *key, s32 flag) __asm__("func_00364868");
    s32 getParam(s32 *out, s32 id, s32 flag) __asm__("func_00364E90");
    s32 getValue(s32 id) __asm__("func_00364FA8");
};

struct Record {
    s32 date;
    s32 car;
    s32 course;
    s32 f0C;
    s32 f10;
    s32 f14;
    s32 f18;
    u32 time;
    s32 rank;
    s32 count;
    const char *name;
    s32 f2C;
};

extern char *D_00622F4C;
extern char D_0068D308[];

extern "C" void func_0010F718(Record *, char *) throw();
extern "C" void func_00430A58(void *, s32, s32);
extern "C" void *func_00430D20(void *, s32);
extern "C" void func_004320B8(void *, u32, s32, char *);
extern "C" void *func_004323D0(void *, s32);
extern "C" s64 func_004454C0(s64 *);
extern "C" s32 SPEC_DATABASE__RaceSpec__getRaceLabel(void *);
extern "C" s32 func_004472A0(void *);
extern "C" s32 func_004482C0(s64);
extern "C" s32 func_00448398(s32);
extern "C" s32 func_0044AC20(void);

extern "C" void func_001105A8(Race *self, s32 *bestKind, u32 *bestTime) {
    s32 kind = 13;
    Course *course = self->course;
    Result *res = &course->result;
    u32 time = res->time;
    s32 label = SPEC_DATABASE__RaceSpec__getRaceLabel(course->spec);
    s32 name = func_004472A0(course->spec);
    switch (res->mode) {
    case 2:
        kind = 9;
        break;
    case 3:
        kind = 10;
        break;
    case 4:
        kind = 11;
        break;
    }
    if (kind == 13) return;
    if (time < *bestTime) {
        *bestKind = kind;
        *bestTime = time;
    }
    char **g = &D_00622F4C;
    func_00430A58(func_00430D20(*g + 0x13E28, label), 1, (u8)kind);
    s32 count;
    s32 rank = self->getRank(&count);
    s64 *key = &course->grid->entries[0]->key;
    ShowRoomCar car;
    car.set(key, 0);
    count -= 1;
    rank -= 4;
    char blk[0x20];
    Record rec;
    s32 out;
    rec.date = func_0044AC20();
    rec.car = func_004482C0(func_004454C0(key));
    rec.course = func_00448398(name);
    rec.f0C = 0;
    rec.f10 = car.getParam(&out, 0x7073, 0);
    rec.f14 = car.getValue(0x6B67);
    rec.f18 = 2;
    rec.time = time;
    rec.rank = rank;
    rec.count = count;
    rec.name = D_0068D308;
    func_0010F718(&rec, blk);
    func_004320B8(func_004323D0(*g + 0x26F30, label + 2), time, (u8)kind, blk);
}
