import random

# Function to perform modular exponentiation
def power(base, exponent, mod):
    result = 1
    base = base % mod  # Update base if it is more than or equal to mod
    while exponent > 0:
        if (exponent % 2) == 1:  # If exponent is odd, multiply base with the result
            result = (result * base) % mod
        exponent = exponent >> 1  # Divide the exponent by 2
        base = (base * base) % mod  # Square the base
    return result

# New prime number (p) and primitive root (g) agreed upon by both parties
p = 29  # A new prime number
g = 6   # A new primitive root for p

# Private keys for Alice and Bob
alice_private_key = random.randint(1, p - 1)
bob_private_key = random.randint(1, p - 1)

# Calculate public keys
alice_public_key = power(g, alice_private_key, p)
bob_public_key = power(g, bob_private_key, p)

# Exchange public keys and compute the shared secret key
alice_shared_secret = power(bob_public_key, alice_private_key, p)
bob_shared_secret = power(alice_public_key, bob_private_key, p)

# Output all information
print("\nDiffie-Hellman Key Exchange")
print("-----------------------------")
print(f"Prime (p): {p}")
print(f"Primitive root (g): {g}")
print(f"Alice's private key: {alice_private_key}")
print(f"Bob's private key: {bob_private_key}")
print(f"Alice's public key: {alice_public_key}")
print(f"Bob's public key: {bob_public_key}")
print(f"Alice's shared secret: {alice_shared_secret}")
print(f"Bob's shared secret: {bob_shared_secret}")

# Verify that both shared secrets are the same
assert alice_shared_secret == bob_shared_secret, "Shared secrets do not match!"
print(f"Shared secret key: {alice_shared_secret}")

