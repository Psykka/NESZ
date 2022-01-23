Before starting I would like to thank the original author of the post, for helping me understand better about emulation. I decided to republish this post in the form of **Markdown** because the original post published on [site](http://www.obelisk.me.uk/6502/index.html) was lost the domain, I was only able to restore its original content by because of [Way Back Machine](http://web.archive.org/web/*/http://www.obelisk.me.uk/6502/index.html)

Enjoy ;)


*Introduction*
==============

My first computer, a BBC Microcomputer Model B, was powered by a 6502 processor and I spent many hours writing and debugging assembly language programs for it (I was the author of CodeKit, co-author of SupaStore and lots of other stuff). I managed to hold on to my BBC until 1989 when my wife insisted that I got rid of it before I bought my first Intel based PC.

Sometime in 1998 I found an emulator called 'pcBBC' on the web. It was very good BBC emulator and it reawakened my interest in 6502 assembly programming. Unfortunate pcBBC did not survive the various updates to Microsoft Windows and now I use BeebEm.

The assembler that I started with ([AS65](Downloads.md#useful-tools)) runs under DOS (or in a DOS window) and can assemble a 16Kb ROM almost instantly (on a Pentium III 500Mhz). When I was developing on my BBC I used to break for a cup of tea (or two) when the assembler was running!

More recently I have written my own Java based 6502 assembler which supports relocatable code and some simple structured programming constructs (e.g. if/then/else).

Contents
--------

Originally this was all in one HTML file but it grew too big for any of my editors to handle without crashing so I had to cut it up into 8 sections.

- [Architecture](Architecture.md) describes the few basic details of the processor.
- [Registers](Registers.md) goes over each of the internal registers and their use.
- [Instructions](Instructions.md) gives a summary of whole instruction set.
- [Addressing](Addressing.md) describes each of the 6502 memory addressing modes.
- [Algorithms](Algorithms.md) contains examples of basic 6502 coding.
- [Reference](Reference.md) describes the complete instruction set in detail.
- [Downloads](Downloads.md) contains some files useful for 6502 programming.
- [Links](Links.md) contains some links to other sites worth visiting.

Click on any of the above links or the links at the bottom of each page to move between the sections.

--------------------------------------------------
[Next &rarr;](Architecture.md)