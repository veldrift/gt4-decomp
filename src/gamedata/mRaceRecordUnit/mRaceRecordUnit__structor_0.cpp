// Native object wrapper: the constructor installs its read-only data pointer.
struct RefCounter {int unknown0;virtual ~RefCounter();};
struct hObject:RefCounter {hObject() __asm__("func_0030A678");virtual ~hObject();int unknown8,unknownC;};
struct mRaceRecordUnit:hObject {void* const data;mRaceRecordUnit(void*) __asm__("func_001A49E8");virtual ~mRaceRecordUnit();};
mRaceRecordUnit::mRaceRecordUnit(void* value):data(value){}
