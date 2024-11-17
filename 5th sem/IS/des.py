from Crypto.Cipher import DES
from Crypto.Util.Padding import pad, unpad

# Function to encrypt plaintext using DES
def encrypt_des(plaintext, key):
    # Ensure the key is exactly 8 bytes (64 bits)
    key = key.encode()[:8]  # Convert to bytes and trim to 8 bytes
    
    # Create a DES cipher object in ECB mode
    cipher = DES.new(key, DES.MODE_ECB)
    
    # Pad plaintext to make it a multiple of 8 bytes (64 bits)
    padded_plaintext = pad(plaintext.encode(), DES.block_size)
    
    # Encrypt the padded plaintext
    ciphertext = cipher.encrypt(padded_plaintext)
    
    return ciphertext

# Function to decrypt ciphertext using DES
def decrypt_des(ciphertext, key):
    # Ensure the key is exactly 8 bytes (64 bits)
    key = key.encode()[:8]  # Convert to bytes and trim to 8 bytes
    
    # Create a DES cipher object in ECB mode
    cipher = DES.new(key, DES.MODE_ECB)
    
    # Decrypt the ciphertext
    decrypted_data = cipher.decrypt(ciphertext)
    
    # Unpad the decrypted data to get the original plaintext
    plaintext = unpad(decrypted_data, DES.block_size).decode()
    
    return plaintext

# Main function
if __name__ == "__main__":
    # Example plaintext and key (both should be 8 bytes for DES)
    plaintext = "IamSajjit"  # 16 characters = 128 bits
    key = "133457799bbcdff1"  # 16 hex digits = 64-bit key
    
    print(f"Original Plaintext: {plaintext}")
    print(f"Key: {key}")
    
    # Encrypt the plaintext
    ciphertext = encrypt_des(plaintext, key)
    print(f"Ciphertext: {ciphertext.hex()}")  # Print ciphertext as hex
    
    # Decrypt the ciphertext
    decrypted_text = decrypt_des(ciphertext, key)
    print(f"Decrypted Plaintext: {decrypted_text}")
