# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

An invented long word said to mean a lung disease caused by inhaling very fine ash and sand dust.

## According to its man page, what does `getrusage` do?

Return resource usage statistics for the calling process, which is the sum of resources used by all threads in the process.

## Per that same man page, how many members are in a variable of type `struct rusage`?

16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

These structs are huge and passing it by value would require a lot of memory.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

The main method reads one char in from the file at a time, as long as the char that is read is not EOF. Then it makes sure the char is only alphabetic
or contains apostrophes and skips over words that are either too long or do not fit the requirements.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

We might get a segmentation fault if the string is too long

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

You cannot modify a string literal and the parameters for check and load might sometimes be pointers to string literals, so making it constant
is a good way to make sure the programmer does not try and modify the string literal.
