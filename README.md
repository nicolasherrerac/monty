# Monty Interpreter

This interpreter reads Monty bytecode files of any extension (preferably `.m` although it doesn't matter), and interprets the opcodes contained.

It was built in the C language and is compliant with `ISO90`, `ISO99`, & `ISO11`.

The interpreter can handle a variety of Monty opcodes, all handled opcodes are listed below.

## Monty Opcodes

* **push**
  * Usage: `push <int>`
  * Pushes an element to the stack and queue.
  * The parameter `<int>` must be an integer.

* **pall**
  * Prints all values in the stack and queue, starting from the top.

* **pint**
  * Prints the top value of the stack and queue.

* **pop**
  * Removes the top element of the stack and queue.

* **swap**
  * Swaps the top two elements of the stack and queue.

* **add**
  * Adds the top two elements of the stack.
  * The result is stored in the second element from the top and the top element is popped.

* **nop**
  * Does not do anything.

* **sub**
  * Subtracts the top element of the stack and queue from the second element from the top.
  * The result is stored in the second element from the top and the top element is removed.

* **mul**
  * Multiplies the top two elements of the stack and queue.
  * The result is stored in the second element from the top and the top element is removed.

* **div**
  * Divides the second element from the top of the stack and queue by the top element.
  * The result is stored in the second element from the top and the top element is removed.

* **mod**
  * Computes the modulus of the second element from the top of the stack and queue divided by the top element.
  * The result is stored in the second element from the top and the top element is removed.

* **pchar**
  * Prints the character value of the top element of the stack and queue.
  * The integer at the top is treated as an ASCII value.

* **pstr**
  * Prints the string contained in the stack and queue.
  * Prints characters element by element until the stack/queue is empty, a value is `0`, or an error occurs.

* **rotl**
  * Rotates the top element of the stack and queue to the bottom.

* **rotr**
  * Rotates the bottom element of the stack and queue to the top.

* **stack**
  * Switches a queue to stack mode.

* **queue**
  * Switches a stack to queue mode.

When the first non-space character of a line is #, treat this line as a comment (don’t do anything).

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account).

## Examples

The opcode pop removes the top element of the stack.

```
$ cat example.m
push 1
push 2
push 3
pall
pop
pint
$ ./monty example.m
3
2
1
2
```

The opcode add adds the top two elements of the stack.

```
$ cat example.m 
push 1
push 2
push 3
pall
add
pall

$ ./monty example.m 
3
2
1
5
1
```


```
$ cat sub.m 
push 1
push 2
push 10
push 3
sub
pall
$ ./monty sub.m 
7
2
1
```

## Authors

* **Estephania Calvo Carvajal** - [@EstephaniaCalv2](https://github.com/EstephaniaCalvoC)

* **Nicolas Herrera Castro** - [@19Niick](https://github.com/nicolasherrerac)

---

## Flowcharts


![flowchard loop](https://dochub.com/2283-b66vf4/Xv7zYW5Rn2E3AxzR2A9egx/flowchart-loop-jpg)
![flowchard main](https://dochub.com/2283-b66vf4/1XEpyxzwNG6qz0bRQZGd38/flowchart-main-jpg)