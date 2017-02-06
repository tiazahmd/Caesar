## Caesar
A C program that does Caesar cipher.

#### Background
Supposedly, Caesar (yes, that Caesar) used to "encrypt" (i.e., conceal in a reversible way) confidential messages by shifting each letter therein by some number of places. For instance, he might write A as B, B as C, C as D, …​, and, wrapping around alphabetically, Z as A. And so, to say HELLO to someone, Caesar might write IFMMP. Upon receiving such messages from Caesar, recipients would have to "decrypt" them by shifting letters in the opposite direction by the same number of places.

The secrecy of this "cryptosystem" relied on only Caesar and the recipients knowing a secret, the number of places by which Caesar had shifted his letters (e.g., 1). Not particularly secure by modern standards, but, hey, if you’re perhaps the first in the world to do it, pretty secure!

Unencrypted text is generally called plaintext. Encrypted text is generally called ciphertext. And the secret used is called a key.

#### Specification
Design and implement a program, caesar, that encrypts messages using Caesar’s cipher.

- Implement your program in a file called caesar.c in a directory called caesar.

- Your program must accept a single command-line argument, a non-negative integer. Let’s call it k for the sake of discussion.

- If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.

- You can assume that, if a user does provide a command-line argument, it will be a non-negative integer (e.g., 1). No need to check that it’s indeed numeric.

- Do not assume that k will be less than or equal to 26. Your program should work for all non-negative integral values of k less than 231 - 26. In other words, you don’t need to worry if your program eventually breaks if the user chooses a value for k that’s too big or almost too big to fit in an int. (Recall that an int can overflow.) But, even if k is greater than 26, alphabetical characters in your program’s input should remain alphabetical characters in your program’s output. For instance, if k is 27, A should not become [ even though [ is 27 positions away from A in ASCII, per asciichart.com; A should become B, since B is 27 positions away from A, provided you wrap around from Z to A.

- Your program must output plaintext: (without a newline) and then prompt the user for a string of plaintext (using get_string).

- Your program must output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext "rotated" by k positions; non-alphabetical characters should be outputted unchanged.

- Your program must preserve case: capitalized letters, though rotated, must remain capitalized letters; lowercase letters, though rotated, must remain lowercase letters.

- After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.

## Vigenere
A C program that does Vigenere cipher.

#### Background
Vigenère’s cipher improves upon Caesar’s cipher by encrypting messages using a sequence of keys (or, put another way, a keyword). In other words, if p is some plaintext and k is a keyword (i.e., an alphbetical string, whereby A represents 0, B represents 1, C represents 2, …​, and Z represents 25), then each letter, ci, in the ciphertext, c, is computed as: ci=(pi+kj)mod26
Note this cipher’s use of kj as opposed to just k. And if k is shorter than p, then the letters in k must be reused cyclically as many times as it takes to encrypt p.

In other words, if Vigenère himself wanted to say HELLO to someone confidentially, using a keyword of, say, ABC, he would encrypt the H with a key of 0 (i.e., A), the E with a key of 1 (i.e., B), and the first L with a key of 2 (i.e., C), at which point he’d be out of letters in the keyword, and so he’d reuse (part of) it to encrypt the second L with a key of 0 (i.e., A) again, and the O with a key of 1 (i.e., B) again. And so he’d write HELLO as HFNLP.

#### Specification
Design and implement a program that encrypts messages using Vigenère’s cipher.

- Implement your program in a file called vigenere.c in a directory called vigenere.

- Your program must accept a single command-line argument: a keyword, k, composed entirely of alphabetical characters.

- If your program is executed without any command-line arguments, with more than one command-line argument, or with one command-line argument that contains any non-alphabetical character, your program should print an error (of your choice) and exit immediately, with main returning 1 (thereby signifying an error).

- Otherwise, your program must proceed to prompt the user for a string of plaintext, p, (as by a prompt for plaintext:) which it must then encrypt according to Vigenère’s cipher with k, ultimately printing the result (prepended with ciphertext: and ending with a newline) and exiting, with main returning 0.

- With respect to the characters in k, you must treat A and a as 0, B and b as 1, …​ , and Z and z as 25.

- Your program must only apply Vigenère’s cipher to a character in p if that character is a letter. All other characters (numbers, symbols, spaces, punctuation marks, etc.) must be outputted unchanged. Moreover, if your code is about to apply the jth character of k to the ith character of p, but the latter proves to be a non-alphabetical character, you must wait to apply that jth character of k to the next alphabetical character in p; you must not yet advance to the next character in k.

- Your program must preserve the case of each letter in p.
