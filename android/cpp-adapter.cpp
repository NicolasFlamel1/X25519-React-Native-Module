// Header files
#include <iomanip>
#include <jni.h>
#include <memory>
#include <sstream>
#include "x25519-react.h"

using namespace std;


// Constants

// Hex character length
static const size_t HEX_CHARACTER_LENGTH = (sizeof("FF") - sizeof('\0'));

// Bits in a byte
static const int BITS_IN_A_BYTE = 8;


// Function prototypes

// Native secret key from Ed25519 secret key
extern "C" JNIEXPORT jstring JNICALL Java_com_x25519react_X25519ReactModule_nativeSecretKeyFromEd25519SecretKey(JNIEnv *environment, jclass type, jstring ed25519SecretKey);

// Native public key from Ed25519 public key
extern "C" JNIEXPORT jstring JNICALL Java_com_x25519react_X25519ReactModule_nativePublicKeyFromEd25519PublicKey(JNIEnv *environment, jclass type, jstring ed25519PublicKey);

// Native shared secret key from secret key and public key
extern "C" JNIEXPORT jstring JNICALL Java_com_x25519react_X25519ReactModule_nativeSharedSecretKeyFromSecretKeyAndPublicKey(JNIEnv *environment, jclass type, jstring secretKey, jstring publicKey);

// From hex string
static vector<uint8_t> fromHexString(JNIEnv *environment, jstring hexString);

// To hex string
static jstring toHexString(JNIEnv *environment, const vector<uint8_t> &input);

// Character to number
static uint8_t characterToNumber(char character);


// Supporting function implementation

// Native secret key from Ed25519 secret key
jstring Java_com_x25519react_X25519ReactModule_nativeSecretKeyFromEd25519SecretKey(JNIEnv *environment, jclass type, jstring ed25519SecretKey) {

	// Try
	try {
	
		// Get data from Ed25519 secret key
		const vector<uint8_t> ed25519SecretKeyData = fromHexString(environment, ed25519SecretKey);

		// Return getting secret key from Ed25519 secret key
		return toHexString(environment, secretKeyFromEd25519SecretKey(ed25519SecretKeyData.data(), ed25519SecretKeyData.size()));
	}
	
	// Catch errors
	catch(const exception &error) {
	
		// Check if throwing error failed
		if(environment->ThrowNew(environment->FindClass("java/lang/RuntimeException"), error.what() ? error.what() : "")) {
		
			// Exit
			exit(0);
		}
		
		// Return nothing
		return nullptr;
	}
}

// Native public key from Ed25519 public key
jstring Java_com_x25519react_X25519ReactModule_nativePublicKeyFromEd25519PublicKey(JNIEnv *environment, jclass type, jstring ed25519PublicKey) {

	// Try
	try {
	
		// Get data from Ed25519 public key
		const vector<uint8_t> ed25519PublicKeyData = fromHexString(environment, ed25519PublicKey);

		// Return getting public key from Ed25519 public key
		return toHexString(environment, publicKeyFromEd25519PublicKey(ed25519PublicKeyData.data(), ed25519PublicKeyData.size()));
	}
	
	// Catch errors
	catch(const exception &error) {
	
		// Check if throwing error failed
		if(environment->ThrowNew(environment->FindClass("java/lang/RuntimeException"), error.what() ? error.what() : "")) {
		
			// Exit
			exit(0);
		}
		
		// Return nothing
		return nullptr;
	}
}

