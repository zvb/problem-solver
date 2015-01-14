#include <cstdio>

using namespace std;

struct entry {
    unsigned int val : 30;
    unsigned int next : 17;
};

entry s[100001]; int ptr = 1;
char str[5];

int main() {
    printf("%lu\n", sizeof(entry));
    //entry e = {1000000000, 100000, 100000};
    //printf("%d %d %d\n", e.val, e.next, e.head);
    /*
    int q;
    scanf("%d", &q);
    int x, num, val, head;
    while (q --) {
        scanf("%s ", str);
        if (str[1] == 'U') {
            scanf("%d %d", &x, &num);
            s[ptr].val = num;
            s[ptr].next = s[x].head;
            s[x].head = ptr;
            ptr ++;
        } else {
            scanf("%d", &x);
            head = s[x].head;
            printf("%d\n", s[head].val);
            s[x].head = s[head].next;
        }
    }
    */
    return 0;
}
