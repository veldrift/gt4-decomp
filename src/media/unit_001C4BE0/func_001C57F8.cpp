typedef int s32;
extern "C" void func_001C4DF8(void *);
extern "C" void func_00574EB0(void *);

#define FIELD(T,p,o) (*(T*)((char*)(p)+(o)))

extern "C" void func_001C57F8(void *self) {
    for (;;) {
        func_00574EB0(self);
        if (FIELD(s32, self, 0x38) != 0) {
            break;
        }
        void *n = FIELD(void *, self, 0x48);
        while (n != 0) {
            func_001C4DF8(FIELD(void *, n, 0));
            n = FIELD(void *, n, 8);
        }
    }
}
