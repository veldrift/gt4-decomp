struct TunerCodes { unsigned long first; unsigned short last; };
extern "C" int func_004478B8(unsigned long, TunerCodes *);
extern "C" int func_004478F8(unsigned long identifier, int *output, int capacity) {
    if (!output) return 0;
    TunerCodes row;
    if (!func_004478B8(identifier, &row)) return 0;
    TunerCodes codes;
    codes.first = row.first;
    codes.last = row.last;
    int count = 0;
    const unsigned char *names = (const unsigned char *)&codes;
    int i = 0;
    while (i < 10 && i < capacity) {
        int code = names[i++];
        if (code == 0) break;
        output[count++] = code;
    }
    return count;
}
