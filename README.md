# 4x6 monochrome bitmap font for rendering

A simple and tiny 4x6 bitmap font.

[font4x6_basic.h](font4x6_basic.h) contains unicode points `U+0000` - `U+007F`.

![](images/font.png)

![](images/showcase.png)

> That second image have been scaled by 400% to improve visualization.

## Encoding

Every character in the font is encoded row-wise in 6 bytes.

The least significant bit of each byte corresponds to the first pixel in row.

E.g.: The character `'A'` (0x41 / 65) is encoded as `{ 0x02, 0x05, 0x07, 0x05, 0x05, 0x00 }`

```
0x02 => 0000 0010 => .X....
0x05 => 0000 0101 => X.X...
0x07 => 0000 0111 => XXX...
0x05 => 0000 0101 => X.X...
0x05 => 0000 0101 => X.X...
0x00 => 0000 0000 => ......
```

## Renderer

To visualize the font, a simple renderer is included in [`render.c`](render.c)

```sh
$ gcc render.c -o render
$ ./render 65
 X
X X
XXX
X X
X X
```

## Inspiration

This repository only exists thanks to:

- https://github.com/dhepper/font8x8
- https://alasseearfalas.itch.io/another-tiny-pixel-font-mono-3x5

## LICENSE

This repository is (un)licensed under [Public Domain](LICENSE), so take it and do whatever you want with it. Credits are not required but much appreciated.
