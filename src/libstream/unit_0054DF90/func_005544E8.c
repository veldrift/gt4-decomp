/* compiler: ee-gcc2.96-no-strict-aliasing */
void func_00578500(int);
void free(void *);
int func_00576AD8(void *, void *);
void func_00576B28(void *, void *);
void func_00578168(void *, int, int, void *, int);

struct Request {
    int arg0;
    int arg1;
    int arg2;
    int arg3;
    int arg4;
    int arg5;
};

struct Client {
    int sema;
    char pad4[0x38];
    struct Request *request;
};

int func_005544E8(struct Client *client, int arg1, int arg2, int arg3, void *arg4, void *arg5, int arg6) {
    if (arg6 != 0) {
        func_00576B28(arg4, arg5);
    } else {
        func_00576AD8(arg4, arg5);
    }
    func_00578500(client->sema);
    client->request->arg0 = arg1;
    client->request->arg1 = arg2;
    client->request->arg2 = arg3;
    client->request->arg3 = arg4;
    client->request->arg4 = arg5;
    client->request->arg5 = (int) (arg6 != 0);
    func_00578168(client, 4, 0, client->request, 0x40);
    return client->request->arg2;
}
