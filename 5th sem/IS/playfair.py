def generate_matrix(key):
    matrix = []
    key = ''.join(sorted(set(key), key=key.index)).replace('J', 'I')  # Remove duplicates & merge J with I
    alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
    for char in key:
        if char not in matrix:
            matrix.append(char)
    for char in alphabet:
        if char not in matrix:
            matrix.append(char)
    return matrix

def preprocess(text):
    text = ''.join(e.upper() for e in text if e.isalpha()).replace('J', 'I')
    if len(text) % 2 != 0:
        text += 'X'  # Add 'X' if odd length
    digraphs = [text[i:i+2] if text[i] != text[i+1] else text[i] + 'X' for i in range(0, len(text), 2)]
    return digraphs

def find_position(c, matrix):
    index = matrix.index(c)
    return index // 5, index % 5

def encrypt_digraph(digraph, matrix):
    r1, c1 = find_position(digraph[0], matrix)
    r2, c2 = find_position(digraph[1], matrix)
    if r1 == r2:
        return matrix[r1*5 + (c1+1)%5] + matrix[r2*5 + (c2+1)%5]
    elif c1 == c2:
        return matrix[((r1+1)%5)*5 + c1] + matrix[((r2+1)%5)*5 + c2]
    else:
        return matrix[r1*5 + c2] + matrix[r2*5 + c1]

def decrypt_digraph(digraph, matrix):
    r1, c1 = find_position(digraph[0], matrix)
    r2, c2 = find_position(digraph[1], matrix)
    if r1 == r2:
        return matrix[r1*5 + (c1-1)%5] + matrix[r2*5 + (c2-1)%5]
    elif c1 == c2:
        return matrix[((r1-1)%5)*5 + c1] + matrix[((r2-1)%5)*5 + c2]
    else:
        return matrix[r1*5 + c2] + matrix[r2*5 + c1]

def playfair(text, key, mode='encrypt'):
    matrix = generate_matrix(key)
    digraphs = preprocess(text)
    if mode == 'encrypt':
        return ''.join(encrypt_digraph(d, matrix) for d in digraphs)
    elif mode == 'decrypt':
        result = ''.join(decrypt_digraph(d, matrix) for d in digraphs)
        # Remove filler 'X' only if it's at the end of the plaintext
        if result.endswith('X'):
            result = result.rstrip('X')
        return result

# Example usage:
key = "MONARCHY"
plaintext = "XAVIERS"
ciphertext = playfair(plaintext, key, mode='encrypt')
decrypted_text = playfair(ciphertext, key, mode='decrypt')

print(f"Key: {key}")
print(f"Plaintext: {plaintext}")
print(f"Ciphertext: {ciphertext}")
print(f"Decrypted text: {decrypted_text}")
