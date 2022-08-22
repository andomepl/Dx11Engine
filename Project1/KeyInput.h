#pragma once
#include<stdint.h>

class Key {


	enum class KeyStatus:uint8_t{

		Press,
		Release,
		Invalid



	};

	KeyStatus GetCurrentKeyStatus() {

		return keystatus;
	}


	Key() = default;

	Key(KeyStatus _keystatus, unsigned char _keyvalue) :keystatus(_keystatus), keyvalue(_keyvalue) {}

	void SetKetValue(KeyStatus _keystatus,unsigned char _keyvalue) {

		keystatus = _keystatus;

		keyvalue = _keyvalue;
	}



private:

	KeyStatus keystatus{ KeyStatus ::Invalid};

	unsigned char keyvalue{0u};

};