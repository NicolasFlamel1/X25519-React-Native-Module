// Header files
#include "./x25519-react.h"

using namespace std;


// X25519 namespace
namespace X25519 {

	// Header files
	#include "../X25519-NPM-Package-master/main.cpp"
}


// Supporting function implementation

// Secret key from Ed25519 secret key
vector<uint8_t> secretKeyFromEd25519SecretKey(const uint8_t *ed25519SecretKey, size_t ed25519SecretKeySize) {

	// Check if getting secret key from Ed25519 secret key failed
	vector<uint8_t> secretKey(X25519::secretKeySize());
	if(!X25519::secretKeyFromEd25519SecretKey(secretKey.data(), ed25519SecretKey, ed25519SecretKeySize)) {
	
		// Throw error
		throw runtime_error("Getting secret key from Ed25519 secret key failed");
	}
	
	// Return secret key
	return secretKey;
}

// Public key from Ed25519 public key
vector<uint8_t> publicKeyFromEd25519PublicKey(const uint8_t *ed25519PublicKey, size_t ed25519PublicKeySize) {

	// Check if getting public key from Ed25519 public key failed
	vector<uint8_t> publicKey(X25519::publicKeySize());
	if(!X25519::publicKeyFromEd25519PublicKey(publicKey.data(), ed25519PublicKey, ed25519PublicKeySize)) {
	
		// Throw error
		throw runtime_error("Getting public key from Ed25519 public key failed");
	}
	
	// Return public key
	return publicKey;
}

// Shared secret key from secret key and public key
vector<uint8_t> sharedSecretKeyFromSecretKeyAndPublicKey(const uint8_t *secretKey, size_t secretKeySize, const uint8_t *publicKey, size_t publicKeySize) {

	// Check if getting shared secret key from secret key and public key failed
	vector<uint8_t> sharedSecretKey(X25519::sharedSecretKeySize());
	if(!X25519::sharedSecretKeyFromSecretKeyAndPublicKey(sharedSecretKey.data(), secretKey, secretKeySize, publicKey, publicKeySize)) {
	
		// Throw error
		throw runtime_error("Getting shared secret key from secret key and public key failed");
	}
	
	// Return shared secret key
	return sharedSecretKey;
}
