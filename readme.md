# Vigenère Cipher Implementation

This repository contains a Vigenère cipher encryption and decryption tool implemented in C. The Vigenère cipher is a classical encryption algorithm based on a series of Caesar ciphers using a keyword.

## Features
- Encrypts plaintext using the Vigenère cipher.
- Decrypts ciphertext back to plaintext.
- Validates input for non-alphabetic characters.
- Command-line interface for easy interaction.

## Requirements
- GCC or any C compiler.
- Compatible with Linux and Windows.

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/N111X/Cifrador-Vigenere.git
   cd Cifrador-Vigenere
   ```
2. Compile the source code:
   ```bash
   gcc vigenere.c -o vigenere
   ```

## Usage
1. Run the program and follow the prompts:
   ```bash
   ./vigenere
   ```
2. Choose between encryption and decryption.
3. Enter the plaintext or ciphertext as prompted.
4. Provide the keyword (case-insensitive).
5. View the resulting encrypted or decrypted text.

### Example
#### Encryption:
Input:
- Plaintext: `HELLO`
- Keyword: `KEY`

Output:
- Ciphertext: `RIJVS`

#### Decryption:
Input:
- Ciphertext: `RIJVS`
- Keyword: `KEY`

Output:
- Plaintext: `HELLO`

## Technical Details
- **Case-insensitive:** Both the plaintext and the keyword are processed as uppercase.
- **Alphabetic validation:** Non-alphabetic characters are ignored during processing.
- **Shift Calculation:** Uses modular arithmetic to cycle through the alphabet.

## Limitations
- Designed for English alphabet only (A-Z).
- Input validation could be expanded for better user experience.

## Future Work
- Support for multilingual encryption.
- Add an option for saving results to a file.
- Enhance input handling for larger text files.

## Disclaimer
This tool is intended for educational purposes only and is not suitable for secure communication in modern applications.
