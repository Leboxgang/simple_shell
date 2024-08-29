i# Simple Shell - README

## Overview

**Simple Shell** is a basic UNIX command-line interpreter that mimics the functionality of a simple shell. The project is built in C and adheres to the Betty coding style. It implements basic shell features such as command execution, prompt display, and environment handling.

## Features

- Displays a prompt and waits for the user to input a command.
- Executes commands based on the input.
- Handles errors appropriately, printing relevant messages when commands are not found or fail to execute.
- Supports environment variable handling.
- Includes the built-in commands `exit` to exit the shell and `env` to print the current environment variables.

## Mandatory Tasks

### 0. Betty would be proud
- Write code that passes all Betty checks.

### 1. Simple Shell 0.1
- Display a prompt and wait for the user to type a command.
- Only one-word commands are supported.
- Handle errors and print a message if a command is not found.

### 2. Simple Shell 0.2
- Extend the shell to handle command lines with arguments.

### 3. Simple Shell 0.3
- Handle the `PATH` environment variable to locate commands.

### 4. Simple Shell 0.4
- Implement the built-in command `exit`.

### 5. Simple Shell 1.0
- Implement the built-in command `env` to print the current environment.

## Advanced Tasks

### 6. Simple Shell 0.1.1
- Implement your own version of `getline`.

### 7. Simple Shell 0.2.1
- Do not use `strtok` to parse command lines.

### 8. Simple Shell 0.4.1
- Handle arguments for the `exit` built-in.

### 9. Setenv, Unsetenv
- Implement `setenv` and `unsetenv` built-ins.

### 10. cd
- Implement the built-in command `cd`.

### 11. Command separator `;`
- Handle the `;` command separator.

### 12. Logical operators `&&` and `||`
- Implement logical operators `&&` and `||`.

### 13. Alias
- Implement the `alias` built-in command.

### 14. Variables
- Handle variables such as `$?` and `$$`.

### 15. Comments
- Implement support for comments using `#`.

### 16. File as input
- Support reading commands from a file as input.

## Usage

```bash
./simple_shell
