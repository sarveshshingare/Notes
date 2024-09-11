---
id: "custom"
---

@import "note-style.less"

<link href="https://fonts.googleapis.com/css2?family=Handlee&display=swap" rel="stylesheet">

# Lecture 3

## patterns

**Pattern 1**
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0

```cpp
#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 4; i++)
    {

        for (int j = 0; j < 4; j++)
        {
            cout << "0";
        }
        cout << endl;
    }

    return 0;
}
```

**Pattern 2**
111
222
333

```cpp
#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cout << i;
        }
        cout << endl;
    }

    return 0;
}
```

**Pattern 3**
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4

```cpp
#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
```

**pattern 4**
123
456
789

```cpp
#include <iostream>
using namespace std;

int main()
{
    int num = 1;
    for (int i = 1; i <= 3; i++)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << num;
            num += 1;
        }
        cout << endl;
    }

    return 0;
}
```

**pattern 5**
0
0 0
0 0 0
0 0 0 0

```cpp
#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
```

**pattern 6**
1
22
333
4444

```cpp
#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }

    return 0;
}
```

**pattern 7**
1
2 3
4 5 6
7 8 9 10

```cpp
#include <iostream>
using namespace std;

int main()
{
    int num = 1;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num += 1;
        }
        cout << endl;
    }

    return 0;
}
```

**pattern 8**
1
2 3
3 4 5
4 5 6 7

```cpp
#include <iostream>
using namespace std;
int main()
{
    int num = 1;
    for (int i = 1; i <= 4; i++)
    {
        num = i;

        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num += 1;
        }
        cout << endl;
    }

    return 0;
}
```

ALTERNATE LOGIC

```cpp
#include <iostream>
using namespace std;
int main()
{

    for (int i = 1; i <= 4; i++)
    {

        for (int j = i; j < i * 2; j++)
        {
            cout << j << " ";
                }
        cout << endl;
    }

    return 0;
}
```

**pattern 9**
1
2 1
3 2 1
4 3 2 1

```cpp
#include <iostream>
using namespace std;
int main()
{

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i - j + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
```

**pattern 10**
A A A
B B B
C C C

```cpp
#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 4; i++)

    {
        for (int j = 1; j <= 4; j++)
        {
            cout << (char)('A' + i - 1) << " ";
        }
        cout << endl;
    }

    return 0;
}
```

**pattern 11**
A B C
A B C
A B C

```cpp
#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 4; i++)

    {
        for (int j = 1; j <= 4; j++)
        {
            cout << (char)('A' + j - 1) << " ";
        }
        cout << endl;
    }

    return 0;
}
```
