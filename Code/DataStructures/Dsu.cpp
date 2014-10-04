struct Dsu {
    int *id, sz;
    Dsu() {}
    Dsu (int n) {
        id = new int[n];
        for (int i = 0 ; i < n ; i++)
            id[i] = i;
        sz = n;
    }
    int root(int x) {
        while (x != id[x]) {
            id[x] = id[id[x]];
            x = id[x];
        }
        return x;
    }
    void unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y)
            return;
        sz --;
        if (rand() & 1)
            id[x] = y;
        else
            id[y] = x;
    }
};