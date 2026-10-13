typedef int s32;
struct Text5 { char bytes[5]; };
struct CarRef { char pad[0x14]; s32 id; };
struct Manager;
extern void *D_00624984;
extern "C" const Text5 D_0068F520;
extern char PDISTD__UNIT_MANAGER[];
extern "C" void *func_00441248(s32);
extern "C" char *func_00445F30(void *);
extern "C" const char *func_004726B8(Manager *);
extern "C" char *func_004727B8(Manager *);
extern "C" void func_00490A40(void *, void *, s32, s32, const char *, const char *, char *);
extern "C" void func_00145FE8(CarRef *self, s32 size, char *buffer, s32 value) {
    char *text = func_00445F30(func_00441248(self->id));
    if (*text == '-') {
        *(Text5 *)buffer = D_0068F520;
        return;
    }
    const char *format = func_004726B8((Manager *)PDISTD__UNIT_MANAGER);
    func_00490A40(D_00624984, buffer, size, value, format, text,
                  func_004727B8((Manager *)PDISTD__UNIT_MANAGER));
}
