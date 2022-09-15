// Package
package com.x25519react;


// Imports
import androidx.annotation.NonNull;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.module.annotations.ReactModule;


// Classes

// X25519 React module class
@ReactModule(name = X25519ReactModule.NAME)
public class X25519ReactModule extends ReactContextBaseJavaModule {

	// Name
	public static final String NAME = "X25519React";
	
	// Static
	static {
	
		// Try
		try {
		
			// Load library
			System.loadLibrary("X25519React");
		}
		
		// Catch errors
		catch(Exception error) {
		
		}
	}

	// Constructor
	public X25519ReactModule(ReactApplicationContext reactContext) {
	
		// Delegate constructor
		super(reactContext);
	}

	// Get name
	@Override
	@NonNull
	public String getName() {
	
		// Return name
		return NAME;
	}
	
	// Secret key from Ed25519 secret key
	@ReactMethod
	public void secretKeyFromEd25519SecretKey(String ed25519SecretKey, Promise promise) {

		// Try
		try {

			// Resolve promise to native secret key from Ed25519 secret key
			promise.resolve(nativeSecretKeyFromEd25519SecretKey(ed25519SecretKey));
		}

		// Catch errors
		catch(Exception error) {

			// Reject promise
			promise.reject("Error", error);
		}
	}
	
	// Public key from Ed25519 public key
	@ReactMethod
	public void publicKeyFromEd25519PublicKey(String ed25519PublicKey, Promise promise) {

		// Try
		try {

			// Resolve promise to native public key from Ed25519 public key
			promise.resolve(nativePublicKeyFromEd25519PublicKey(ed25519PublicKey));
		}

		// Catch errors
		catch(Exception error) {

			// Reject promise
			promise.reject("Error", error);
		}
	}
	
	// Shared secret key from secret key and public key
	@ReactMethod
	public void sharedSecretKeyFromSecretKeyAndPublicKey(String secretKey, String publicKey, Promise promise) {

		// Try
		try {

			// Resolve promise to native shared secret key from secret key and public key
			promise.resolve(nativeSharedSecretKeyFromSecretKeyAndPublicKey(secretKey, publicKey));
		}

		// Catch errors
		catch(Exception error) {

			// Reject promise
			promise.reject("Error", error);
		}
	}
	
	// Native secret key from Ed25519 secret key prototype
	private static native String nativeSecretKeyFromEd25519SecretKey(String ed25519SecretKey);
	
	// Native public key from Ed25519 public key
	private static native String nativePublicKeyFromEd25519PublicKey(String ed25519PublicKey);
	
	// Native shared secret key from secret key and public key
	private static native String nativeSharedSecretKeyFromSecretKeyAndPublicKey(String secretKey, String publicKey);
}
