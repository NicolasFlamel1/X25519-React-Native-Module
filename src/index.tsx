// Imports
import { NativeModules, Platform } from "react-native";
import { Buffer } from "buffer";


// Check if X25519 React module doesn't exist
if(!NativeModules.X25519React) {

	// Throw error
	throw new Error("The package '@nicolasflamel/x25519-react' doesn't seem to be linked. Make sure: \n\n" + Platform.select({
		ios: "- You have run 'pod install'\n",
		default: ""
	}) + "- You rebuilt the app after installing the package\n- You are not using Expo managed workflow\n");
}


// Classes

// X25519 class
export default class X25519 {

	// Operation failed
	public static readonly OPERATION_FAILED = null;

	// Secret key from Ed25519 secret key
	static async secretKeyFromEd25519SecretKey(
		ed25519SecretKey: Buffer
	): Promise<Buffer | null> {
	
		// Try
		try {
	
			// Return getting secret key from Ed25519 secret key with X25519 React module
			return Buffer.from(await NativeModules.X25519React.secretKeyFromEd25519SecretKey(ed25519SecretKey.toString("hex")), "hex");
		}
		
		// Catch errors
		catch(
			error: any
		) {
		
			// Return operation failed
			return X25519.OPERATION_FAILED;
		}
	}
	
	// Public key from Ed25519 public key
	static async publicKeyFromEd25519PublicKey(
		ed25519PublicKey: Buffer
	): Promise<Buffer | null> {
	
		// Try
		try {
	
			// Return getting public key from Ed25519 public key with X25519 React module
			return Buffer.from(await NativeModules.X25519React.publicKeyFromEd25519PublicKey(ed25519PublicKey.toString("hex")), "hex");
		}
		
		// Catch errors
		catch(
			error: any
		) {
		
			// Return operation failed
			return X25519.OPERATION_FAILED;
		}
	}
	
	// Shared secret key from secret key and public key
	static async sharedSecretKeyFromSecretKeyAndPublicKey(
		secretKey: Buffer,
		publicKey: Buffer
	): Promise<Buffer | null> {
	
		// Try
		try {
	
			// Return getting shared secret key from secret key and public key with X25519 React module
			return Buffer.from(await NativeModules.X25519React.sharedSecretKeyFromSecretKeyAndPublicKey(secretKey.toString("hex"), publicKey.toString("hex")), "hex");
		}
		
		// Catch errors
		catch(
			error: any
		) {
		
			// Return operation failed
			return X25519.OPERATION_FAILED;
		}
	}
}
