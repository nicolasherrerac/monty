# Monty Interpreter

This interpreter reads Monty bytecode files of any extension (preferably `.m` although it doesn't matter), and interprets the opcodes contained.
<!--
It was built in the C language and is compliant with `ISO90`, `ISO99`, & `ISO11`.

The interpreter can handle a variety of Monty opcodes, all handled opcodes are listed below.

## Monty Opcodes

* **push**
  * Usage: `push <int>`
  * Pushes an element to the stack.
  * The parameter `<int>` must be an integer.

* **pall**
  * Prints all values in the stack, starting from the top.

* **pint**
  * Prints the top value of the stack.

* **pop**
  * Removes the top element of the stack.

* **swap**
  * Swaps the top two elements of the stack.

* **add**
  * Adds the top two elements of the stack.
  * The result is stored in the second element from the top and the top element is popped.

* **nop**
  * Does not do anything.


## Examples

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
-->

## Authors

* **Estephania Calvo Carvajal** - [@EstephaniaCalv2](https://github.com/EstephaniaCalvoC)

* **Nicolas Herrera Castro** - [@19Niick](https://github.com/nicolasherrerac)