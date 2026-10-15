typedef unsigned long long u64;
struct TunerCodes { u64 first; unsigned short last; };
extern "C" int func_004478B8(void *, TunerCodes *);
extern "C" int func_004478F8(void *car, int *output, int capacity) {
    if (!output) return 0;
    TunerCodes row;
    if (!func_004478B8(car, &row)) return 0;
    TunerCodes codes;
    codes.first = row.first;
    codes.last = row.last;
    int count = 0;
    const unsigned char *names = (const unsigned char *)&codes;
    for (int i = 0; i < 10 && i < capacity && names[i]; ++i) {
        output[count++] = names[i];
    }
    return count;
}
