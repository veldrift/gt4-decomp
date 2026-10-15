/* compiler: ee-gcc2.96-nsa-nosib */
struct Global { char unknown[0x39E7C]; int zone; };
extern Global *D_00622F4C;
extern void *D_00623790;
extern "C" int func_00448CA0(int);
extern "C" unsigned long func_00447DD0(unsigned long, int);
extern "C" int func_0044A5A8(void *, int, int);
static inline unsigned long converted(unsigned long code,int kind) { if((int)(code>>32)==kind)code=func_00447DD0(code,kind);return code; }
extern "C" int func_00448C10(unsigned long identifier) {
    int condition = func_00448CA0(D_00622F4C->zone);
    if (condition == 0) return condition;
    unsigned long normalized=converted(identifier,0x26);
    int number=(int)(normalized & 0xFFFFFFFF);
    return func_0044A5A8(D_00623790, number, condition);
}
