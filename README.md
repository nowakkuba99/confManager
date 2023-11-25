# confManager
C++ library used to read .conf files and assign values to variables in your app

## Broad idea

Let's say we have some C++ program that depends on some configuration
Etc. we want to display a tree with parameters like:

- Width,
- Character.

Example ```tree.config```:

```python
# Tree configuration file
# Width
width = 3
# Character
character = '&'
```

Output should look like this:

```c
  &
 &&&
&&&&&
```

The same output should be done for such file:

```python
# Tree configuration file
# Width
type = int
width = 3
# Character
type = char
character = '&'
```

## Requirements

- Lines starting with ```#``` are comments and should be skipped,
- Type should be guessed if not specified,
- Error messages should be specified if configuration file is corrupted,
- Library should load variables into key-value (KV) pairs once,
- Then the app should ask for particular variables it wants and if
present it should get it loaded as a proper type.
- At last the loaded information should be destroyed.
- Supported types for loading:

```c++
int, char, std::string, double, float, bool, long 
```

- For numeric assume int as default,
- For floating point assume float as default,
- For text based if 1 character → char else std::string.
