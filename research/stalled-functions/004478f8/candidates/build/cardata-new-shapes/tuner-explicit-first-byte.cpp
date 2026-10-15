struct TunerCodes { unsigned long first; unsigned short last; };
extern "C" int func_004478B8(unsigned long, TunerCodes *);
extern "C" int func_004478F8(unsigned long identifier, int *output, int capacity) {
    if (!output) return 0;
    TunerCodes row;
    if (!func_004478B8(identifier, &row)) return 0;
    TunerCodes codes;
    codes.first = row.first;
    codes.last = row.last;
    int index = 0;
    int count = 0;
    if (capacity > 0) {
        const unsigned char *names = (const unsigned char *)&codes;
        int code = names[0];
        if (code != 0) {
            output[0] = code;
            int *cursor = output;
            count = 1;
            for (;;) {
                ++index;
                ++cursor;
                if (index >= 10) break;
                if (index >= capacity) break;
                code = names[index];
                if (code == 0) break;
                ++count;
                *cursor = code;
            }
        }
    }
    return count;
}
