/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node {
    int link : 13;
    unsigned rest : 19;
    char pad[0x3C];
};
struct Pool {
    Node *recs;
    unsigned short head;
    short idx;
    int arr[11];
};
extern "C" void func_004AC41C(float);

extern "C" void func_003E7538(Pool *p) {
    p->head = -1;
    p->idx = 0;
    int i = 0;
    do {
        p->recs[i].link = i + 1;
    } while (++i < 255);
    p->recs[255].link = -1;
    for (i = 10; i >= 0; i--) p->arr[i] = 0;
    func_004AC41C(0.1f);
}
