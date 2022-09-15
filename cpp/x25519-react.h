// Header guard
#ifndef X25519_REACT_H
#define X25519_REACT_H


// Header files
#include <vector>

using namespace std;


// Function prototypes

// Secret key from Ed25519 secret key
vector<uint8_t> secretKeyFromEd25519SecretKey(const uint8_t *ed25519SecretKey, size_t ed25519SecretKeySize);

// Public key from Ed25519 public key
vector<uint8_t> publicKeyFromEd25519PublicKey(const uint8_t *ed25519PublicKey, size_t ed25519PublicKeySize);

// Shared secret key from secret key and public key
vector<uint8_t> sharedSecretKeyFromSecretKeyAndPublicKey(const uint8_t *secretKey, size_t secretKeySize, const uint8_t *publicKey, size_t publicKeySize);


#endif
