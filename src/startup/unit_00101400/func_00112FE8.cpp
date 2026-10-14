/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
typedef long s64;

struct CarParam {
    s64 key;
    char pad08[0x160 - 8];
    u8 color0;
    u8 color1;
    char pad162[3];
    u8 b165;
    char pad166[2];
};
struct Entry {
    char pad0[0x20];
    CarParam param;
    char pad188[0x3444 - 0x188];
    s32 index;
};
struct Entry0 {
    char pad0[0x68];
    s64 row;
    char pad70[0x14A - 0x70];
    u8 b14A;
};
struct Opt { char pad[0x54]; s32 f54; s32 f58; };
struct Grid { s32 count; s32 f4; Entry **entries; };
struct Course { char pad0[0x60]; Grid *grid; char pad64[0xC]; void *spec; };
struct Race { char pad0[0x6C]; Course *course; };
struct Game { char pad0[0xD8]; Opt opt; char pad134[4]; s32 color; };
struct Self {
    char pad0[0x364];
    s32 a[6];
    s32 b[6];
    s32 c[6];
    s32 f3AC;
    s32 f3B0;
    u8 b3B4;
    u8 b3B5;
    u8 b3B6;
    s32 f3B8;
    s32 f3BC;
    s32 f3C0;
    s32 f3C4;
    char pad3C8[0x488 - 0x3C8];
    s32 f488;
    s32 f48C;
};
struct Info { char d[0x20]; };
struct Row { char pad[0x25]; u8 b25; u8 b26; u8 b27; char pad28[8]; };

struct ShowRoomCar {
    s32 f0;
    char f4;
    void *f8;
    ShowRoomCar() __asm__("func_00364760");
    ShowRoomCar(const ShowRoomCar &);
    ~ShowRoomCar() __asm__("func_003647A0");
    void set(CarParam *param, s32 flag) __asm__("func_00364868");
    s32 getParam(s32 *out, s32 id, s32 flag) __asm__("func_00364E90");
    s32 getValue(s32 id) __asm__("func_00364FA8");
};

extern Game *D_00622F4C;
extern char D_006235A8[];

extern "C" s32 func_00110B70(s32, s32);
extern "C" s32 func_00430878(Opt *);
extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(char *, s64, Row *);
extern "C" s64 func_004454C0(CarParam *);
extern "C" s32 SPEC_DATABASE__RaceSpec__getCourseType(void *);
extern "C" void func_00448820(s64, Info *);
extern "C" s32 func_004489A0(Info *, s32);

extern "C" void func_00112FE8(Self *self, Race *race) {
    Course *course = race->course;
    self->f48C = 1;
    s32 type = SPEC_DATABASE__RaceSpec__getCourseType(course->spec);
    if (type == 2 || type == 3) self->f48C = 0;
    s32 color = D_00622F4C->color;
    if (type == 3) color = 0xC;
    for (s32 i = 0; i <= 0; i++) {
        Entry *e = course->grid->entries[i];
        CarParam *param = &e->param;
        Info info;
        func_00448820(func_004454C0(param), &info);
        u8 c = color;
        param->color0 = c;
        param->color1 = c;
        param->b165 = 1;
        s32 idx = e->index;
        ShowRoomCar car;
        car.set(&course->grid->entries[i]->param, 0);
        s32 out;
        self->a[idx] = car.getParam(&out, 0x7073, 0);
        if (func_004489A0(&info, 3) != 0) self->a[idx] = 0;
        self->b[idx] = car.getValue(0x6B67);
        self->c[idx] = param->color0;
    }
    self->f3AC = 0;
    self->f3B0 = 0;
    self->f3B8 = color;
    self->f3BC = color;
    Game **g = &D_00622F4C;
    self->f3C0 = func_00430878(&(*g)->opt);
    Opt *opt = &(*g)->opt;
    self->f3C4 = func_00110B70(opt->f54, opt->f58);
    Row row;
    SPEC_DATABASE__DatabaseStorage__getRow(D_006235A8, ((Entry0 *)course->grid->entries[0])->row, &row);
    if (row.b25 == 0) {
        self->b3B4 = 0;
        self->b3B5 = 0;
        self->b3B6 = 0;
    } else {
        self->b3B4 = ((Entry0 *)course->grid->entries[0])->b14A;
        self->b3B5 = row.b26;
        self->b3B6 = row.b27;
    }
    self->f488 = 0;
}
