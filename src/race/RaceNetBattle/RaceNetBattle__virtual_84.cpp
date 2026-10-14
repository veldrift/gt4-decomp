/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" char D_00645570[];
extern "C" int func_004F9E60(char *, int);
extern "C" int func_004F9EC0(char *, int);
extern "C" void func_004FB110(char *, int, int);
extern "C" void RaceNetBattle__virtual_84(void *self, int car, int value) {
    if (func_004F9EC0(D_00645570, func_004F9E60(D_00645570, *(int *)(D_00645570 + 0xcc4))) == car) {
        func_004FB110(D_00645570, value, 0x30);
    }
}
