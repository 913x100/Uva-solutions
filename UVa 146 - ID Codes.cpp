#include <cstdio>
#include <algorithm>
#include <cstring>

char str[55];
int n;

int main()
{
    while(1) {
        scanf("%s", str);
        if(str[0] == '#') break;
        n = strlen(str);
        if(std::next_permutation(str, str+n))
            printf("%s\n", str);
        else
            printf("No Successor\n");
    }
    return 0;
}
