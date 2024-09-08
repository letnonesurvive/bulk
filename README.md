# Task:

Develop a program for batch processing of commands. Commands are read line by line from the standard input and processed in blocks of N commands. One command is one line, and the specific content of the line does not matter. If the data ends, the block is terminated forcefully. The parameter N is passed as the sole command-line argument in the form of an integer.

The logic for static blocks (in the example where N == 3):
![image](https://github.com/letnonesurvive/bulk/assets/36066335/09cd1f42-4179-487d-91c5-ab67523f9e93)

The block size can be changed dynamically by issuing the commands { at the beginning of the block and } immediately after it. The previous block is forcibly terminated. Such blocks can be nested within each other; however, nested { and } commands are ignored (but not the blocks themselves). If the data ends inside a dynamic block, the entire dynamic block is ignored.

The logic for dynamically sized blocks (in the example where N == 3):

![image](https://github.com/letnonesurvive/bulk/assets/36066335/d0557047-0923-4f64-81db-256c32c7a365)

![image](https://github.com/letnonesurvive/bulk/assets/36066335/605e896a-4852-4239-ba30-207e11a2fcb8)

In addition to outputting to the console, blocks should be saved in separate files with names like bulk1517223860.log, where 1517223860 is the timestamp of when the first command in the block was received. There should be one file per block.

