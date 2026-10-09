extern "C" void *func_00441248(void *);
extern "C" void *func_004454C0(void *);
extern "C" int func_00448820(void *,void *);
extern "C" int func_00448990(void *);
extern "C" int func_0043F4C8(void *,int);
extern "C" int func_0013F528(void *car) {char metadata[32];int found=func_00448820(func_004454C0(func_00441248(car)),metadata);if(found){int flag=func_00448990(metadata);int result=1;if(!flag)result=func_0043F4C8(car,28)==1;return result;}return found;}