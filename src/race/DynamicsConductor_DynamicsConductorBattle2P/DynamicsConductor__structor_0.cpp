/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00343490(char *) throw();
extern "C" void func_00386A38(char *, float);
extern "C" void EnemyLineProcessorOld__structor_0(char *);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" char DynamicsConductor__vtable[];
extern "C" void DynamicsConductor__structor_0(char *self) {
    char *p = self + 0x6698;
    *(char **)(self + 0x10140) = DynamicsConductor__vtable;
    for (int i = 5; i != -1; --i) {
        func_00343490(p + 0x6DC);
        func_00386A38(p + 0x9A0, 0.0f);
        p += 0x10A0;
    }
    EnemyLineProcessorOld__structor_0(self + 0xDA50);
    for (int i = 5; i != -1; --i) {
        for (int j = 7; j != -1; --j) {}
    }
    func_005A48D8(self + 0xF818, 0, 0x80);
    *(float *)(self + 0xCBF8) = 1.0f;
}
