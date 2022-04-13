***HILL CYPHER ALGORITHM***

Hill cipher is a polygraphic substitution cipher based on linear algebra.Each letter is represented by a number modulo 26. Often the simple scheme A = 0, B = 1, …, Z = 25 is used, but this is not an essential feature of the cipher.

**Encryption**

To encrypt a message, each block of n letters (considered as an n-component vector) is multiplied by an invertible n × n matrix, against modulus 26. User inputs a 3x3 (Key) matrix and then a 3 letter string (Plaintext). The 3x3 matrix is multiplied by the 1x3 key so we have the encrypted message.

**Decryption**

To decrypt the message, each block is multiplied by the inverse of the matrix used for encryption.
The matrix used for encryption is the cipher key, and it should be chosen randomly from the set of invertible n × n matrices (modulo 26). We find the inverse of the 3x3 matrix and then multiply it by the encrypted string.
