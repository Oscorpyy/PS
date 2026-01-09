#!/usr/bin/env python3
import sys
import random

def compute_disorder(a):
    n = len(a)
    if n < 2:
        return 0.0
    mistakes = 0
    total_pairs = n * (n - 1) // 2
    for i in range(n):
        ai = a[i]
        for j in range(i + 1, n):
            if ai > a[j]:
                mistakes += 1
    return mistakes / total_pairs

class Fenwick:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)

    def add(self, i, delta):
        i += 1
        while i <= self.n:
            self.bit[i] += delta
            i += i & -i

    def kth(self, k):
        # plus petit idx tel que prefix_sum(idx) >= k (k >= 1)
        idx = 0
        bitmask = 1 << (self.n.bit_length())
        while bitmask:
            nxt = idx + bitmask
            if nxt <= self.n and self.bit[nxt] < k:
                k -= self.bit[nxt]
                idx = nxt
            bitmask >>= 1
        return idx  # 0-based

def max_inversions(m):
    return m * (m - 1) // 2

def random_inversion_vector(n, inv_target, rng):
    # vector a[i] in [0, n-1-i] with sum == inv_target, chosen randomly among feasible choices
    a = [0] * n
    k = inv_target
    for i in range(n):
        max_here = n - 1 - i
        remaining = n - 1 - i  # number of items left after this position
        max_rest = max_inversions(remaining)

        # choose x so that 0 <= x <= max_here and 0 <= k-x <= max_rest
        min_x = max(0, k - max_rest)
        max_x = min(max_here, k)

        x = rng.randint(min_x, max_x)
        a[i] = x
        k -= x
    return a

def perm_from_inversion_vector(a):
    n = len(a)
    fw = Fenwick(n)
    for i in range(n):
        fw.add(i, 1)

    perm = []
    for i in range(n):
        # a[i] est un rang 0-based parmi les éléments restants
        pos = fw.kth(a[i] + 1)
        perm.append(pos)
        fw.add(pos, -1)
    return perm

def usage():
    print(f"Usage: {sys.argv[0]} <taille:int> <desordre:0..100> [min] [max] [seed]", file=sys.stderr)
    sys.exit(1)

def main():
    if len(sys.argv) < 3:
        usage()

    try:
        n = int(sys.argv[1])
        D = float(sys.argv[2])  # 0..100
    except ValueError:
        usage()

    if n <= 0:
        print("Erreur: taille doit être > 0", file=sys.stderr)
        sys.exit(2)

    if D < 0:
        D = 0.0
    if D > 100:
        D = 100.0

    lo, hi = 0, 9999
    seed = None
    if len(sys.argv) >= 5:
        lo = int(sys.argv[3])
        hi = int(sys.argv[4])
    if len(sys.argv) >= 6:
        seed = int(sys.argv[5])

    if lo > hi:
        lo, hi = hi, lo

    if (hi - lo + 1) < n:
        print("Erreur: intervalle trop petit pour tirer des valeurs uniques", file=sys.stderr)
        sys.exit(2)

    rng = random.Random(seed)

    values = sorted(rng.sample(range(lo, hi + 1), n))

    total_pairs = n * (n - 1) // 2
    if total_pairs == 0:
        out = values
    else:
        target_inv = int(round((D / 100.0) * total_pairs))
        target_inv = max(0, min(target_inv, total_pairs))

        inv_vec = random_inversion_vector(n, target_inv, rng)
        perm = perm_from_inversion_vector(inv_vec)
        out = [values[i] for i in perm]

    # debug (sur stderr): décommente si tu veux vérifier
    # print(f"target={D/100:.6f} real={compute_disorder(out):.6f}", file=sys.stderr)

    # format push_swap friendly: une seule ligne
    sys.stdout.write(" ".join(map(str, out)) + "\n")

if __name__ == "__main__":
    main()