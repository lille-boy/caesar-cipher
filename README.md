# Caesar cipher

## Goal
Implement a Caesar cipher, both encoding and decoding.

## Description
The key is an integer from 1 to 25. This cipher rotates the letters of the alphabet (A to Z).
The encoding replaces each letter with the 1st to 25th next letter in the alphabet (wrapping Z to A).
So key 2 encrypts "HI" to "JK", but key 20 encrypts "HI" to "BC".

Note: this simple "monoalphabetic substitution cipher" provides almost no security, because an attacker who has the encoded message can either use frequency analysis to guess the key, or just try all 25 keys.

## Usage
### Build

`make`

### Execute

Takes 4 arguments:
* Option
   * Encode: e
   * Decode: d
* Key: number between 1 and 25
* Input file: txt format
* Output file: txt format

Execute. Examples:
1. Encode with key = 2

`./caesar e 2 message.txt encode.txt`

2. Decode, you need to enter the original key used for encoding

`./caesar d 2 encode.txt decode.txt`

## Reference
[Caesar cipher on Wikipedia](https://en.wikipedia.org/wiki/Caesar_cipher)
