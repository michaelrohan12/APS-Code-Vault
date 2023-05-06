def find_nth_char(n):
    total_length = 0
    block = 1
    while total_length < n:
        total_length += 26 * block
        block += 1
    pos_within_block = n - (total_length - 26 * (block - 1))
    block_start = 26 * (block - 1)
    block_idx = (pos_within_block - 1) // (block - 1)
    letter_idx = (block_start + block_idx) % 26
    letter = chr(ord('A') + letter_idx)

    return letter


T = int(input())


for t in range(1, T + 1):
    N = int(input())
    nth_char = find_nth_char(N)
    print("Case #{}: {}".format(t, nth_char))
