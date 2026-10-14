/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0xe46c]; int active; int reserved; float value; union { long both; int words[2]; } pair; };
extern Obj *D_006201C8;
extern "C" float func_00336368(int *a, int *b) {
    if (D_006201C8->pair.both == 0) D_006201C8->active = 0;
    if (D_006201C8->active != 0) { *a = 0; *b = 0; return 0.0f; }
    if (a) *a = D_006201C8->pair.words[0];
    if (b) *b = D_006201C8->pair.words[1];
    return D_006201C8->value;
}
