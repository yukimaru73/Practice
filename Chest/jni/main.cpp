#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <mcpe.h>
#include <Substrate.h>
#include "ChestBlockEntity.h"

static bool(*_isLargeChest)(void*);

int (*_getContainerSize)(ChestBlockEntity *);
int getContainerSize(ChestBlockEntity *_chestEntity){
	if(_isLargeChest(_chestEntity)){
		return 1;
	}else{
		return 10;
	}
};

/*bool (*_isLarge)(ChestBlockEntity);
bool isLarge(ChestBlockEntity *_chestEntity){
	return true;
};*/

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*)&ChestBlockEntity::getContainerSize,(void*)&getContainerSize,(void**)&_getContainerSize);
	//MSHookFunction((void*)&ChestBlockEntity::isLargeChest,(void*)&isLarge,(void**)&_isLarge);
	_isLargeChest=(bool(*)(void*))(void*)&ChestBlockEntity::isLargeChest;
	return JNI_VERSION_1_2;
}
//ChestBlockEntity::getContainerSize(void)
//ChestBlockEntity::getMaxStackSize(void)
//ChestBlockEntity::isLargeChest(void)
