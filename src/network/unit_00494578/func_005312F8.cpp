struct Data { unsigned values[100]; unsigned count; };
extern "C" Data *func_00535970(int);
extern "C" int func_005312F8(unsigned *out, int arg1) {
    unsigned values[100];
    if (!out) return 23;
    Data *data = func_00535970(arg1);
    if (!data) return 22;
    int i;
    for (i = 0; i < 100; i++) values[i] = data->values[i];
    for (i = data->count - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (values[j] > values[j+1]) {
                unsigned t = values[j];
                values[j] = values[j+1];
                values[j+1] = t;
            }
        }
    }
    int index = data->count / 20;
    if (index <= 0) index = 1;
    *out = values[index];
    return 0;
}
