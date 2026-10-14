extern int D_00634BC8;
extern int InitWnn(const char*);
extern "C" int func_004B3E50(const char* arg) {
 if(!D_00634BC8) {D_00634BC8=1;return InitWnn(arg);}
 return 0;
}
