# n64-northsec-2022
N64 Reverse Engineering Challenges for Northsec CTF 2022

In the event you had access to the following:
- `n64_puzzle.n64` is the rom.
- `n64_puzzle.out` is the symbol file.

Please check out these fantastic write-ups!
- http://jackmc.xyz/2022/05/23/N64-ROM-Reverse-Engineering.html
- https://blog.quantumlyconfused.com/ctf/2022/05/22/nsec2022-n64/
- https://github.com/wernerburat/ctf-writeups/blob/main/_2022/NorthSec%202022/The%20Legend%20of%20Shiitakoin%20Early%20Access/writeup.md


```
SOLUTIONS

------------------------------------------

Level - 1

the expected values are A3 5E 8D 3F

the flag is:
FLAG-HZQCFVZXSRSFEAUBSXA

You need to first, understand how controller inputs are taken and where they are validated.

I left symbols in so if you read some N64 development docs for nusys you shouldn't have any trouble finding one of them.

The routine is as follows:
- value_1 is an XOR of the first and second numbers, we then use bit masks to validate the most and least significant bits of the byte seperately

- value_2 uses the third number, it has a right shift applied to it. The shift is determined by applying a bitmask to the first input.

- value_3 uses the fourth input and is looped on an AND and an OR with the count

---------------------------------

Level - 2

the expected coordinate is:
    // ( A3, 4E )
    // 1010 0011
    A3 = 1010 0011
    4E = 0100 1110

temp_buf[0] & 0x80) != 0x80
temp_buf[0] & 0x20) != 0x20
temp_buf[0] & 0x40) != 0x00
temp_buf[0] & 0x02) != 0x02
temp_buf[0] & 0x01) != 0x01
temp_buf[0] & 0x10) != 0x00
temp_buf[0] & 0x08) != 0x00
temp_buf[0] & 0x04) != 0x00

temp_buf[1] & 0x01) != 0x00
temp_buf[1] & 0x80) != 0x00
temp_buf[1] & 0x40) != 0x40
temp_buf[1] & 0x20) != 0x00
temp_buf[1] & 0x04) != 0x04
temp_buf[1] & 0x02) != 0x02
temp_buf[1] & 0x10) != 0x00
temp_buf[1] & 0x08) != 0x08

The coordinate has a series of single bit bitmasks applied to them in order to validate that every bit is correct.

the flag is:
FLAG-HZQCFXWFJMPTJSMCMFMB
```
