typedef int s32;
extern char D_008286F0[];
extern "C" void func_001C5220(void *);
extern "C" void func_001C52E8(void *);
extern "C" void func_001C5370(void *);
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);

#define FIELD(T,p,o) (*(T*)((char*)(p)+(o)))

extern "C" void func_001C4D90(void *self) {
    func_00576788(D_008286F0);
    if (FIELD(s32, self, 0x274) != 0) {
        FIELD(s32, self, 0x274) = 0;
        func_001C52E8(self);
        func_001C5370(self);
        func_001C5220(self);
    }
    func_005767C0(D_008286F0);
}
