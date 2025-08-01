# Exercise B: Multiplication table

**Available memory:** 24 MB

Consider the **M × M** multiplication table: it has **M** columns and **M** rows, and at the intersection of column **i** and row **j** sits the value **i × j**. For example, when **M = 4**, the table is:

<!-- markdownlint-disable MD033 -->
<p align="center">
  <table>
    <tr><td>1</td><td>2</td><td>3</td><td>4</td></tr>
    <tr><td>2</td><td>4</td><td>6</td><td>8</td></tr>
    <tr><td>3</td><td>6</td><td>9</td><td>12</td></tr>
    <tr><td>4</td><td>8</td><td>12</td><td>16</td></tr>
  </table>
</p>

Your task is to print the **k largest distinct numbers** appearing in this table, in **descending order**.

**Note:** You **must not** use any built‑in priority‑queue or ordered‑set data structures from your language’s standard library. In C++, for example, it is forbidden to use `std::set`, `std::map`, or `std::priority_queue`.

## Input specification

The first and only line of input contains two numbers **𝑀** and **𝑘** separated by
a single space, such that **1 ⩽ 𝑀 ⩽ 10<sup>6</sup>** and **1 ⩽ 𝑘 ⩽ 2 · 10<sup>6</sup>**.
<!-- markdownlint-enable MD033 -->

You may assume that the numbers are chosen so that the multiplication table **𝑀 × 𝑀** contains at least 𝑘 different numbers.

## Output specification

Your program should print **𝑘** lines containing the **𝑘** largest numbers from the multiplication table
**𝑀 × 𝑀** sorted from largest to smallest.

## Examples

### Example A

**Input:**

```text
4 4
```

**Output:**

```text
16
12
9
8
```

### Example B

**Input:**

```text
3 6
```

**Output:**

```text
9
6
4
3
2
1
```

### Example C

**Input:**

```text
5 2
```

**Output:**

```text
25
20
```

---

> **Source:**  
> This problem was assigned as part of the *Algorithms & Data Structures* course (AiSD) in 2025 Summer semester at University of Wrocław by Marcin Bieńkowski