// Native shared secret key from secret key and public key
jstring Java_com_x25519react_X25519ReactModule_nativeSharedSecretKeyFromSecretKeyAndPublicKey(JNIEnv *environment, jclass type, jstring secretKey, jstring publicKey) {

	// Try
	try {
	
		// Get data from secret key
		const vector<uint8_t> secretKeyData = fromHexString(environment, secretKey);
		
		// Get data from public key
		const vector<uint8_t> publicKeyData = fromHexString(environment, publicKey);

		// Return getting shared secret key from secret key and public key
		return toHexString(environment, sharedSecretKeyFromSecretKeyAndPublicKey(secretKeyData.data(), secretKeyData.size(), publicKeyData.data(), publicKeyData.size()));
	}
	
	// Catch errors
	catch(const exception &error) {
	
		// Check if throwing error failed
		if(environment->ThrowNew(environment->FindClass("java/lang/RuntimeException"), error.what() ? error.what() : "")) {
		
			// Exit
			exit(0);
		}
		
		// Return nothing
		return nullptr;
	}
}

// From hex string
vector<uint8_t> fromHexString(JNIEnv *environment, jstring hexString) {

	// Initialize release input
	auto releaseInput = [environment, hexString](const char *input) {
	
		// Release input
		environment->ReleaseStringUTFChars(hexString, input);
	};

	// Check if getting input from hex string failed
	const unique_ptr<const char,  decltype(releaseInput)> input(environment->GetStringUTFChars(hexString, nullptr), releaseInput);
	if(!input) {
	
		// Throw error
		throw runtime_error("Getting input from hex string failed");
	}
	
	// Get input length
	const size_t inputLength = strlen(input.get());
	
	// Check if input length is invalid
	if(inputLength % HEX_CHARACTER_LENGTH) {
	
		// Throw error
		throw runtime_error("Input length is invalid");
	}
	
	// Initialize result
	vector<uint8_t> result(inputLength / HEX_CHARACTER_LENGTH);
	
	// Go through all character pairs in the input
	for(size_t i = 0; i < inputLength; i += HEX_CHARACTER_LENGTH) {
	
		// Set value in result
		result[i / HEX_CHARACTER_LENGTH] = (characterToNumber(input.get()[i]) << BITS_IN_A_BYTE / 2) | characterToNumber(input.get()[i + 1]);
	}
	
	// Return result
	return result;
}

// To hex string
jstring toHexString(JNIEnv *environment, const vector<uint8_t> &input) {

	// Initialize result
	ostringstream result;
	
	// Configure result
	result << hex << setfill('0');
	
	// Go through all bytes in the input
	for(const uint8_t byte : input) {
	
		// Append byte to result
		result << setw(HEX_CHARACTER_LENGTH) << static_cast<unsigned>(byte);
	}
	
	// Check if getting result as a string failed
	const jstring resultString = environment->NewStringUTF(result.str().c_str());
	if(!resultString) {
	
		// Throw error
		throw runtime_error("Getting result as a string failed");
	}
	
	// Return result string
	return resultString;
}

// Character to number
uint8_t characterToNumber(char character) {

	// Check character
	switch(character) {
	
		// Zero
		case '0':
		
			// Return number
			return 0;
		
		// One
		case '1':
		
			// Return number
			return 1;
		
		// Two
		case '2':
		
			// Return number
			return 2;
		
		// Three
		case '3':
		
			// Return number
			return 3;
		
		// Four
		case '4':
		
			// Return number
			return 4;
		
		// Five
		case '5':
		
			// Return number
			return 5;
		
		// Six
		case '6':
		
			// Return number
			return 6;
		
		// Seven
		case '7':
		
			// Return number
			return 7;
		
		// Eight
		case '8':
		
			// Return number
			return 8;
		
		// Nine
		case '9':
		
			// Return number
			return 9;
		
		// A
		case 'a':
		case 'A':
		
			// Return number
			return 10;
		
		// B
		case 'b':
		case 'B':
		
			// Return number
			return 11;
		
		// C
		case 'c':
		case 'C':
		
			// Return number
			return 12;
		
		// D
		case 'd':
		case 'D':
		
			// Return number
			return 13;
		
		// E
		case 'e':
		case 'E':
		
			// Return number
			return 14;
		
		// F
		case 'f':
		case 'F':
		
			// Return number
			return 15;
		
		// Default
		default:
		
			// Throw error
			throw runtime_error("Getting character as a number failed");
	}
}
