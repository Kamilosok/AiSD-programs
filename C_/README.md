# Exercise C: Chessboard

**Available memory:** 16 MB

Consider a chessboard with **5** rows and **n** columns. Each cell is colored **black** (`x`) or **white** (`.`). Certain **3×3** patterns are **forbidden**. A coloring is **valid** if **none** of the forbidden patterns appears anywhere on the board (in any contiguous 3×3 block).

For example, suppose the two forbidden patterns are:

For example, suppose the two forbidden patterns are:

<!-- markdownlint-disable MD033 -->
<table>
  <tr>
    <th>Pattern A</th>
    <th>Pattern B</th>
  </tr>
  <tr>
    <td>
<pre>
..x
.x.
x..
</pre>
    </td>
    <td>
<pre>
...
.x.
...
</pre>
    </td>
  </tr>
</table>

Then the left coloring below is valid, while the right one is invalid because it contains Pattern B:

<table>
  <tr>
    <th>Left coloring</th>
    <th>Right coloring</th>
  </tr>
  <tr>
    <td>
<pre>
.......
x.....x
.x.x...
..x....
......x
</pre>
    </td>
    <td>
<pre>
.......
....x..
.......
xxxxxxx
.......
</pre>
    </td>
  </tr>
</table>

## Input specification

In the first line of input there are three positive integers **n**, **p** and **m** separated by single spaces, such that **3 ≤ n ≤ 5000**, **p ≤ 100** and **m ≤ 10<sup>6</sup>**. Here **n** is the number of columns of the board and **p** is the number of forbidden patterns.
<!-- markdownlint-enable MD033 -->

In the next **3p** lines you are given the descriptions of the forbidden patterns. Each pattern consists of three consecutive lines, each containing **exactly** three characters from the set {`x`, `.`}, where `x` denotes a black cell and `.` denotes a white cell. Some patterns may be identical.

## Output specification

Let k be the total number of valid colorings of the 5×n board. Print a single integer:

**``k mod m``**

## Examples

### Example A

**Input:**

```text
3 1 1000000
...
...
...
```

**Output**:

```text
32592
```

### Example B

**Input:**

```text
5 1 1000000
.xx
x..
.xx
```

**Output:**

```text
969696
```

### Example C

**Input:**

```text
10 3 1000000
xxx
x..
.xx
..x
.x.
x..
xxx
x..
.xx
```

**Output:**

```text
904576
```

---

> **Source:**  
> This problem was assigned as part of the *Algorithms & Data Structures* course (AiSD) in 2025 Summer semester at University of Wrocław by Marcin Bieńkowski
