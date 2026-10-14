typedef unsigned long long Key;
extern "C" int func_001CBD70(signed char);
extern "C" Key __muldi3(Key,Key);
extern "C" Key func_001CBDC8(const signed char*text,int count){int i=0;Key weight=1;Key result=0;for(;i<count;++i){int digit=func_001CBD70(*text++);if(digit<0)return (Key)-1;result+=__muldi3(weight,digit);weight<<=6;}return result;}
