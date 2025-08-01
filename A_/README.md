# Exercise A: Sidewalk Tiles

**Available memory:** 16 MB

You are given **n** tiles, each of which is characterized by three non‑negative integers  
**ℓ** (left connector), **m** (middle length), and **r** (right connector), as shown:

![Tile shape with left connector ℓ, middle m, and right connector r][def]

Your task is to select a subset of these tiles and arrange them in a linear “sidewalk” so that it:

1. **Starts correctly**: the first tile’s left connector ℓ = 0.  
2. **Connects correctly**: for every two consecutive tiles, the length of the right connector of the first tile was equal to the length of the left connector of the second tile.
3. **Ends correctly**: the last tile’s right connector r = 0.

Each tile may be used at most once, and **no rotations** are allowed.

## Input specification

The first line of input contains a natural number **𝑛 ∈ [1,200,000]**, which is the number of available
tiles. Each of the next **𝑛** lines contains a description of the next tile, consisting of three natural numbers
**ℓ**, **𝑚**, and **𝑟** characterizing the tile. These numbers satisfy the conditions **ℓ**, **$𝑟 ∈ [0,10,000]** and
**𝑚 ∈ [1,10,000]**. Any two tiles are different.

## Output specification

If it is not possible to arrange the tiles in the sidewalk, your program should print the word BRAK in the first and only line of output.
Otherwise, your program should print a positive integer **𝑠** in the first line, which is the number of tiles that make up the sidewalk.
Next, each of the following **𝑠** lines should contain a description of the next tile
that is part of the sidewalk *(three numbers, as in the input data)*. If there is more than one
correct solution, your program can print any of them.

## Examples

### Example A

**Input:**

```text
6
0 1 1
1 1 3
3 1 2
3 1 0
2 1 4
2 1 3
```

**Output:**

```text
3
0 1 1
1 1 3
3 1 0
```

### Example B

**Input:**

```text
5
0 1 1
0 2 2
0 3 2
2 4 3
3 5 0
```

**Output:**

```text
3
0 2 2
2 4 3
3 5 0
```

### Example C

**Input:**

```text
1
0 1 2
```

**Output:**

```text
BRAK
```

---

> **Source:**  
> This problem was assigned as part of the *Algorithms & Data Structures* course (AiSD) in 2025 Summer semester at University of Wrocław by Marcin Bieńkowski

[def]: ./A_/Tile_example.png
