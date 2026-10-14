/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Values {
    float unknown[4];
    float value10, value14, value18, value1C, value20;
};
struct Record {
    char unknown0[0x12];
    unsigned short value12, value14, value16, value18;
    char unknown1A[0x26];
    short value40;
};
extern "C" void func_004430F0(void *context, Record *destination, const Values *source) {
    destination->value16 = (unsigned int)source->value14;
    destination->value18 = (unsigned int)source->value10;
    destination->value12 = (unsigned int)source->value18;
    destination->value14 = (unsigned int)source->value1C;
    destination->value40 = (int)(source->value20 * 10000.0f);
}
